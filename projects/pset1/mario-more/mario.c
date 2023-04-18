#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, rows, columns, spaces, space;

do
{
    height = get_int("Enter the height from range 1 to 8: ");
}
while(height < 1 || height > 8);
// creates a new rows
for(rows=0; rows<height; rows++)
{
    // gives us spaces to make reverse piramid
    for(spaces=0; spaces < height - rows - 1; spaces++)
    {
        printf(" ");
    }
    // gives us # to make piramid look like a piramid
    for(columns=0; columns<=rows; columns++)
    {
        printf("#");
    }
    //gives us ONE SPACE
    if(1 == 1)
    {
        printf("  ");
    }
    // gives us a $ to build normal piramid
    for(columns=0; columns<=rows; columns++)
    {
        printf("#");
    }
        // gives us spaces to make reverse piramid
    for(space=0; space < height - rows - 1; space++)
    {
        printf(" ");
    }



    printf("\n");
}
}