from flask import Flask, render_template, request

app = Flask(__name__)

# Live reload
app.run(debug=True)

@app.route("/")
def index():
  return render_template("index.html")