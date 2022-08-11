from cs50 import get_float


# Get amount of positive cents
while(True):
    cents = get_float("Change Owed: ")
    if (cents >= 0):
        break
