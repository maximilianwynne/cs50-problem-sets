#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // iterate through each pixel row
        for (int j = 0; j < height; j++)
        {
            // get into the 2D array, obtain value of each colour
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            // calculate the average pixel value for each individual channel, rounded (how to calculate average and round a result)
            int avg = round(((float)red + (float)blue + (float)green)/3);

            // set the calculated average to be the result of each pixel value
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avg;
            }
    }
    return;
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
            // We need to increment columns by 1 to set the current pixel to reflected pixel on other image's side
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

// CORNERS
    // corner pixel on bottom right
    if (i >= 0 && j >= 0)
    {
        sum_red += temp[i][j - 1].rgbtRed;
        sum_green += temp[i][j - 1].rgbtGreen;
        sum_blue += temp[i][j - 1].rgbtBlue;
        counter++;
    }

    //corner pixel on bottom left
    if (i >= 0 && j - 1 >= 0)
    {
        sum_red += temp[i][j].rgbtRed;
        sum_green += temp[i][j].rgbtGreen;
        sum_blue += temp[i][j].rgbtBlue;
        counter++;
    }

    //corner pixel on top left
    if (i - 1 >= 0 && j >= 0)
    {
        sum_red += temp[i - 1][j].rgbtRed;
        sum_green += temp[i - 1][j].rgbtGreen;
        sum_blue += temp[i - 1][j].rgbtBlue;
        counter++;
    }

    //corner pixel on top right
    if (i - 1 >= 0 && j - 1 >= 0)
    {
        sum_red += temp[i - 1][j - 1].rgbtRed;
        sum_green += temp[i - 1][j - 1].rgbtGreen;
        sum_blue += temp[i - 1][j - 1].rgbtBlue;
        counter++;
    }

// FOUR EDGES
    // top left edges
    if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
    {
        sum_red += temp[i + 1][j].rgbtRed;
        sum_green += temp[i + 1][j].rgbtGreen;
        sum_blue += temp[i + 1][j].rgbtBlue;
        counter++;
    }

    // top right edges
    if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j - 1 >= 0))
    {
        sum_red += temp[i + 1][j - 1].rgbtRed;
        sum_green += temp[i + 1][j - 1].rgbtGreen;
        sum_blue += temp[i + 1][j - 1].rgbtBlue;
        counter++;
    }

    // top edges
    if ((i - 1 >= 0 && j >= 0) && (i - 1 < height && j + 1 >= 0))
    {
        sum_red += temp[i - 1][j + 1].rgbtRed;
        sum_green += temp[i - 1][j + 1].rgbtGreen;
        sum_blue += temp[i - 1][j + 1].rgbtBlue;
        counter++;
    }

    // bottom edges
    if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j + 1 >= 0))
    {
        sum_red += temp[i + 1][j + 1].rgbtRed;
        sum_green += temp[i + 1][j + 1].rgbtGreen;
        sum_blue += temp[i + 1][j + 1].rgbtBlue;
        counter++;
    }

// MIDDLE PIXELS
    // middle pixels
    if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
    {
        sum_red += temp[i + 1][j + 1].rgbtRed;
        sum_green += temp[i + 1][j + 1].rgbtGreen;
        sum_blue += temp[i + 1][j + 1].rgbtBlue;
        counter++;
    }

    // find the average value - sum of the value (which is the sum of the colour / number of that value)
    image[i][j].rgbtRed = red(sum_red / counter);
    image[i][j].rgbtBlue = blue(sum_blue / counter);
    image[i][j].rgbtGreen = green(sum_green / counter);
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE out[height][width];

// Making image copy
    for (int r = 0; i < height; r++)
    {
        for (int c = 0; j < width; c++)
    }
    // Calculate Gx
    int GxRed = 0, GxGreen = 0, GxBlue = 0;
    if (c > 0)

    {
        GxRed -= 2 * image[r][c - 1].rgbtRed;
        GxGreen -= 2 *image[r][c - 1].rgbtGreen;
        GxBlue -= 2* image[r][c - 1].rgbtBlue;
        if (r < 0)
    }

    {
        GxRed -= image[r - 1][c - 1].rgbtRed;
        GxGreen -= image[r - 1][c - 1].rgbtGreen;
        GxBlue -= image[r - 1][c - 1].rgbtBlue;
    }
        if (r < height - 1)
    {
        GxRed += image[r + 1][c + 1].rgbtRed;
        GxGreen += image[r + 1][c + 1].rgbtGreen;
        GxBlue += image[r + 1][c + 1].rgbtBlue;
    }


    // calculate Gy
    int GyRed = 0, GyGreen = 0, GyBlue = 0;
    if (r > 0)
    {
        GyRed -= 2 * image[r - 1][c].rgbtRed;
        GyGreen -= 2 * image[r - 1][c].rgbtGreen;
        GyBlue -= 2 * image[r - 1][c].rgbtBlue;
        if (c > 0)
    {
        GyRed -= image[r - 1][c - 1].rgbtRed;
        GyGreen -= image[r - 1][c - 1].rgbtGreen;
        GyBlue -= image[r - 1][c - 1].rgbtBlue;
    }
    if (c < width - 1)
    {
        GyRed -= image[r - 1[c + 1].rgbtRed;
        GyGreen -= image[r - 1][c + 1].rgbtGreen;
        GyBlue -= image[r - 1][c + 1].rgbtBlue;
    }

    {
        copy[r][c].rgbtRed = round(sqrt((float)(GxRed * GxRed) + (GyRed * GyRed)));
        copy[r][c].rgbtGreen = round(sqrt((float)(GxGreen * GyGreen) + (GyGreen * GyGreen)));
        copy[r][c].rgbtBlue = round(sqrt((float)(GxBlue * GxBlue) + (GyBlue * GyBlue)));
    }

    {
        for (int r = 0; r < height; r++)
    }

    {
        for (int c = 0; c < width; c++)
    }

    {
        image[r][c].rgbtRed = copy[r][c].rgbtRed;
        image[r][c].rgbtGreen = copy[r][c].rgbtGreen;
        image[r][c].rgbtBlue = copy[r][c].rgbtBlue;
    }
    return;
}
