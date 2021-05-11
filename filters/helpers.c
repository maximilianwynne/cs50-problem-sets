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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // compute weighted sums for pixels surrounding middle pixel here by detecting edges in x and y directions
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1},
    };

    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1},
    };

    for (int i = 0; i < height; i++)
    {
        long redx = 0, redy = 0;
        long greenx = 0, greeny = 0;
        long bluex = 0, bluey = 0;

        for (int j = 0; j < height; j++)
        {
            // finding a pixel within the image
            for (int h = -1; h < 2; h++)
            {
                // finding a pixel within the image
                for (int k = -1; k < 2; k++)
                {
                    if (i + h < 0 || i + h > width - 1 || j + k < 0 || j + k > height - 1)
                    {
                        continue;
                    }

                    // calculating edges in the x and y directions // try to find a way to make a sum of all the values for all 9 pixels, because right now it keeps resetting
                    redx = image[i + h][j + k].rgbtRed * Gx[h + 1][k + 1];
                    greenx = image[i + h][j + k].rgbtGreen * Gx[h + 1][k + 1];
                    bluex = image[i + h][j + k].rgbtBlue * Gx[h + 1][k + 1];
                    redy = image[i + h][j + k].rgbtRed * Gy[h + 1][k + 1];
                    greeny = image[i + h][j + k].rgbtGreen * Gy[h + 1][k + 1];
                    bluey = image[i + h][j + h].rgbtBlue * Gy[h + 1][k + 1];

                    redx = greenx = bluex = redy = greeny = bluey >= 255.0;

                    int red = round(fmin(255.0, sqrt((redx^2) + (redy^2))));
                    int green = round (fmin(255.0, sqrt((greenx^2) + (greeny^2))));
                    int blue = round (fmin(255.0, sqrt((bluex^2) + (bluey^2))));

                    copy[i][j].rgbtRed = red;
                    copy[i][j].rgbtGreen = green;
                    copy[i][j].rgbtBlue = blue;
                }
            }
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
