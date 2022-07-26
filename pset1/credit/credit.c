#include <cs50.h>
#include <stdio.h>

// AMEX, MASTERCARD, VISA or INVALID

// American Express - 15 digits, starts with 34 or 37
// Mastercard - 16 digits, starts with 51, 52, 53, 54 or 55
// Visa - 13 or 16 digits, starts with 4

long get_card_number();
int validate_credit(long number);
int get_total_number(long number);
string get_flag_card(long number);

int main(void)
{
    // Get card number
    long card_number = get_card_number();

    // Get total number from card
    int total_number = get_total_number(card_number);

    // If number is not 13, 15 or 16, for this exercise will be invalid
    if (total_number == 13 || total_number == 15 || total_number == 16)
    {
        // Validate the credit
        int result = validate_credit(card_number);

        // Check if value is 0 and show the card flag name based on number
        if (result == 0)
        {
            string card_name = get_flag_card(card_number);
        }
    } else
    {
        printf("INVALID\n");
    }

}

long get_card_number()
{
    long card;

    do
    {
        // Get card number from user
        card = get_long("Number: ");

    }
    while (card < 0);

    return card;
}

int validate_credit(long number)
{
    // Copy the number to keep intact, for later print the number to user;
    long num = number;

    // Iniate variables for the operations
    int multipliedBy2 = 0;
    int notMultipliedBy2 = 0;

    // Use count to keep track to get a the right number in do while
    int count = 1;

    do
    {
        // Check if the count is even, to get the second-to-last digit
        if (count % 2 == 0)
        {
            // Get the last digit
            int n = num % 10;

            // Multiply by 2
            int multBy2 = n * 2;

            // If the result is higher than 9
            if (multBy2 > 9)
            {
                // The number can't be greater than 18, so i know there will be only 2 numbers to sum
                int firstNum = multBy2 % 10;

                int secondNum = multBy2 / 10;

                // Sum the numbers
                int sum = firstNum + secondNum;

                // Add to the multipliedBy2
                multipliedBy2 += sum;

                // And remove last digit from the num;
                num /= 10;

            } else {
                // If not greater than 9, only sum
                multipliedBy2 += multBy2;

                // And remove last digit again
                num /= 10;
            }

        }
        else
        {
            // Add last digit to the variable
            notMultipliedBy2 += num % 10;

            // Remove last digit
            num /= 10;
        }

        count++;
    }
    // The result will reach 0 eventually dividing by 10
    while (num > 0);

    // Get the final result
    int finalResult = notMultipliedBy2 + multipliedBy2;

    // return the last digit, being 0 or not
    return finalResult % 10;
}

int get_total_number(long number)
    {
        long num = number;
        int count = 0;

        do
        {
            num /= 10;
            ++count;
        }
        while (num != 0);

        return count;
    }

    string get_flag_card(long number) {
        int numb = number;
        int digit;

        while (numb >= 10)
        {
            numb /= 10;
            digit = numb;
        }

        printf("%i\n", digit);

        return "AA";
    }