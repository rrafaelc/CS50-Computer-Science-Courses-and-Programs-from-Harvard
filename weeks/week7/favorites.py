import csv

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

title = input("Title: ").strip()

db.execute("SELECT COUNT(*) FROM favorites WHERE title ?", title)