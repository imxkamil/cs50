#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

#define storage_capacity 512 * 50

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if(input_file == NULL){
        printf("Error with opening the file\n");
        return 2;
    }

    // Create copy of memory to work on

    // Open card.raw, set the new array for 512 bytes jpegs, find bybtes starting with FF D8, ending FF D9, then copy them to new file in card.raw, go until 50 reached

    // Store block of 512 bytes in array, unsigned = only positive ones
    unsigned char buffer[512];

    // Track the number of images
    int counter = 0;

    // File pointer for recovered images
    FILE *output_file = NULL;

    // Char filename[8]
    char *filename = malloc(8 * sizeof(char));

    // Read the blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // Check if bytes indicate start of JPEG
        if (buffer[0] == 0xFF & buffer[1] == 0xD8)
        {
            // Create file name by sprintf(allocating printf to a string, and if u wanna use that just call printf %s, name of string)
            // Write the JPEG filenames
            sprintf(filename, "%03i.jpg", counter);

            // Open output_file for writting
            output_file = fopen(filename, "w");
            // Count number of images
            counter++;
        }


        // Check if output has been used for valid input
       if(output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }


    }
    free(filename);
    fclose(output_file);
    fclose(input_file);


    return 0;


}