#include <cs50.h>
#include <stdio.h>

// AMEX, MASTERCARD, VISA or INVALID

// American Express - 15 digits, starts with 34 or 37
// Mastercard - 16 digits, starts with 51, 52, 53, 54 or 55
// Visa - 13 or 16 digits, starts with 4

long get_card_number();

int main(void)
{
    // Get card number
    long card = get_card_number();
}

long get_card_number() {
    long card;

    // do
    // {
        // Get card number from user
        // do
        // {
            card = get_long("Number: ");
            return card;
        // } while
    // }
}
