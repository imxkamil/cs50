#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Easy version of caesar just to show the logic

int main(void){
string s = get_string("plaintext: \n");
int k = get_int("key(number): \n");
printf("ciphertext: \n");
for(int i = 0, n = strlen(s); i < n; i++)
{
    if(isalpha(s[i])){
    printf("%c", (((s[i] - 97)+k)%26)+97);
    }
    else
    printf("%c", s[i]);
}
printf("\n");
}