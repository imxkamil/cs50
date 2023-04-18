#include <cs50.h>
#include <stdio.h>



int main(void)
{

int height, rows, columns;

do
{
    height = get_int("Height: ");
}
while(height < 1 || height > 8);

for(rows=0; rows<height; rows++)
{
    for(columns=0; columns<=rows; columns++)
    {
        printf("#");
    }
    printf("\n");
}

}