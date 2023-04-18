import csv
import random


serial_names = ["How I met Your mother?", "Family Guy", "Brickleberry", "Paradise PD", "Love Island", "Hotel Paradise", "What If", "The End of The Fucking World", "Test1"]
serial_category = ["Action", "Comedy", "Drama", "Fantasy", "Romance", "Sci-Fi", "Sports", "Thriller"]


with open('favourites.csv', 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    writer.writerows(rows)