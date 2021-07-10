from cs50 import SQL
from csv import reader
from sys import argv

db = SQL("sqlite:///students.db")
    input_file = csv.DictReader(open("characters.csv"))
    reader = csv.DictReader(characters.csv)
    for column in reader
        print(column['name'], column['house'], column['birth'])

# check to see if we have the correct number of command line arguments
if len(argv) < 2:
    print("incorrect number of command line arguments; provide name of CSV file")
    exit()

# open CSV file and read line-by-line
open(argv[1], newline='') as charactersFile("characters.csv"):
    characters = reader(charactersFile)
    for character in characters:
        if character[0] == 'name':
            continue

        # print first, middle (if there is middle) and last names for each student
        studentName = name.first, name.middle, name.last
        studentName = character.split()
        if len(studentName) < 3:
            db.execute("insert into students.db(first, middle, last, house, birth")
            VALUES = name.first(?), name.middle(?), name.last(?), house(?), birth(?)
            name.first[0], name.middle[None], name.last[1], character[1], character[2]

        else:
            db.execute("ineert into students.db9first, middle, last, house, birth")
            name.first[0], name.middle[1], name.last[1], character[1], character[2]

print(row)
