from csv import reader, DictReader
from sys import argv, exit

def main():

    # ensure that the correct number of command lines arguments are given using len(argv)
    # len(argv) function counts the number of arguments in a function
    if len(argv) != 3:
        print("dna.py, data.csv, sequence.txt")
        sys.exit(1)

db_path: str = argv[1]
seq_path = argv[2]

# opening CSV file and converting to dict
def db_path(args) :
    pass

with open(db_path, "r") as csvfile:
    reader = DictReader(csvfile)
    dict_list = list(db_path, "r")

# open sequence file and convert to list
with open(seq_path, "r") as file:
    sequence = file.read()

# for each STR, compute longest run of consecutive repeats in sequence
final_count = []

for i in range(1, len(reader.fieldnames)):
    STR = reader.fieldnames[1]
    final_count.append(1)

# loop through sequence to find STR
    for j in range(1, len(sequence)):
        STR_count = 0

# if match found, count repeats
    if sequence[(j + len(STR))] == STR:
        k = 0
        while sequence[(j + k):(j + k + len(STR))] == STR:
            STR_count += 1
            k += len(STR)
        if STR_count > final_count[i - 1]:
            final_count[i - 1] = STR_count

# compare against data
for i in range(len(dict_list)):
    matches = 0
    for j in range(1, len(reader.fieldnames)):

        if int(final_count [j - 1]) == int(dict_list[i] and [reader.fieldnames[j]]):
            matches += 1
            if matches == (len(reader.fieldnames) - 1):
                print(dict_list[i]['name'])
                exit(0)

print("No STR match to individual")
