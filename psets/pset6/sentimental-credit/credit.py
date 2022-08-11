from cs50 import get_int

# AMEX, MASTERCARD, VISA or INVALID

# American Express - 15 digits, starts with 34 or 37
# Mastercard - 16 digits, starts with 51, 52, 53, 54 or 55
# Visa - 13 or 16 digits, starts with 4


def main():
    # Get card number
    card_number = get_card_number()

    # Get total number from card
    total_number = get_total_number(card_number)

    # If number is not 13, 15 or 16, for this exercise will be invalid
    if (total_number in [13, 15, 16]):
        # Validate the credit
        result = validate_credit(card_number)

        # Check if value is 0 and show the card flag name based on number
        if (result == 0)

            string card_name = get_flag_card(card_number)

            # Print the card name
            printf("%s\n", card_name)

        else

            printf("INVALID\n")


    else

        printf("INVALID\n")




def get_card_number():
    # Get card number from user
    while(True):
        card = get_int("Number: ")
        if(card >= 0):
            break

def validate_credit(number)
    # Iniate variables for the operations
    num = number
    multipliedBy2 = 0
    notMultipliedBy2 = 0

    # Use count to keep track to get a the right number in do while
    count = 1

    # Check if the count is even, to get the second-to-last digit
    while(True):
        if (count % 2 == 0):
            # Get the last digit
            n = num % 10

            # Multiply by 2
            multBy2 = n * 2

            # If the result is higher than 9
            if (multBy2 > 9):
                # The number can't be greater than 18, so i know there will be only 2 numbers to sum
                firstNum = multBy2 % 10
                secondNum = multBy2 / 10

                # Sum the numbers
                sum = firstNum + secondNum

                # Add to the multipliedBy2
                multipliedBy2 += sum

                # And remove last digit from the num
                num /= 10

            else:
                # If not greater than 9, only sum
                multipliedBy2 += multBy2

                # And remove last digit again
                num /= 10

        else:
            # Add last digit to the variable
            notMultipliedBy2 += num % 10

            # Remove last digit
            num /= 10

        count += 1

        # The result will reach 0 eventually dividing by 10
        if (num == 0):
            break

    # Get the final result
    finalResult = notMultipliedBy2 + multipliedBy2

    # return the last digit, being 0 or not
    return finalResult % 10

def get_total_number(number):
    num = number
    count = 0

    while(True):
        num /= 10
        count += 1

        if (num != 0)

    return count


string get_flag_card(long number)


    # Store temporary number
    long firstTwoDigits = number

    # Remove last digit from number till only one digit is left
    while (firstTwoDigits >= 100)

        firstTwoDigits /= 10


    printf("%li\n", firstTwoDigits)

    # Check card name based on first 2 Digits
    # AMEX - starts with 34 or 37
    # MASTERCARD - starts with 51, 52, 53, 54 or 55
    # VISA - starts with 4
    if (firstTwoDigits == 34 || firstTwoDigits == 37)

        return "AMEX"


    if (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55)

        return "MASTERCARD"



    # If don't pass the 2 conditional, than remove one more digit to check if is VISA
    int firstDigit = firstTwoDigits / 10

    if (firstDigit == 4)

        return "VISA"


    return "INVALID"

main()