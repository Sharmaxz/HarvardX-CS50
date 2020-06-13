#include "helpers.h"
#include "math.h"
#include "stdlib.h"

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

//Limit of RGB
int limit(int rgb)
{
    if (rgb > 255)
    {
        rgb = 255;
    }
    //Return the limit
    return rgb;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    //Variables with array of float
    float red[2];
    float blue[2];
    float green[2];
    float modifier[2];

    //Row Interator
    for (int i = 0; i < width; i++)
    {
        //Column Interator
        for (int j = 0; j < height; j++)
        {
            //Reset the values
            red[0] = red[1] = 0.0;
            blue[0] = blue[1] = 0.0;
            green[0] = green[1] = 0.0;

            //Row Interator
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }
                //Column Interator
                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    //Modifier logic
                    modifier[0] = (k + 1 * k - k * abs(h));
                    modifier[1] = (h + 1 * h - h * abs(k));

                    //Update the RGB values
                    red[0] += image[j + k][i + h].rgbtRed * modifier[0];
                    green[0] += image[j + k][i + h].rgbtGreen * modifier[0];
                    blue[0] += image[j + k][i + h].rgbtBlue * modifier[0];

                    red[1] += image[j + k][i + h].rgbtRed * modifier[1];
                    green[1] += image[j + k][i + h].rgbtGreen * modifier[1];
                    blue[1] += image[j + k][i + h].rgbtBlue * modifier[1];
                }
            }
            //Set value in the pixel with the limit
            temp[j][i].rgbtRed = limit(round(sqrt(red[0] * red[0] + red[1] * red[1])));
            temp[j][i].rgbtBlue = limit(round(sqrt(blue[0] * blue[0] + blue[1] * blue[1])));
            temp[j][i].rgbtGreen = limit(round(sqrt(green[0] * green[0] + green[1] * green[1])));
        }
    }
    //Set temp in the image
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i] = temp[j][i];
        }
    }
}
