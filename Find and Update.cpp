#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t,n;
    scanf("%d",&t);
    getchar();
    while (t--) {
        char b,c[10];
        map<int, char> word;
        while (1) {
            scanf("%s",c);
            getchar();
            if (c[0]=='S')
                break;
            else if (c[0]=='F')
            {
                scanf("%d",&n);
                if (!word[n])
                    printf("A");
                else
                    printf("%c",word[n]);
            }
            else if (c[0]=='U')
            {
                scanf("%d %c",&n,&b);
                word[n]=b;
            }
        }
        printf("\n");
    }
    return 0;
}
/*
 Problem description
 Let us write a programme, it will associate integers and capital, the capital that associated with the integer was defined the attribute of the integer.The programme can receive three commands, "UPDATE", "FIND" and "STOP". The format of "UPDATE" is: UPDATE n a(-2^31 <= n < 2^31), when the programme received "UPDATE", it will set the attribute of the integer n to the alpha a; The format of "FIND" is: FIND n(n(-2^31 <= n < 2^31), when the programme received "FIND", it will output the attribute of n; When the programme received "STOP", it will halt.
 
 Input
 There are several test cases.The first line of input is a positive number that represent the number of test cases. Each test case will start with "UPDATE" or "FIND" and end with "STOP". The number of "UPDATE" will not exceed 10000.
 
 Output
 For each data set, there will be exactly one line of output that is the output of "FIND" command.Please do not print any other charactors.
 
 Sample Input
 2
 FIND 65536
 UPDATE 65536 B
 FIND 65536
 STOP
 FIND 1
 UPDATE 2 B
 FIND 1
 STOP
 Sample Output
 AB
 AA
*/