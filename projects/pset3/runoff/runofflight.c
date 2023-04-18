#include <cs50.h>
#include <stdio.h>




typedef struct Candidate{
    string name;
    int votes;
    bool eliminated;
}Candidate;




Candidate candidate1 = {"John", 5, true};
Candidate candidate2 = {"David", 3, true};
Candidate candidate3 = {"Doug", 9, true};
int votes[] = {5, 3, 9};

int count(){


for (int i = 1; i < 3; i++) {
    if (votes[0] < votes[i]) {
      votes[0] = votes[i];
    }
  }
  return votes[0];
}

string test(){
    Candidate x[3] = {candidate1, candidate2, candidate3};
    for(int i=0; i<3; i++){
        if(votes[0] == x[i].votes){
            
        }
    }
return x[i].name;
}

int winner(){
    printf("test \n");
    return 0;
}


int main(){
winner();
//printf("Candidates: %s\n", candidate1.name);
/*
candidates[0].name = "John";
candidates[0].votes = 0;
candidates[0].eliminated = false;
candidates[1].name = "Max";
candidates[1].votes = 0;
candidates[1].eliminated = false;
candidates[2].name = "Mama";
candidates[2].votes = 0;
candidates[2].eliminated = false;

for(int i=0; i<3; i++){
    printf("Candidate %i: %s\n", i+1, candidates[i].name);
}
*/
}


