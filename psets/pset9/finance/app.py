import os
import json

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

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
    """Show portfolio of stocks"""
    return apology("TODO")


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
            return apology("share can't be zero or negative", 400)

        stock = lookup(request.form.get("symbol"))

        if not stock:
            return apology("invalid symbol", 400)

        # Check in database if already has stock
        stocks = db.execute("SELECT * FROM stocks WHERE user_id = ?", session["user_id"])

        # If not in database, create one
        if not stocks:
            stock = [{
                "symbol": request.form.get("symbol"),
                "name": stock["name"],
                "shares": int(request.form.get("shares")),
                "price": stock["price"],
                "total": stock["price"] * int(request.form.get("shares"))
            }]

            # Convert to string
            transactions = json.dumps(stock)

            # Add the json to the database
            db.execute("INSERT INTO stocks (transactions, user_id) VALUES(?, ?)", transactions, int(session["user_id"]))

            # Get cash from user
            row = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

            # Discount cash from total
            cash = row[0]["cash"] - stock[0]["total"]
            total = usd(cash + stock[0]["total"])
            cash = usd(cash)

            # Convert to usd
            stock[0]["price"] = usd(stock[0]["price"])
            stock[0]["total"] = usd(stock[0]["total"])

            flash("Bought!")
            return render_template("buy.html", bought=True, stocks=stock, cash=cash, total=total)

        # If already in database
        else:
            # Convert to list
            stocks = json.loads(stocks[0]["transactions"])

            for stock in stocks:
                # Check if find same symbol, then update
                if stock["symbol"] == request.form.get("symbol"):
                    stock["shares"] += int(request.form.get("shares"))
                    stock["total"] += stock["price"] * int(request.form.get("shares"))

                    # Convert to string
                    transactions = json.dumps(stocks)

                    # Add the json to the database
                    db.execute("UPDATE stocks SET transactions = ? WHERE user_id = ?", transactions, int(session["user_id"]))

                    # Get cash from user
                    row = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

                    # Discount cash from total
                    cash = row[0]["cash"] - stock["total"]
                    total = usd(cash + stock["total"])
                    cash = usd(cash)

                    # Convert to usd
                    stock["price"] = usd(stock["price"])
                    stock["total"] = usd(stock["total"])

                    flash("Bought!")
                    return render_template("buy.html", bought=True, stocks=stocks, cash=cash, total=total)

            # If not find symbol, add one
            stoc = [{
                "symbol": request.form.get("symbol"),
                "name": stock["name"],
                "shares": int(request.form.get("shares")),
                "price": stock["price"],
                "total": stock["price"] * int(request.form.get("shares"))
            }]

            return render_template("buy.html", bought=False)



    # row = db.execute("SELECT * FROM stocks WHERE user_id = ?", session["user_id"])

    # stocks[0].price = usd(stocks[0].price)

    return render_template("buy.html", bought=False)


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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
        return apology("logout first to register", 405)

    """Register user"""
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

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
    """Sell shares of stock"""
    return apology("TODO")
