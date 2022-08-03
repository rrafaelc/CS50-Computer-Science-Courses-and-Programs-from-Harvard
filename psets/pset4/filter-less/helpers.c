#include "helpers.h"
#include <math.h>

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

            // Calculate the average and round
            int average = round((red + green + blue) / 3);

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
        // Loop the width
        for (int j = 0; j < width; j++)
        {
            // Get all 3 rgb colors
            // int reflectedRed = image[i][j].rgbtRed;
            // int reflectedGreen = image[i][j].rgbtGreen;
            // int reflectedBlue = image[i][j].rgbtBlue;

            int tmpRed = image[i][width - j].rgbtRed;
            int tmpGreen = image[i][width - j].rgbtGreen;
            int tmpBlue = image[i][width - j].rgbtBlue;

            image[i][j].rgbtRed =
            image[i][j].rgbtGreen =
            image[i][j].rgbtBlue =
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
