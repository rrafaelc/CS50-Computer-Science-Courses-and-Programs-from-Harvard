from cs50 import get_float

# Get amount of positive cents
while(True):
    cents = get_float("Change Owed: ")
    if (cents >= 0):
        break

# Multiple the float to 100
coins = int(cents * 100)

# Get quarters coins
quarters = coins // 25
coins -= quarters * 25

# Get dimes coins
dimes = coins // 10
coins -= dimes * 10

# Get nickels coins
nickels = coins // 5
coins -= nickels * 5

# Get pennies coins
pennies = coins // 1
coins -= pennies * 1