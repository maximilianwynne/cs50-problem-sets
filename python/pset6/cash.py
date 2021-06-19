def get_change():
    a = 0
    while a < 25 or a > 1:
        a = int(input("Change: "))
    return a

while True:
  change float("How much change is owned: ");
  if fail_condition:
    break

dollar_amount = float(input("Enter dollar amount : "))
cents = float(dollar_amount * 100);
print("$",dollar_amount," = ¢",cents)

amount = amount - quarters * 25
dimes = amount // 10
amount = amount - dimes * 10
nickels = amount // 5
pennies = amount - nickels * 5
