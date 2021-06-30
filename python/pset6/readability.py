from cs50 import get_string

# counting letters
# Prompt user for a string of text

text = get_string("Please enter your text: ")

# Initialise 3 different counters to 0 - letters, words, and sentences

n_words = n_sent = n_letters = i = 0

# Iterate through each individual letter using len()

length = len(text)

while i < length:

    # letters? base unit of text input. find them using isalpha() - returns true if all characters are alphabet letters
    if text[i].isalpha():
        n_letters += 1

    # iteration: count no. of letters, words, and sentences
    # counting words
    # two parts: first word? first word found where i = 0 and [i + 1] when immediately after there is NOT a space
    # second to last word: count where there is a letter immediately after a space -> text[i] == "" and text[i + 1] != "".
    # Search must stop after last word, so i!=length
    # NO WORDS YET / NEXT WORD IS NOT A SPACE or SEARCH FOR NEW WORDS MUST STOP AFTER LAST WORD and SPACE AFTER LAST WORD
    if (i == 0 and text[i] != " ") or (i != length and text[i] == " " and text[i + 1] != " "):
        n_words += 1

    # counting letters
    
    if text[i] == "." or text[i] == "?" or text[i] == "!":
        n_sent += 1
    i += 1

# using the given formula

L = (n_letters / n_words) * 100
S = (n_sent / n_words) * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

# print

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
