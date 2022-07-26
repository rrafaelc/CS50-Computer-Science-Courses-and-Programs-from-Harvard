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
    long num = number;

    int multipliedBy2 = 0;
    int notMultipliedBy2 = 0;
    int count = 1;

    do
    {
        if (count % 2 == 0)
        {
            int n = num % 10;

            int multBy2 = n * 2;

            // printf("%i\n", multBy2);

            if (multBy2 > 9)
            {
                int firstNum = multBy2 % 10;
                int secondNum = multBy2 / 10;
                int sum = firstNum + secondNum;

                printf("%i\n", firstNum);
                printf("%i\n", secondNum);
                printf("%i\n", sum);

                multipliedBy2 += sum;

            //     int sum = 0;

            //     do
            //     {
            //         sum += multBy2 % 10;
            //         multBy2 /= 10;
            //     }
            //     while (multBy2 > 0);

            //     multipliedBy2 += multBy2;
            }

            multipliedBy2 += multBy2;

            num /= 10;
        } else
        {
            notMultipliedBy2 = num % 10;
            num /= 10;
        }

        count++;
    }
    while (num > 0);

    printf("\n");
    printf("By 2: %i\n", multipliedBy2);
    printf("Not By 2: %i\n", notMultipliedBy2);




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