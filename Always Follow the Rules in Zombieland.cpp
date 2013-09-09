#include <iostream>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        char c=getchar();
        int i,m,k;
        char a[55][80]={0};
        for (i=0; i<n; i++)
            gets(a[i]);
        cin >> m;
        for (i=0; i<m; i++) {
            cin >> k;
            if (k>=1&&k<=n)
                printf("Rule %d: %s\n",k,a[k-1]);
            else
                printf("Rule %d: No such rule\n",k);
        }
    }
    return 0;
}
/*
 Problem description
 
 
 Welcome to Zombieland! For the next five hours, your team will battle wits with hordes of the undead. Do you have the cunning, will, and stamina to survive? Follow the rules, and you may live to tell the tale.
 In Zombieland, there are a fundamental set of rules you must follow to stay alive. Rule 8 is “Get a kick&@% partner”, rule 18 is “Limber up”, rule 29 is “The buddy system”, and rule 22 is, “When in doubt, know your way out”.
 If you intend to survive for long in Zombieland, you’ll need to know which rule number goes with which quote. Write a program to display the correct quote given the rule number.
 Have fun during your stay in Zombieland, and remember rule 32, “Enjoy the little things”. 
 
 
 Input
 Input will begin with an integer q, 0 < q ≤ 50, on its own line signifying the number of quotes. On the following lines will be the quotes, one per line. No quote will be greater than 65 characters. The first quote will be rule 1, the second quote rule 2, etc. Following these quotes will be an integer r, 0 < r ≤ 50 on a line of its own signifying the number of rules to look up quotes for, followed by a sequence of r rule numbers, one per line. 
 
 
 Output
 For each rule number, display “Rule”, followed by a single space, then the rule number, then a “:” and a single space followed by the appropriate quote. If a rule number falls outside the range of quotes, display the message “No such rule”, instead of a quote. 
 
 
 Sample Input
 4
 Cardio
 The double tap
 Beware of bathrooms
 Seatbelts
 5
 2
 -10
 5
 1
 4
 Sample Output
 Rule 2: The double tap
 Rule -10: No such rule
 Rule 5: No such rule
 Rule 1: Cardio
 Rule 4: Seatbelts
*/