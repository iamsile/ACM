#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

char buffer[256];
char names[20][81];
int rank[1000][20];
bool isValid[20];
int votes[20];
int numVoters;
int numCandidates;
int halfVotes;

inline void calculateWinner() {
    bool equal;
    int lowest;
    for(int i = 0; i < 20; ++i)
        isValid[i] = true;
    while(true) {
        int i;
        for(i = 0; i < 20; ++i)
            votes[i] = 0;
        for(i = 0; i < numVoters; ++i) {
            int j = 0;
            while(isValid[rank[i][j]] == false && j < numCandidates)
                ++j;
            votes[rank[i][j]]++;  
        }
        i = 0;
        while(isValid[i] == false && i < numCandidates)
            ++i;
        lowest = i++;
        equal = true;
        for(; i < numCandidates; ++i)
            if(votes[i] != votes[i - 1] && isValid[i] == true) {
                if(votes[i] > halfVotes) {
                    puts(names[i]);
                    return;
                }
                if(equal == true)
                    equal = false;
                if(votes[i] < votes[lowest])
                    lowest = i;   
            }
        if(equal == true) {
            for(i = 0; i < numCandidates; ++i)
                if(isValid[i] == true)
                    puts(names[i]);
            return;   
        }
        else
            for(i = 0; i < numCandidates; ++i)
                if(votes[i] == votes[lowest])
                    isValid[i] = false;    
    }
}

int main () {
    int numTests;
    scanf("%d\n\n", &numTests);
    while(0 < numTests--) {
        scanf("%d\n", &numCandidates);
        int i;
        for(i = 0; i < numCandidates; ++i)
            gets(names[i]); 
        char* cp;
        numVoters = 0;
        gets(buffer);
        while(strlen(buffer) > 1 && numVoters < 1000) {
            for(cp = strtok(buffer, " \n"), i = 0; i < numCandidates; ++i, cp = strtok(NULL, " \n"))
                rank[numVoters][i] = atoi(cp) - 1;
            numVoters++;  
            gets(buffer); 
        }
        halfVotes = numVoters / 2;
        calculateWinner();
        if(numTests > 0)
            printf("\n");
    }
}
/*
 Australian ballots require that voters rank all the candidates in order of choice. Initially only the first choices are counted, and if one candidate receives more than 50% of the vote then that candidate is elected. However, if no candidate receives more than 50%, all candidates tied for the lowest number of votes are eliminated. Ballots ranking these candidates first are recounted in favor of their highest-ranked non-eliminated candidate. This process of eliminating the weakest candidates and counting their ballots in favor of the preferred non-eliminated candidate continues until one candidate receives more than 50% of the vote, or until all remaining candidates are tied.
 
 Input
 
 The input begins with a single positive integer on a line by itself indicating the number of cases following, each as described below. This line is followed by a blank line. There is also a blank line between two consecutive inputs.
 
 The first line of each case is an integer n20 indicating the number of candidates. The next n lines consist of the names of the candidates in order, each up to 80 characters in length and containing any printable characters. Up to 1,000 lines follow, each containing the contents of a ballot. Each ballot contains the numbers from 1 to n in some order. The first number indicates the candidate of first choice; the second number indicates candidate of second choice, and so on.
 
 Output
 
 The output of each test case consists of either a single line containing the name of the winner or several lines containing the names of all candidates who are tied. The output of each two consecutive cases are separated by a blank line.
 
 Sample Input
 
 1
 
 3
 John Doe
 Jane Smith
 Jane Austen
 1 2 3
 2 1 3
 2 3 1
 1 2 3
 3 1 2
 Sample Output
 
 John Doe
*/