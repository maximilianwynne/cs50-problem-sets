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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // iterate through each pixel row
        for (int j = 0; j < width; j++)
        {
            // get into the 2D array, obtain value of each colour
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            // take each pixel and convert to sepia equivalent
            sepiaRed =   .393 * rgbtRed[i][j];
                       + .769 * rgbtGreen[i][j];
                       + .189 * rgbtBlue[i][j];

            sepiaGreen = .349 * rgbtRed[i][j];
                       + .686 * rgbtGreen[i][j];
                       + .168 * rgbtBlue[i][j];

            sepiaBlue =  .272 * rgbtRed[i][j];
                       + .534 * rgbtGreen[i][j];
                       + .131 * rgbtBlue[i][j];
