#include "helpers.h"

// get last row of image image[height - 1]
// image[0] first row
// image[0][0] first pixel in first row
// image[0][1] second pixel in first row and so on
// image[2][3] pixel in row 2 and column 3

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = 255;
            image[i][j].rgbtGreen = 255;
            image[i][j].rgbtBlue = 255;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
