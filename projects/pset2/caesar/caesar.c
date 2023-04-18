#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// argc(int) stands for argument count, f.e. ./caesar = 1 argument, ./caesar 69 = 2 arguments, etc.
// argv(string) stands for argument vector, f.e. for ./caesar 69 argv[0] is ./caesar, argv[1] is 69
int main(int argc, string argv[])
{

if(argc==2)
    printf("");
else
    printf("Usage: ./caesar key\n");
    return 1;

string key = argv[1];
// Checking if all values in string are digits
for(int i=0; i<strlen(argv[1]); i++)
{
    if(!isdigit(argv[1][i]))
    {
        printf("Usage: ./caesar\n");
        return 1;
    }
}

printf("Key is %s\n", key);

string plaintext = get_string("What message you want to have encrypted?\n");
// Convert the key to int
int k = atoi(key);

printf("Encrypted message:\n");
// Obtaining encrypted message
for(int i = 0; i < strlen(plaintext); i++)
{
    // Great letters
    if(isupper(plaintext[i]))
    {
        // Printing the character plaintext[i] - 65(ASCII) to make it 0, adding key k to move its position in alphabet, %26 for sure and adding 65 to get letter back
        printf("%c", (((plaintext[i] - 65) +k) %26) +65);
    }
    // Small letters
    else if(islower(plaintext[i]))
    {
        printf("%c", (((plaintext[i] - 97) +k) %26) +97);
    }
    else
        printf("%c", plaintext[i]);
}
printf("\n");

}
