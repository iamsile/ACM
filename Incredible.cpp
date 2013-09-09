#include <iostream>
using namespace std;

int main()
{
    double n,m,k;
    while (~scanf("%lf%lf%lf",&n,&m,&k)) {
        if (n==m)
            printf("0.00\n");
        else printf("%.2lf\n",(n-1)*k-(m-1)*k/2);
    }
    return 0;
}
/*
 Problem description
 Zhuge Liang, a person?of?great?wisdom?and?resourcefulness, who is capable of knowing things 500 years ago and predicting things 500 years later. What's incredible! He must could make large amounts of money if he still alive today because he could forecast everything. Now, we want invite him to help us to forecast the result of football matches. The Olympic Games of this year will hold in London, England. Assume that the rule of football in Olympic Games is as same as group stage. That's to say, there are n teams in a group and k teams which have higher scores will be promoted. Each team will play a match against each other teams of that group. For a match, the winner team will get A scores and the loser will get zero scores. Both two teams will get A/2(real number) scores if the result is tie. At last, each team will have a score and we will choose the k-highest teams as promoted teams. Now, can you calculate the least score that can ensure one team for promotion? 
 
 Input
 There are several test cases end with EOF. For each test case, the first line is three integers n ( 0 < n ≤ 50 ), k ( 0 < k ≤ n ) and A ( 0 < A < 10000 ), which are described as above. 
 
 
 Output
 For each the case, just output a real number rounded to two decimal places which means the least score that one team can be promoted. 
 
 
 Sample Input
 4 2 3
 3 1 2
 Sample Output
 7.50
 4.00
*/