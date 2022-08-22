import os
import json

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd, sum_total_stocks, add_to_history

# export API_KEY=pk_dd2c20ae829e43efa4a328269fed1819
# Created 08/19/22

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    # Get the users transactions from database
    stocks = db.execute("SELECT transactions FROM stocks WHERE user_id = ?", session["user_id"])

    # Get user cash
    row = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    cash = row[0]["cash"]

    if len(stocks) == 1:
        # Convert to list
        stocks = json.loads(stocks[0]["transactions"])

        # Convert to usd
        total_final = usd(cash + sum_total_stocks(stocks))
        cash = usd(cash)

        # Convert each one to usd
        for stock in stocks:
            stock["price"] = usd(stock["price"])
            stock["total"] = usd(stock["total"])

        return render_template("index.html", stocks=stocks, cash=cash, total_final=total_final)

    cash = usd(cash)
    return render_template("index.html", cash=cash, total_final=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)

        elif not request.form.get("shares"):
            return apology("must provide shares", 400)

        if int(request.form.get("shares")) <= 0:
            return apology("shares must be positive", 400)

        stock_API = lookup(request.form.get("symbol"))

        if not stock_API:
            return apology("invalid symbol", 400)

        # Check if has enough cash to buy for the user
        row = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = row[0]["cash"]
        price = stock_API["price"] * int(request.form.get("shares"))

        if cash - price < 0:
            return apology("not enough cash to buy", 400)

        # Check in database if the user already has stock for the user
        stocks = db.execute("SELECT * FROM stocks WHERE user_id = ?", session["user_id"])

        # If not in database, create one
        if not stocks:
            stock = [{
                "symbol": stock_API["symbol"],
                "name": stock_API["name"],
                "shares": int(request.form.get("shares")),
                "price": stock_API["price"],
                "total": stock_API["price"] * int(request.form.get("shares"))
            }]

            stock_current_total = stock_API["price"] * int(request.form.get("shares"))

            # Convert to string
            transactions = json.dumps(stock)

            # Add the json to the database for the user
            db.execute("INSERT INTO stocks (transactions, user_id) VALUES(?, ?)", transactions, int(session["user_id"]))

            # Discount cash from total
            cash -= stock_current_total

            # Update user cash for the user
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

            # Add transactions to history for the user
            add_to_history(stock_API["symbol"], int(request.form.get("shares")), stock_API["price"], session["user_id"])

            # Convert to usd
            total_final = usd(cash + sum_total_stocks(stock))
            cash = usd(cash)

            stock[0]["price"] = usd(stock[0]["price"])
            stock[0]["total"] = usd(stock[0]["total"])

            flash("Bought!")
            return render_template("buy.html", bought=True, stocks=stock, cash=cash, total_final=total_final)

        # If already in database
        elif len(stocks) == 1:

            # Convert to list
            stocks = json.loads(stocks[0]["transactions"])

            # Sort the list
            stocks = sorted(stocks, key=lambda d: d["symbol"])

            # Check if has same symbol, if true then update
            for stock in stocks:
                if stock["symbol"] == stock_API["symbol"]:
                    stock["shares"] += int(request.form.get("shares"))
                    stock["total"] += stock_API["price"] * int(request.form.get("shares"))

                    stock_current_total = stock_API["price"] * int(request.form.get("shares"))

                    # Convert to string
                    transactions = json.dumps(stocks)

                    # Update the json in the database for the user
                    db.execute("UPDATE stocks SET transactions = ? WHERE user_id = ?", transactions, int(session["user_id"]))

                    # Discount cash from total current
                    cash -= stock_current_total

                    # Update user cash for the user
                    db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

                    # Add transactions to history for the user
                    add_to_history(stock_API["symbol"], int(request.form.get("shares")), stock_API["price"], session["user_id"])

                    total_final = usd(cash + sum_total_stocks(stocks))
                    cash = usd(cash)

                    # Convert each one to usd for all stocks after found the same symbol
                    for sto in stocks:
                        sto["price"] = usd(sto["price"])
                        sto["total"] = usd(sto["total"])

                    flash("Bought!")
                    return render_template("buy.html", bought=True, stocks=stocks, cash=cash, total_final=total_final)

            # If not find symbol, append new one
            newStock = {
                "symbol": stock_API["symbol"],
                "name": stock_API["name"],
                "shares": int(request.form.get("shares")),
                "price": stock_API["price"],
                "total": stock_API["price"] * int(request.form.get("shares"))
            }

            stock_current_total = stock_API["price"] * int(request.form.get("shares"))

            # Append the new stock
            stocks.append(newStock)

            # Sort the list
            stocks = sorted(stocks, key=lambda d: d["symbol"])

            # Convert to string
            transactions = json.dumps(stocks)

            # Update the json in the database for the user
            db.execute("UPDATE stocks SET transactions = ? WHERE user_id = ?", transactions, int(session["user_id"]))

            # Discount cash from total current
            cash -= stock_current_total

            # Update user cash for the user
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

            # Add transactions to history for the user
            add_to_history(stock_API["symbol"], int(request.form.get("shares")), stock_API["price"], session["user_id"])

            # Convert to usd
            total_final = usd(cash + sum_total_stocks(stocks))
            cash = usd(cash)

            # Convert each one to usd
            for stock in stocks:
                stock["price"] = usd(stock["price"])
                stock["total"] = usd(stock["total"])

            flash("Bought!")
            return render_template("buy.html", bought=True, stocks=stocks, cash=cash, total_final=total_final)

    # Return from method GET
    return render_template("buy.html", bought=False)


