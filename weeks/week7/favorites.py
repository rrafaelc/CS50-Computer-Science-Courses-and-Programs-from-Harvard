import csv

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

title = input("Title: ").strip()

# rows = db.execute("SELECT COUNT(*) AS counter FROM favorites WHERE title LIKE ?", title)
rows = db.execute("SELECT title FROM favorites WHERE title LIKE ?", title)

# print(rows)
# [{'counter': 4}]
# [{'title': 'The Office'}, {'title': 'The Office'}, {'title': 'The Office'}]

# row = rows[0]

# print(row["counter"])
for row in rows:
    print(row["title"])