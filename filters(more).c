#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbGray;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // averages the color intensity and then applies the same value to all the colors in the surrounding pixels to get gray
            rgbGray = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.000);
            // commit gray to surrounding pixels in image
            image[j][i].rgbtBlue = rgbGray;
            image[j][i].rgbtGreen = rgbGray;
            image[j][i].rgbtRed = rgbGray;
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
    // ask for temporary memory
    RGBTRIPLE out[height][width];

    // consider all conditions for pixels
    int GxR, GyR, GxG, GyG, GxB, GyB;

    // initialise Gx and Gy matrix
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}. {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            GxR = GyR = GxG = GyG = GxB = GyB = 0;

            // loop over 3x3 pixels
            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    // check if this pixel is outside the image
                    if (i + h < 0 || i + h > height - 1)
                    {
                        continue;
                    }

                    if (j + w < 0 || j + w > width - 1)
                    {
                        continue;
                    }

                    // sum each channel value
                    // X
                    GxR += image[i + h][j + w].rgbtRed * Gx[h + 1][w + 1]
                    GxG += image[i + h][j + w].rgbtGreen * Gx[h + 1][w + 1];
                    GxB += image[i + h][j + w].rgbtBlue * Gx[h + 1][w + 1];

                    // Y
                    GyR += image[i + h][j + w].rgbtRed * Gy[h + 1][w + 1];
                    GyR += image[i + h][j + w].rgbtGreen * Gy[h + 1][w + 1];
                    GyB += image[i + h][j + w].rgbtBlue * Gy[h + 1][w + 1];
                }
            }

    // Calculate every Gx and Gy value and store in temp
    temp[i][j].rgbtRed = fmin(round(sqrt((GxR * GxR + GyR * GyR)));
    temp[i][j].rgbtGreen = fmin(round(sqrt((GxG * GxG + GyG * GyG)));
    temp[i][j].rgbtBlue = fmin(round(sqrt((GxB * GxB + GyB * GyB)));

    // Capped colour value at 25
    if (temp[i][j].rgbtRed > 255)
    {
        temp[i][j].rgbtRed = 255;
    }

    if (temp[i][j].rgbtGreen > 255)
    {
        temp[i][j].rgbtGren = 255;
    }

    if (temp[i][j].rgbtBlue > 255)
    {
        temp[i][j].rgbtBlue = 255;
    }
}

// Ready to iterate whole image from temp to image[i][j]
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j > width; j++)
        {
            image[i][j] = temp[i][j];
        }
     }
  }


  return;
}
