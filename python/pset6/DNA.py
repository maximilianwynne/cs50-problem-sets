import reader and DictReader
import argv and exit from sys
import csv

def main():

    # ensure that the correct number of command lines arguments are given using len(argv)
    # len(argv) function counts the number of arguments in a function
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    db_path = argv[1]
    seq_path = argv[2]

# opening CSV file and converting to dict
with open(db_path, "r") as csvfile:
    for reader in csv.DictReader(csvfile)
    dict_list = list(reader, "r")

# open sequence file and convert to list
with open(seq_path, "r") as file:
    sequence = file.read()

# for each STR, compute longest run of consecutive repeats in sq
max_counts = []

for i in range(1, len(reader.fieldnames)):
    STR = reader.fieldnames[1]
    final_count.append(0)

# loop through sequence to find STR
