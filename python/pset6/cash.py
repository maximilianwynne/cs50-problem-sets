x = int(input('Please enter an amount between 0-99:'))

print(x//25, "quarters")
x = x % 25

print(x//10, "dimes")
x = x % 10

print(x//5, "nickles")
x = x % 5

print(x//1, "pennies")
