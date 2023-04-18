import csv
import re # regular expressions

counter = 0

with open('fav.csv', 'r') as file:
    reader = csv.DictReader(file) # Outputs a dict object key:val
    for row in reader:
        title = row["title"].strip().upper()
        if re.search("^(OFFICE|THE.OFFICE)$", title): # this dot let us tolerate any character between the and office if someone accidentaly
                                                      # pressed v b n or something instead of spacebar, might be very useful :D
                                                      # ^ is start of matching input, $ is the end, | means or
            counter += 1



print(f"How many people liked The Office? {counter}")