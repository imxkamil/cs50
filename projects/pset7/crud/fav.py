import csv

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

title = input("Title: ").strip()

# this db.execute returns us a list
rows = db.execute("SELECT COUNT(*) AS counter FROM fav WHERE title LIKE ?", title) # ? in SQL is like %s in C

row = rows[0]

print(row["counter"])
