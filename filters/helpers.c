#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate through each pixel column
    for (int i = 0; i < height; i++)
    {
        // iterate through each pixel row
        for (int j = 0; j < height; j++)
        {
            // get into the 2D array, obtain value of each colour
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            // calculate the average pixel value for each individual channel and rounded
            int avg = round(((float)red + (float)blue + (float)green)/3);

            // set the calculated average to be the result of each pixel value
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            //new sepia value
           int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
           int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
           int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
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

// Blur image
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
}  
