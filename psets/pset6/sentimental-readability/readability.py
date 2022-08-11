from cs50 import get_string


def main():
    # Get user input
    text = get_string("Text: ")

    # Store variables for later
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Using variables for better look
    l = letters / words * 100
    s = sentences / words * 100

    # Calculate using formula
    readability = int(round(0.0588 * l - 0.296 * s - 15.8))

    # Use conditional for Grade
    if (readability < 1):
        print("Before Grade 1")

    # If is 16 or higher
    elif (readability >= 16):
        print("Grade 16+")

    # If none, then print the Grade
    else:
        print(f"Grade {readability}")


def count_letters(text):
    return text.count()


int count_words(string text)

    int c_words = 0

    # Loop the array text
    for (int i = 0, n = strlen(text) i < n i ++)

        # Count how much spaces in ASCII, which is 32
        if (text[i] == 32)

            c_words++



    # Add one more to count the final word
    c_words++

    return c_words


int count_sentences(string text)

    int c_sentences = 0

    # Loop the string
    for (int i = 0, n = strlen(text) i < n i++)

        # Check if has . ASCII which is 46
        if (text[i] == 46)

            c_sentences++

        # Check if has ! ASCII which is 33
        else if (text[i] == 33)

            c_sentences++

        # Check if has ? ASCII which is 63
        else if (text[i] == 63)

            c_sentences++



    return c_sentences
