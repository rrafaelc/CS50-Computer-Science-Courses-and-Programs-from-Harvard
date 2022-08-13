import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as data:
        reader = csv.DictReader(data)
        for d in reader:
            # for k in d.keys():
            #     # If dict key different from "name", change the numbers to int
            #     if(d[k] != d["name"]):
            #         d[k] = int(d[k])
            database.append(d)

    # print(database)

    # TODO: Read DNA sequence file into a variable
    sequences = ''
    with open(sys.argv[2]) as f:
        # Read the lines, removing the \n
        lines = f.read().splitlines()
        for line in lines:
            sequences += line

    # print(sequences)
    # print(len(sequences))

    # TODO: Find longest match of each STR in DNA sequence
    match_str = []

    # print(database[0]["name"])
    print(len(database))

    # m = longest_match(sequences, 'TATC')

    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
