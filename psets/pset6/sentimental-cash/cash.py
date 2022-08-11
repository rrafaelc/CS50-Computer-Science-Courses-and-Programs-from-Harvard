from cs50 import get_int


def main():

    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)


def get_cents():
    # Get amount of positive cents
    while(True):
        cents = get_int("Change Owed: ")
        if (cents >= 0):
            break

def calculate_quarters(cents):
    # Divide the cents by quarter number, and the int return the integer number, not float
    return cents / 25

def calculate_dimes(cents):
    # Divide the cents by dimes number
    return cents / 10

def calculate_nickels(cents):
    # Divide the cents by nickels number
    return cents / 5

def calculate_pennies(cents):
    # Divide the cents by pennies number
    return cents / 1

main()