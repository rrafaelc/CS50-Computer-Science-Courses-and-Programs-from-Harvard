# Import the get int function from cs50
from cs50 import get_int

# Get the input from user in range of 1 to 8
while (True):
    height = get_int("Height: ")
    if(height in range(1, 9)):
        break

# for i in range(height):
    # for j in range(height):

