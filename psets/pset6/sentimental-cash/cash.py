from cs50 import get_float

# Get amount of positive cents
while(True):
    cents = get_float("Change Owed: ")
    if (cents >= 0):
        break

# Multiple the float to 100
cents = int(cents * 100)

# Get quarters coins
quarters = cents // 25
cents -= quarters * 25

# Get dimes coins
dimes = cents // 10
cents -= dimes * 10

# Get nickels coins
nickels = cents // 5
cents -= nickels * 5

# Get pennies coins
pennies = cents // 1

# Sum coins
coins = quarters + dimes + nickels + pennies

# Print coins
print(coins)