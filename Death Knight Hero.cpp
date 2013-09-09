#include <iostream>
using namespace std;

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    while (n--) {
        char a[1100]={0},flag=0,lab=0;
        scanf("%s",a);
        int i,k=strlen(a);
        for (i=0; i<k; i++) {
            if (a[i]=='C')
                flag=1;
            else if(a[i]=='D') {
                if (flag) {
                    lab=1;
                    break;
                }
            }
            else if (a[i]=='O')
                flag=0;
        }
        if (!lab) {
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}
/*
 Problem description
 
 There once was a champion of WoW 
 Arthasdk the name he was bestowed
 He Death Gripped you to his side 
 His Chains of Ice stopped your stride 
 And Obliterates made you say "OWW!"
 But one day our hero got puzzled
 His Death Grip totally fizzled In his darkest despair
 He could barely hear
 "OMG NOOB u Chains of Iced than u Death Gripped"
 
 Input
 You are given a recording of the abilities our hero used in his battles. The first line of input will contain a single integer n (1 <= n <= 100), the number of battles our hero played.
 Then follow n lines each with a sequence of ki (1 <= ki <= 1000) characters, each of which are either 'C', 'D' or 'O'. These denote the sequence of abilities used by our hero in the i-th battle. 'C' is Chains of Ice, 'D' is Death Grip and 'O' is Obliterate.
 
 Output
 Output the number of battles our hero won, assuming he won each battle where he did not Chains of Ice immediately followed by Death Grip.
 
 Sample Input
 3
 DCOOO
 DODOCD
 COD
 Sample Output
 2
*/