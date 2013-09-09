#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        char a[17][5],b[17][5];
        int i,j,c[17],d[17];
        for (i=0; i<16; i++)
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        for (i=0; i<16; i++) {
            if (c[i]>d[i]) {
                for (j=0; j<16; j++) 
                {
                    if (strcmp(b[i], a[j])==0)
                        a[j][0]='#';
                    if (strcmp(b[i], b[j])==0&&i!=j)
                        b[j][0]='#';
                    
                }
                b[i][0]='#';
            }
            else {
                for (j=0; j<16; j++) {
                    if (strcmp(a[i], b[j])==0)
                        b[j][0]='#';
                    if (strcmp(a[i], a[j])==0&&i!=j)
                        a[j][0]='#';
                }
                a[i][0]='#';
            }
        }
        for (i=0; i<16; i++)
            if (a[i][0]!='#') {
                cout << a[i] << '\n';
                break;
            }
    }
    return 0;
}
/*
 Problem description
 The teams have nished the group stage of the FIFA World Cup and the teams that are in the round of the last sixteen are known. My boss has all of the games analyzed and bet on the whole rest of the tournament { writing the outcome of each match on a single sheet of paper. It was my job to bring his bets to the next betting oce and set 1 000$. Being nervous with so much cash in my pockets I fell over (I am a bit clumsy) and the bets got shued. So I don't know if a bet corresponds to the nal match or the semi-nal or something else.
 I do not want to disappoint my boss, so I decided to place only one bet on the winner of the tour- nament. Everything I know is that in each round the teams that win (a team wins if it shoots more goals than the opposing team) are in the next round, the other teams are eliminated from the tournament. This is not true for the semi-nals where the losers also play for the third place. So we have in total 16 matches.
 Can you please tell me which team will win the World Cup based on the bets of my boss?
 
 Input
 The rst line of the input is the number of test cases c (1 <= c <= 100). Each test case consists of 16 lines describing the matches in random order. A match description looks as follows: t1 t2 g1 g2. t1 and t2 are the names of teams (abbreviated as exactly three uppercase letters), g1 and g2 (0 <= g1, g2 <= 10, g1 != g2) are the goals of the two teams.
 
 Output
 For each test case, print one line containing the team that will win the FIFA World Cup (based on the analysis of my boss which is always correct!).
 
 Sample Input
 1
 ITA URU 2 0
 ITA IRE 1 0
 ITA ARG 3 4
 YUG ARG 2 3
 GER CZE 1 0
 ENG GER 3 4
 ITA ENG 2 1
 CAM COL 2 1
 ENG CAM 3 2
 ENG BEL 1 0
 GER ARG 1 0
 CZE CRC 4 1
 NET GER 1 2
 BRZ ARG 0 1
 SPA YUG 1 2
 ROM IRE 4 5
 Sample Output
 GER
*/