from cs50 import get_int


def main():

    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    # Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    # Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    # Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    # Sum coins
    int coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    printf("%i\n", coins)


def get_cents():
    # Get amount of positive cents
    do

        cents = get_int("Change Owed: ")

    while (cents < 0)

    return cents


def calculate_quarters(cents):

    # Divide the cents by quarter number, and the int return the integer number, not float
    int quarters = cents / 25

    return quarters


def calculate_dimes(cents):

    # Divide the cents by dimes number
    int dimes = cents / 10

    return dimes


def calculate_nickels(cents):

    # Divide the cents by nickels number
    int nickels = cents / 5

    return nickels


def calculate_pennies(cents):

    # Divide the cents by pennies number
    int pennies = cents / 1

    return pennies


main()