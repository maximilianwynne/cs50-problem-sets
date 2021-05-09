#include "helpers.h"
#include <math.h>

// grayscale:
// • take an image and convert it to black and white
// • take average of the red, green and blue values of each pixel and set them to equal average
// • loop through each pixel in the image via nested loop
// • define variables for the blue, green and red components of each pixel's RGBTRIPLE
// • calculate an integer average of these three - use round to get a whole number
// • set each of the blue green and red components to the RGBTRIPLE to the average

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Get RGBTriple values
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            // Calculate average
            int average = round((blue + green + red) / 3.0);

            // Set all values to average
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }
    return;
}

// stops max value at 255 preventing overflow
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    
    int sepiaBlue;
    int sepiaRed;
    int sepiaGreen;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaBlue = limit(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            sepiaGreen = limit(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            sepiaRed = limit(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width / 2; j++)
        {
            // Reflect pixels
            RGBTRIPLE temp = image[i][j];
            // If we simply looped through the entire width and set the value of the current pixel to the equivalent at the other side, by the time we get halfway across the image, half of the pixels would be lost.
            // We need to increment columns by 1 to set the current pixel to reflected pixel on other image's side and then set reflected pixel to temp, i.e. the original pixel
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create temp array to store duplicated image before blurring
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // loop through each pixel and declare variable to store RGB values + count (counter) the amount of pixels around middle pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // initialise values
            float sum_red;
            float sum_blue;
            float sum_green;
            int counter;

            // if height or width outside of 0, then pixel doesn't exist
            sum_red = sum_blue = sum_green = counter = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // check if pixel is outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // check if pixel is outside columns
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // add to each colour's sum and increment the counter when the pixels exist
                    sum_red += temp[i + k][j + l].rgbtRed;
                    sum_blue += temp[i + k][j + l].rgbtBlue;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    counter++;
                }
            }
            // get average for each pixel and round up to then blur image
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
}

#if 0
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Initiliase Sobel arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop through rows
    for (int y = 0; y < height; y++)
    {
        // Loop through columns
        for (int x = 0; x < width; x++)
        {
            // initialise ints
            float Gx_red;
            float Gx_blue;
            float Gx_green;
            float Gy_red;
            float Gy_blue;
            float Gy_green;

            Gx_red = Gx_blue = Gx_green = Gy_red = Gy_blue = Gy_green = 0;

            // for each pixel, loop vertical and horizontal
            for (int y2 = -1; y2 < 2; y2++)
            {
                for (int x2 = -1; x2 < 2; x2++)
                {
                    // check if pixel is outside image
                    if (y + y2 < 0 || y + y2 >= height || x + x2 < 0 || x + x2 >= width)
                    {
                        continue;
                    }
                    // otherwise add to sums
                    Gx_red += temp[y + y2][x + x2].rgbtRed * Gx[y2 + x2][x2 + x2];
                    Gx_green += temp[y + y2][x + x2].rgbtGreen * Gx[y2 + x2][x2 + x2];
                    Gx_blue += temp[y + y2][x + x2].rgbtBlue * Gx[y2 + x2][x2 + x2];
                    Gy_red += temp[y + y2][x + x2].rgbtRed * Gx[y2 + x2][x2 + x2];
                    Gy_green += temp[y + y2][x + x2].rgbtGreen * Gx[y2 + x2][x2 + x2];
                    Gy_blue += temp[y + y2][x + x2].rgbtBlue * Gx[y2 + x2][x2 + x2];
                }
            }

            image[y][x].rgbtRed =
        }
    }



    // the square root of the sum of the squares of the red, green and blue Sobel values can now be calculated to give the final
    // values for the pixel being operated on
    // check to make sure each value is below or at the maximum of 255, before assigning calculated values to the image pixels

    // calculate sobel operator
    int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
    int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
    int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

    // cap at 255
    if (red > 255)
    {
        red = 255;
    }
    if (green > 255)
    {
        green = 255;
    }
    if (blue > 255)
    {
        blue = 255;
    }

    // assign new values to pixels
    image[i][j].rgbtRed = red;
    image[i][j].rgbtGreen = green;
    image[i][j].rgbtBlue = blue;
}
#endif
