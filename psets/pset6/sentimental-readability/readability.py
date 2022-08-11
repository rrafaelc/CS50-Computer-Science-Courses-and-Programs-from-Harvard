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
    count = 0

    for t in text:
        if(t.isalpha()):
            count += 1

    return count


def count_words(text):
    return text.count(' ') + 1


def count_sentences(text):
    count = 0

    # Loop the string
    for t in text:
        # Check if has . ASCII which is 46
        if (t == '.'):
            count += 1

        # Check if has ! ASCII which is 33
        elif (t == '!'):
            count += 1

        # Check if has ? ASCII which is 63
        elif (t == '?'):
            count += 1

    return count