#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// ASCII - 97 a, 122 z
int compute_score(string word);

int main(void)
{
// Get input from both players
string word1 = get_string("Maks:");
string word2 = get_string("Kamil:");



// Score both words
int score1 = compute_score(word1);
int score2 = compute_score(word2);

// TODO print the winner
if(score1 > score2)
    printf("Kamil wygrał :p\n");
else if(score1 < score2)
    printf("Kamil wygrał :p\n");
else
    printf("Remis!\n");

}
// Allows to pause returning by YIELD :D - [coroutine] before calling function
int compute_score(string word)
{
    int score = 0;
    // Compute and return score for string  ?i!=0 instead of i < strlen(word);?
    // Checked for i != 0x0;(hex nul symbol) and it worked i != '\0'
    // Checked one more time and it is not working for 0x0 nor '\0'
    for (int i = 0; i < strlen(word); i++)
    {
        if(word[i] > 65 && word[i] < 90)
        {
            score = score + POINTS[word[i] - 65];
        }
        else if(word[i] > 97 && word[i] < 122)
        {
            score = score + POINTS[word[i] - 97];
        }
    }
    // yield return score; PAUSING EXECUTING CODE :D
    return score;
}


