#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check the arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file as read mode
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }

    // Create the buffer for 512 bytes
    BYTE buffer[BLOCK_SIZE];

    // Create the conditional for first jpeg
    bool found_first_jpeg = false;

    // Count for use of the name of the output files
    int count = 0;

    // Create in memory for using later
    FILE *output_file;

    // As soon as fread returns 0 (which is effectively false), the loop will end.
    while (fread(buffer, 1, BLOCK_SIZE, raw_file))
    {
        // Check if the header is jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If find the first jpeg, set to true
            if (!found_first_jpeg)
            {
                found_first_jpeg = true;
            }
            // Close the output_file which was opened bellow
            else
            {
                fclose(output_file);
            }

            // Create an array of char with 8 bytes
            char filename[8];

            // Name the filename as 000.jpg and increment the count to be 001.jpg, 002.jpg, ...
            sprintf(filename, "%03i.jpg", count++);

            // Try to open file for write
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                printf("Could not open\n");
                return 1;
            }

            // Write the file
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
        }
        else if (found_first_jpeg)
        {
            // Write the previous file
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
        }
    }

    // Close the files
    fclose(output_file);
    fclose(raw_file);
}