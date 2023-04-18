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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    // Apply the edge detection algorithm
    int Gx[3][3]={
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3]={
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){

            int rowCoords[] = {row-1, row, row+1};
            int colCoords[] = {col-1, col, col+1};
            float Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            float Gy_red = 0, Gy_green = 0, Gy_blue = 0;

            for(int r = 0; r < 3; r++){
                for(int c = 0; c < 3; c++){
                    int count = 0;
                    int curRow = rowCoords[r];
                    int curCol = colCoords[c];

                    if(curRow >= 0 && curRow < height && curCol >= 0 && curCol < width){
                        RGBTRIPLE pixel = image[curRow][curCol];

                        Gx_red += Gx[r][c] * pixel.rgbtRed;
                        Gx_green += Gx[r][c] * pixel.rgbtGreen;
                        Gx_blue += Gx[r][c] * pixel.rgbtBlue;

                        Gy_red += Gy[r][c] * pixel.rgbtRed;
                        Gy_green += Gy[r][c] * pixel.rgbtGreen;
                        Gy_blue += Gy[r][c] * pixel.rgbtBlue;

                    }
                }
            }
            // Now apply the sqrt function to Gx and Gy
            int finalRed = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int finalGreen = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int finalBlue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

                            // Calculate average of neighbouring pixels
            tmp[row][col].rgbtRed = finalRed > 255 ? 255 : finalRed;
            tmp[row][col].rgbtGreen = finalGreen > 255 ? 255 : finalGreen;
            tmp[row][col].rgbtBlue = finalBlue > 255 ? 255 : finalBlue;

        }
    }

    // Copy to final image
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j] = tmp[i][j];
        }
    }
    return;
}
