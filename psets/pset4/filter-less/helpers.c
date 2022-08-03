#include "helpers.h"
#include <math.h>
#include <stdio.h>

// get last row of image image[height - 1]
// image[0] first row
// image[0][0] first pixel in first row
// image[0][1] second pixel in first row and so on
// image[2][3] pixel in row 2 and column 3

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop the height
    for (int i = 0; i < height; i++)
    {
        // Loop the width
        for (int j = 0; j < width; j++)
        {
            // Get all 3 rgb colors
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Calculate the average with float numbers first to not lose any information
            float average = (float)(red + green + blue) / 3;

            // Round the float after
            average = round(average);

            // If the average is higher than 255 set to 255
            if (average > 255)
            {
                average = 255;
            }

            // Set for each pixel the result of average
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop the height
    for (int i = 0; i < height; i++)
    {
        // Loop the width
        for (int j = 0; j < width; j++)
        {
            // Get all 3 rgb colors
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepia[3];

            // Calculate the sepiaRed and round
            sepia[0] = round(.393 * red + .769 * green + .189 * blue);

            // Calculate the sepiaGreen and round
            sepia[1] = round(.349 * red + .686 * green + .168 * blue);

            // Calculate the sepiaBlue and round
            sepia[2] = round(.272 * red + .534 * green + .131 * blue);

            // Loop the sepias value
            for (int k = 0; k < 3; k++)
            {
                // If value is higher than 255, set to 255
                if (sepia[k] > 255)
                {
                    sepia[k] = 255;
                }
            }

            // Set for each pixel the result of sepia
            image[i][j].rgbtRed = sepia[0];
            image[i][j].rgbtGreen = sepia[1];
            image[i][j].rgbtBlue = sepia[2];
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop the height
    for (int i = 0; i < height; i++)
    {
        // Loop the width and divide the width by 2
        for (int j = 0; j < width / 2; j++)
        {
            // Temp rgb colors
            int tmpRed = image[i][j].rgbtRed;
            int tmpGreen = image[i][j].rgbtGreen;
            int tmpBlue = image[i][j].rgbtBlue;

            // Swap the colors
            // j = 1
            // 10 - j - 1 = position 9
            // 10 - 1 - 1 = position 9
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            // Put the temp colors
            image[i][width - j - 1].rgbtRed = tmpRed;
            image[i][width - j - 1].rgbtGreen = tmpGreen;
            image[i][width - j - 1].rgbtBlue = tmpBlue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int originalImage[height][width];

    // Loop the height
    for (int i = 0; i < height; i++)
    {
        // Loop the width
        for (int j = 0; j < width; j++)
        {
            // Copy all 3 rgb colors to originalImage
            originalImage[i][j] = image[i][j].rgbtRed;
            originalImage[i][j] = image[i][j].rgbtGreen;
            originalImage[i][j] = image[i][j].rgbtBlue;
        }
    }

    // Loop the height
    for (int row = 0; row < height; row++)
    {
        // Loop the width
        for (int col = 0; col < width; col++)
        {
            int dTL[3], top[3], dTR[3], left[3], right[3], dBL[3], bottom[3], dBR[3];
            // Get the diagonal top left pixels

            if (originalImage[0][-1] < 0)
            {
                printf("Nao\n");
            }
        }
    }

    printf("%i\n", image[-1][-1]);

    return;
}
