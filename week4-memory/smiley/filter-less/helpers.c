#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //to conver a pixel to grayscale, the red, green, and blue's value need to be same value.
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int rgbGray = round((image[row][column].rgbtBlue + image[row][column].rgbtGreen + image[row][column].rgbtRed)/3.0);

            image[row][column].rgbtBlue = rgbGray;
            image[row][column].rgbtGreen = rgbGray;
            image[row][column].rgbtRed = rgbGray;

        }
    }
    return;
}

// Convert image to sepia
//use the following algorithm; for each pixel, the sepia color values are calculated based on the original color values.
/*sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
SepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue*/

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
           int sepiaRed = round(.393 * image[row][column].rgbtRed + .769 * image[row][column].rgbtGreen + .189 * image[row][column].rgbtBlue);
           int sepiaGreen = round(.349 * image[row][column].rgbtRed + .686 * image[row][column].rgbtGreen + .168 * image[row][column].rgbtBlue);
           int sepiaBlue = round(.272 * image[row][column].rgbtRed + .534 * image[row][column].rgbtGreen + .131 * image[row][column].rgbtBlue);
           //a color’s value should not be higher than 255
           image[row][column].rgbtRed = fmin(255, sepiaRed);
           image[row][column].rgbtGreen = fmin(255, sepiaGreen);
           image[row][column].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    //any pixels on the left side of the image should end up on the right, and vice versa.
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width / 2.00; column++)
        {
            temp = image[row][column]; //swapping the values of [row] and [column] using the temp variable
            image[row][column] = image[row][width - column - 1];
            image[row][width - column - 1] = temp;
        }
    }
    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            temp[row][column] = image[row][column];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            //have neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = row + x;
                    int currentY = column + y;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue; //if neighbouring pixel is invalid, this loop will continue to run. if valid, skip to next
                    }
                    // have image value

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }
                //calculate average
                temp[row][column].rgbtRed = round(totalRed / counter);
                temp[row][column].rgbtGreen = round(totalGreen / counter);
                temp[row][column].rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    //apply into original image
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column].rgbtRed = temp[row][column].rgbtRed;
            image[row][column].rgbtGreen = temp[row][column].rgbtGreen;
            image[row][column].rgbtBlue = temp[row][column].rgbtBlue;
        }
    }
    return;
}
