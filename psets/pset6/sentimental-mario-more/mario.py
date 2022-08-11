# Import the get int function from cs50
from cs50 import get_int

# Get the input from user in range of 1 to 8
while (True):
    height = get_int("Height: ")
    if(height in range(1, 9)):
        break

for i in range(height):
    # Get the amount of hash needed
    hash = i + 1

    # The spaces is the height - hash
    spaces = height - hash

    # Do a loop for spaces first
    for s in range(spaces):
        print(" ", end="")

    # Do a loop for hash
    for h in range(hash):
        print("#", end="")

    # Print the 2 spaces for gap in current line
    for g in range(2):
        print(" ", end="")

    # Print the hash again for the next pyramid
    for h in range(hash):
        print("#", end="")

    print("")