#include <cs50.h>
#include <stdio.h>

// AMEX, MASTERCARD, VISA or INVALID

// American Express - 15 digits, starts with 34 or 37
// Mastercard - 16 digits, starts with 51, 52, 53, 54 or 55
// Visa - 13 or 16 digits, starts with 4

long get_card_number();
void validate_credit(long number);
int get_total_number(long number);

int main(void)
{
    // Get card number
    long card = get_card_number();

    // Validate the credit, and print to the user
    validate_credit(card);
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

void validate_credit(long number)
{
    int total_number = get_total_number(number);

    for (int i = 0; i < total_number; i++)
    {

        printf("%li", number % result);
    }

    printf("\n");
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