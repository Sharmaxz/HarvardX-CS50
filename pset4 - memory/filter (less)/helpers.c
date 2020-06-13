#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int originalRed = pixel.rgbtRed;
            int originalGreen = pixel.rgbtGreen;
            int originalBlue = pixel.rgbtBlue;
            int serpiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int serpiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int serpiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            image[i][j].rgbtRed = serpiaRed > 255 ? 255 : serpiaRed;
            image[i][j].rgbtGreen = serpiaGreen > 255 ? 255 : serpiaGreen;
            image[i][j].rgbtBlue = serpiaBlue > 255 ? 255 : serpiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            int red = image[j][i].rgbtRed;
            int blue = image[j][i].rgbtBlue;
            int green = image[j][i].rgbtGreen;

            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;

            image[j][width - i - 1].rgbtRed = red;
            image[j][width - i - 1].rgbtBlue = blue;
            image[j][width - i - 1].rgbtGreen = green;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_blurred[height][width];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int red, blue, green;
            red = blue = green = 0;
            float pixels_valid = 0;
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int l = -1; l < 2; l++)
                {
                    if (i + l < 0 || i + l > width - 1)
                    {
                        continue;
                    }

                    pixels_valid++;
                    red += image[j + k][i + l].rgbtRed;
                    blue += image[j + k][i + l].rgbtBlue;
                    green += image[j + k][i + l].rgbtGreen;
                }
            }

            image_blurred[j][i].rgbtRed = round(red / pixels_valid);
            image_blurred[j][i].rgbtGreen = round(green / pixels_valid);
            image_blurred[j][i].rgbtBlue = round(blue / pixels_valid);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_blurred[i][j];
        }
    }
}