@app.route("/history")
@login_required
def history():
    # Get all transactions from user for the user
    transactions = db.execute("SELECT * FROM transactions WHERE user_id = ?", session["user_id"])

    # Convert the prices to usd
    for transaction in transactions:
        transaction["price"] = usd(transaction["price"])

    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        stock = lookup(request.form.get("symbol"))

        if not stock:
            return apology("invalid symbol", 400)

        # convert to usd
        stock["price"] = usd(stock["price"])
        return render_template("quote.html", stock=stock)

    return render_template("quote.html", stock=None)


@app.route("/register", methods=["GET", "POST"])
def register():
    # Check if user is logged in
    if len(session) > 0:
        return apology("logout first to register", 400)

    """Register user"""
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure password confirmation was submitted
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords don't match", 400)

        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Check if username is already taken
        if len(rows) > 0:
            return apology("username already taken", 403)

        # Hash password
        username = request.form.get("username")
        hashed_password = generate_password_hash(request.form.get("password"))

        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hashed_password)

        # Clear session first
        session.clear()

        # Add user to session
        user = db.execute("SELECT id FROM users WHERE username = ?", username)
        session["user_id"] = user[0]["id"]

        # Redirect user to dashboard
        return redirect("/")

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    symbols = []

    # Get the users transactions from database
    stocks = db.execute("SELECT transactions FROM stocks WHERE user_id = ?", session["user_id"])

    # Check if has stock for get method
    if len(stocks) == 1:
        # Convert to list
        stocks = json.loads(stocks[0]["transactions"])

        # Append the symbols to symbols
        for stock in stocks:
            symbols.append(stock["symbol"])

    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("missing symbol", 400)

        elif not request.form.get("shares"):
            return apology("missing shares", 400)

        if int(request.form.get("shares")) <= 0:
            return apology("shares must be positive", 400)

        stock_API = lookup(request.form.get("symbol"))

        if not stock_API:
            return apology("invalid symbol", 400)

        # Look for same symbols choosed by user
        for stock in stocks:
            if stock["symbol"] == stock_API["symbol"]:
                # Check if can sell
                count = stock["shares"] - int(request.form.get("shares"))

                if count < 0:
                    return apology("too many shares", 400)

                # Check if the shares is equal to 0
                if stock["shares"] - int(request.form.get("shares")) == 0:
                    updatedStock = []

                    for stock in stocks:
                        if stock["symbol"] != stock_API["symbol"]:
                            updatedStock.append(stock)

                    # Convert to string
                    transactions = json.dumps(updatedStock)

                    # Update database for the user
                    db.execute("UPDATE stocks SET transactions = ? WHERE user_id = ?", transactions, session["user_id"])

                    # Get user cash
                    row = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

                    cash = row[0]["cash"]

                    # Add the sell to cash
                    cash += int(request.form.get("shares")) * stock_API["price"]

                    # Update user cash
                    db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

                    # Add to history
                    add_to_history(stock_API["symbol"], -abs(int(request.form.get("shares"))),
                                   stock_API["price"], session["user_id"])

                    # Convert to usd
                    total_final = usd(cash + sum_total_stocks(updatedStock))
                    cash = usd(cash)

                    # Convert each one to usd
                    for stock in updatedStock:
                        stock["price"] = usd(stock["price"])
                        stock["total"] = usd(stock["total"])

                    flash('Sold!')
                    return render_template("sell.html", symbols=symbols, sold=True, stocks=updatedStock, cash=cash, total_final=total_final)

                else:
                    # Find the symbol choosed by user and update the shares and total for the list
                    for stock in stocks:
                        if stock["symbol"] == stock_API["symbol"]:
                            stock["total"] = stock_API["price"] * (stock["shares"] - int(request.form.get("shares")))
                            stock["shares"] -= int(request.form.get("shares"))

                    # Convert to string
                    transactions = json.dumps(stocks)

                    # Update database for the user
                    db.execute("UPDATE stocks SET transactions = ? WHERE user_id = ?", transactions, session["user_id"])

                    # Get user cash
                    row = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

                    cash = row[0]["cash"]

                    # Add the sell to cash
                    cash += int(request.form.get("shares")) * stock_API["price"]

                    # Update user cash
                    db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

                    # Add to history
                    add_to_history(stock_API["symbol"], -abs(int(request.form.get("shares"))),
                                   stock_API["price"], session["user_id"])

                    # Convert to usd
                    total_final = usd(cash + sum_total_stocks(stocks))
                    cash = usd(cash)

                    # Convert each one to usd
                    for stock in stocks:
                        stock["price"] = usd(stock["price"])
                        stock["total"] = usd(stock["total"])

                    flash('Sold!')
                    return render_template("sell.html", symbols=symbols, sold=True, stocks=stocks, cash=cash, total_final=total_final)

    return render_template("sell.html", symbols=symbols, sold=False)
