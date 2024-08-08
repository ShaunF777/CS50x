#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        { // Take average of red, green & blue
            // Add red, green & blue values together, then devide by 3 for an average, then round
            // this average
            float av =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // Update pixel values to have the same average grayscale value
            image[i][j].rgbtRed = (int) av;
            image[i][j].rgbtGreen = (int) av;
            image[i][j].rgbtBlue = (int) av;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        { // Compute sepia values
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // Update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{ // Loop over all pixels

    for (int i = 0; i < height; i++)
    {
        int begin = 0;
        int end = width - 1;
        RGBTRIPLE temp;
        while (begin < end)
        { // Swop pixels starting from the furthest ends working to the middle
            temp = image[i][begin];
            image[i][begin] = image[i][end];
            image[i][end] = temp;
            begin++;
            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // Now read pixel colors from copy, and write blurred pixel colors in image
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0) // Top most row
            {
                if (j == 0) // Top left corner = 4px
                {
                    float avRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                         copy[i + 1][j + 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                                        4.0);
                    float avGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                        copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                                        4.0);
                    float avBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                          copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                                         4.0);
                    // Update image pixel with blur values
                    image[i][j].rgbtRed = avRed;
                    image[i][j].rgbtGreen = avGreen;
                    image[i][j].rgbtBlue = avBlue;
                }
                else if (j > 0 && j < width - 1) // Top middle = 6px
                {
                    float avRed = round((copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed +
                                         copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                         copy[i + 1][j + 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                                        6.0);
                    float avGreen = round((copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                                            copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                            copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                                         6.0);
                    float avBlue = round((copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue +
                                          copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                          copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                                         6.0);
                    // Update image pixel with blur values
                    image[i][j].rgbtRed = avRed;
                    image[i][j].rgbtGreen = avGreen;
                    image[i][j].rgbtBlue = avBlue;
                }
                else if (j == width - 1) // Top right corner = 4px
                {
                    float avRed = round((copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed +
                                         copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed) /
                                        4.0);
                    float avGreen = round((copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                                           copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                                          4.0);
                    float avBlue = round((copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue +
                                          copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                                         4.0);
                    // Update image pixel with blur values
                    image[i][j].rgbtRed = avRed;
                    image[i][j].rgbtGreen = avGreen;
                    image[i][j].rgbtBlue = avBlue;
                }
            }
            else if (i > 0 && i < height - 1) // Middle rows
            {
                if (j == 0) // Left most edge = 6px
                {
                    float avRed = round((copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                                         copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                         copy[i + 1][j + 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                                        6.0);
                    float avGreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                                        copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                        copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                                        6.0);
                    float avBlue = round((copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                                          copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                          copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                                         6.0);
                    // Update image pixel with blur values
                    image[i][j].rgbtRed = avRed;
                    image[i][j].rgbtGreen = avGreen;
                    image[i][j].rgbtBlue = avBlue;
                }
                else if (j > 0 && j < width - 1) // Middle ones surrounded by other pixels = 9px
                {
                    float avRed = round((copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                         copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed +
                                         copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed +
                                         copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed +
                                         copy[i + 1][j + 1].rgbtRed) /
                                        9.0);
                    float avGreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                           copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
                                           copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen +
                                           copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                           copy[i + 1][j + 1].rgbtGreen) /
                                          9.0);
                    float avBlue = round((copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                          copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                                          copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue +
                                          copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                          copy[i + 1][j + 1].rgbtBlue) /
                                         9.0);
                    // Update image pixel with blur values
                    image[i][j].rgbtRed = avRed;
                    image[i][j].rgbtGreen = avGreen;
                    image[i][j].rgbtBlue = avBlue;
                }
                else if (j == width - 1) // Right edge = 6px
                {
                    float avRed = round((copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                         copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed +
                                         copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                                        6.0);
                    float avGreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                        copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
                                        copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                                        6.0);
                    float avBlue = round((copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                          copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                                          copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                                         6.0);
                    // Update image pixel with blur values
                    image[i][j].rgbtRed = avRed;
                    image[i][j].rgbtGreen = avGreen;
                    image[i][j].rgbtBlue = avBlue;
                }
            }
            else if (i == height - 1) // Bottom most row of pixels
            {
                if (j == 0) // Bottom left corner = 4px
                {
                    float avRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                         copy[i - 1][j + 1].rgbtRed + copy[i - 1][j].rgbtRed) /
                                        4.0);
                    float avGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                        copy[i - 1][j + 1].rgbtGreen + copy[i - 1][j].rgbtGreen) /
                                        4.0);
                    float avBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                          copy[i - 1][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue) /
                                         4.0);
                    // Update image pixel with blur values
                    image[i][j].rgbtRed = avRed;
                    image[i][j].rgbtGreen = avGreen;
                    image[i][j].rgbtBlue = avBlue;
                }
                else if (j > 0 && j < width - 1) // Bottom mid = 6px
                {
                    float avRed = round((copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                         copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                         copy[i - 1][j + 1].rgbtRed + copy[i - 1][j].rgbtRed) /
                                        6.0);
                    float avGreen = round((copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                        copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                        copy[i - 1][j + 1].rgbtGreen + copy[i - 1][j].rgbtGreen) /
                                        6.0);
                    float avBlue = round((copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                          copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                          copy[i - 1][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue) /
                                         6.0);
                    // Update image pixel with blur values
                    image[i][j].rgbtRed = avRed;
                    image[i][j].rgbtGreen = avGreen;
                    image[i][j].rgbtBlue = avBlue;
                }
                else if (j == width - 1) // Bottom right corner = 4px
                {
                    float avRed = round((copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                         copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed) /
                                        4.0);
                    float avGreen = round((copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                           copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen) /
                                          4.0);
                    float avBlue = round((copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                          copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue) /
                                         4.0);
                    // Update image pixel with blur values
                    image[i][j].rgbtRed = avRed;
                    image[i][j].rgbtGreen = avGreen;
                    image[i][j].rgbtBlue = avBlue;
                }
            }
        }
    }
    return;
}
