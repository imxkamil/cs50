import csv

titles = [] # or You can use titles = set()

with open('fav.csv', 'r') as file:
    reader = csv.DictReader(file) # Outputs a dict object key:val
    for row in reader:
        title = row["title"].strip().upper() # strip() removes spaces, upper() make everything uppercase
        if not title in titles: # set structure same as in math avoid duplicates
            titles.append(title) # so instead this part of code we just need titles.add(title)

for title in sorted(titles):
    print(title)