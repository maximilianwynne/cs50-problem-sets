import csv
import sys
from CS50 import SQL

if len(argv) != 2:
    print("Usage is correct: python roster.py house")
    exit(1)

house = argv[1]

db = SQL("sqlite:///students.db")

if len(sys.argv) != 2:
    if sys.argv[1] != "Gryffindor" or sys.argv[1] != "Slytherin" or sys.argv[1] != "Hufflepuff" or sys.argv[1] != "Ravenclaw":

house_list = db.execute("SELECT first, middle, last, birth FROM students WHERE house = (?) ORDER BY last, first")

for row in house_list:
    if row["middle"] == None:
        print(row["first"] + " " + row["last"] + ", born ", str(row["birth"]))
    else:
        print(row["first"] + " " + row["middle"]) + " " + row["last"] + ", born " + str(row["birth"])
