#include <iostream>
#include <string.h>
using namespace std;
int map[21][21];

int main()
{
    int n,lab=1;
    while (scanf("%d",&n)!=EOF) {
        int i,j,k,m,u,v;
        for (i=1; i<=20; i++)
            for (j=1; j<=20; j++)
                map[i][j]=30;
        while (n--) {
            cin >> u;
            map[1][u]=map[u][1]=1;
        }
        for (i=2; i<=19; i++) {
            cin >> n;
            while (n--) {
                cin >> u;
                map[i][u]=map[u][i]=1;
            }
        }
        for (k=1; k<=20; k++)
            for (i=1; i<=20; i++)
                for (j=1; j<=20; j++)
                    if (map[i][j]>map[i][k]+map[k][j])
                        map[i][j]=map[i][k]+map[k][j];
        cin >> m;
        printf("Test Set #%d\n",lab++);
        for (i=1; i<=m; i++) {
            cin >> u >> v;
            printf("%d to %d: %d\n",u,v,map[u][v]);
        }
        cout << '\n';
    }
    return 0;
}
/*
 Description
 
 Risk is a board game in which several opposing players attempt to conquer the world. The gameboard consists of a world map broken up into hypothetical countries. During a player's turn, armies stationed in one country are only allowed to attack only countries with which they share a common border. Upon conquest of that country, the armies may move into the newly conquered country. 
 
 During the course of play, a player often engages in a sequence of conquests with the goal of transferring a large mass of armies from some starting country to a destination country. Typically, one chooses the intervening countries so as to minimize the total number of countries that need to be conquered. Given a description of the gameboard with 20 countries each with between 1 and 19 connections to other countries, your task is to write a function that takes a starting country and a destination country and computes the minimum number of countries that must be conquered to reach the destination. You do not need to output the sequence of countries, just the number of countries to be conquered including the destination. For example, if starting and destination countries are neighbors, then your program should return one. 
 
 The following connection diagram illustrates the first sample input. 
 
 Input
 
 Input to your program will consist of a series of country configuration test sets. Each test set will consist of a board description on lines 1 through 19. The representation avoids listing every national boundary twice by only listing the fact that country I borders country J when I < J. Thus, the Ith line, where I is less than 20, contains an integer X indicating how many "higher-numbered" countries share borders with country I, then X distinct integers J greater than I and not exceeding 20, each describing a boundary between countries I and J. Line 20 of the test set contains a single integer (1 <= N <= 100) indicating the number of country pairs that follow. The next N lines each contain exactly two integers (1 <= A,B <= 20; A!=B) indicating the starting and ending countries for a possible conquest. 
 
 There can be multiple test sets in the input file; your program should continue reading and processing until reaching the end of file. There will be at least one path between any two given countries in every country configuration. 
 Output
 
 For each input set, your program should print the following message "Test Set #T" where T is the number of the test set starting with 1. The next NT lines each will contain the result for the corresponding test in the test set - that is, the minimum number of countries to conquer. The test result line should contain the start country code A the string " to " the destination country code B ; the string ": " and a single integer indicating the minimum number of moves required to traverse from country A to country B in the test set. Following all result lines of each input set, your program should print a single blank line.
 Sample Input
 
 1 3
 2 3 4
 3 4 5 6
 1 6
 1 7
 2 12 13
 1 8
 2 9 10
 1 11
 1 11
 2 12 17
 1 14
 2 14 15
 2 15 16
 1 16
 1 19
 2 18 19
 1 20
 1 20
 5
 1 20
 2 9
 19 5
 18 19
 16 20
 Sample Output
 
 Test Set #1
 1 to 20: 7
 2 to 9: 5
 19 to 5: 6
 18 to 19: 2
 16 to 20: 2
*/