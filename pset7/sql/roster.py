import csv
import sys
from CS50 import SQL

db = SQL("sqlite:///students.db")

if len(sys.argv) != 2:
    if sys.argv[1] != "Gryffindor" or sys.argv[1] != "Slytherin" or sys.argv[1] != "Hufflepuff" or sys.argv[1] != "Ravenclaw":
