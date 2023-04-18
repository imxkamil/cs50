import csv

user_film = input("Name Your favourite series").strip().upper()

counter = 0

with open('fav.csv', 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        if row["title"].strip().upper() == title:
            counter += 1

print(counter)