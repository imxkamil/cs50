import csv

titles = {}

with open('fav.csv', 'r') as file:
    reader = csv.DictReader(file) # Outputs a dict object key:val
    for row in reader:
        title = row["title"].strip().upper() # strip() removes spaces, upper() make everything uppercase
        # titles.update(title, 0)
        if title in titles:
            titles[title] += 1
        else:
            titles[title] = 1 # if we put value, the key is automatically there




for title in (titles):
    if titles[title] > 5:
        print(f"serial {title} liked {titles[title]} times")