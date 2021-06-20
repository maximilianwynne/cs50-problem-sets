i = float(input("Enter your credit card number: "))

if i > 16 or i < 13:
    print("INVALID\n")

if i == 13 or i == 16:
    print("VISA\n")

if i == 15:
    print("AMEX\n")

if i == 16:
    print("MASTERCARD\n")
