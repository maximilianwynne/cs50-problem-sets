#include "helpers.h"

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
            int average = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3);

            // Set all values to average
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i]  [j].rgbtRed = average;
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

// Blurring image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temp array to duplicate the image into the array.
    // You will need the original pixels to calculate the averages (stored in the array), which will be removed from the original image once we start blurring
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
             temp[i][j] = image[i][j];
        }
    }
    // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Initialise values
            // Variable declared to store the sums of red, blue and green values of the surrounding pixels, and a counter of the amount of surrounding pixels
            float sum_red;
            float sum_blue;
            float sum_green;
            // counter for the surrounding pixels
            int counter;

            sum_red = sum_blue = sum_green = counter = 0;
        }
}

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
for (int i = 0; i < height; i++)
{
    // Loop through columns
    for (int j = 0; j < width; j++)
    {
        // initialise ints
        float Gx_red;
        float Gx_blue;
        float Gx_green;
        float Gy_red;
        float Gy_blue;
        float Gy_green;

        Gx_red = Gx_blue = Gx_green = Gy_red = Gy_blue = Gy_green = 0;
    }
}
        // for each pixel, loop vertical and horizontal
        for (int k = -1; k < 2; k++)
        {
            for (int l = -1; 1 < 2; l++)
            {
                // check if pixel is outside rows
                if (i + k < 0 || i + k >= height)
                {
                    continue;
                }
                // otherwise add to sums
                Gx_red += temp[i + k][j + l].rgbtRed * Gx[k + l][l + l];
                Gx_green += temp[i + k][j + l].rgbtGreen * Gx[k + l][l + l];
                Gx_blue += temp[i + k][j + l].rgbtBlue * Gx[k + l][l + l];
                Gy_red += temp[i + k][j + l].rgbtRed * Gx[k + l][l + l];
                Gy_green += temp[i + k][j + l].rgbtGreen * Gx[k + l][l + l];
                Gy_blue += temp[i + k][j + l].rgbtBlue * Gx[k + l][l + l];
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
   }
   return;
}
