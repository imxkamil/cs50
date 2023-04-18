#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Comb through each row
    for(int i = 0; i < height; i++){
        // Comb through each column
        for(int j = 0; j < width; j++){
            /* Converts pixels to float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;
            */
        // Converts to float and find the average value
        // int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
        image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Go through each row
    for(int i = 0; i < height; i++){
        // Go through each column
        for(int j = 0; j < width; j++){
            // Convert pixels to float

        /**
            float inputRed = image[i][j].rgbtRed;
            float inputGreen = image[i][j].rgbtGreen;
            float inputBlue = image[i][j].rgbtBlue;
        */
            // Convert pixels to float and applying sepia algorithm - find the updated pixel value
            int sepiaRed = round((image[i][j].rgbtRed * .393) + (image[i][j].rgbtGreen *.769) + (image[i][j].rgbtBlue * .189));
            int sepiaGreen = round((image[i][j].rgbtRed * .349) + (image[i][j].rgbtGreen *.686) + (image[i][j].rgbtBlue * .168));
            int sepiaBlue = round((image[i][j].rgbtRed * .272) + (image[i][j].rgbtGreen *.534) + (image[i][j].rgbtBlue * .131));

            // Update pixel valus if sepiaR/G/B is higher than 255
            /*Question is whether we can somehow write the following expression without both then and else parts

            (integer == 5) ? (THENEXPR) : (ELSEEXPR);
            If you only need the then part you can use &&:

            (integer == 5) && (THENEXPR)
            If you only need the else part use ||:

            (integer == 5) || (ELSEEXPR)*/

            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
            /*
            if(sepiaRed > 255){
                sepiaRed = 255;
            }
            if(sepiaGreen > 255){
                sepiaGreen = 255;
            }
            if(sepiaBlue > 255){
                sepiaBlue = 255;
            }
            */
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
 // Go through each row
    for(int i = 0; i < height; i++){
        // Go through half of columns(if we swap with the rest, no need to go through all columns)
        for(int j = 0; j < width/2; j++){
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j+1)];
            image[i][width - (j+1)] = tmp;
            // ???? Idk if needed but it works If pixels were odd
            if(image[j] == image[width - (j+1)])
            continue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create copy of image
    RGBTRIPLE tmp[height][width];
    // Go through each row
    for(int i = 0; i < height; i++){
        //Go through each column
        for(int j = 0; j < width; j++){
            tmp[i][j] = image[i][j];
        }
 }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            // Get neighbouring pixels
            for(int x = -1; x < 2; x++){
                for(int y = -1; y < 2; y++){
                    int currentX = i + x;
                    int currentY = j + y;

                    // Check if neighbouring pixels are valid
                    if(currentX < 0 || currentX > (height -1) || currentY < 0 || currentY > (width - 1)){
                        continue;
                    }

                    // Get image value
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    counter ++;

                }

                // Calculate average of neighbouring pixels
                tmp[i][j].rgbtRed = round(totalRed / counter);
                tmp[i][j].rgbtGreen = round(totalGreen / counter);
                tmp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    // Copy new pixels to the original image
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }

    return;
}
