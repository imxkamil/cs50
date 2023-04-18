import csv


titles = {}

with open('fav.csv', 'r') as file:
    reader = csv.DictReader(file) # Outputs a dict object key:val
    for row in reader:
        title = row["title"].strip().upper() # strip() removes spaces, upper() make everything uppercase
        if not title in titles:
            titles[title] = 0 # initialize value and this dir key:val format
        titles[title] += 1 # else increasing value per 1 each


# def get_value(title):              \    it is same functionality
    # return titles[title]           /    as lambda title: titles[title]



                            # lambda is just a name of function with easy funtionality input: output whem we dont want to name it and reuse it again
for title in sorted(titles, key=lambda title: titles[title], reverse=True): # key=get_value
    if titles[title] > 5:
        print(f"serial {title} liked {titles[title]} times")