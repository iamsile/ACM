#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while(cin >> n&&n)
    {
        int i,m1,m2,a[1005],sum=0;
        char c;
        memset(a,0,sizeof(a));
        sum=0;
        do
        {
            scanf("%d",&m1);
            c=getchar();
            if(c=='-')
            {   scanf("%d",&m2);
                c=getchar();
                if(m1>m2){}
                else if(m2<=n)
                    for(i=m1;i<=m2;i++)
                        a[i]=1;
                else if(m1<=n)
                    for(i=m1;i<=n;i++)
                        a[i]=1;
            }
            else
            {
                if(m1<=n) 
                    a[m1]=1;
            }
        }while(c==',');
        for(i=1;i<=n;i++)
            if(a[i]==1)
                sum++;
        cout << sum << '\n';
    }
    return 0;
}
/*
 
 Problem description
 When you execute a word processor's print command, you are normally prompted to specify the pages you want printed. You might, for example, enter:
 
 10-15,25-28,8-4,13-20,9,8-8
 The expression you enter is a list of print ranges, separated by commas.
 
 Each print range is either a single positive integer, or two positive integers separated by a hyphen. In the latter case we call the first integer low and the second one high. A print range for which low > high is simply ignored. A print range that specifies page numbers exceeding the number of pages is processed so that only the pages available in the document are printed. Pages are numbered starting from 1.
 
 Some of the print ranges may overlap. Pages which are common to two or more print ranges will be printed only once. (In the example given, pages 13, 14 and 15 are common to two print ranges.)
 
 
 
 Input
 The input will contain data for a number of problem instances. For each problem instance there will be two lines of input. The first line will contain a single positive integer: the number of pages in the document. The second line will contain a list of print ranges, as defined by the rules stated above. End of input will be indicated by 0 for the number of pages. The number of pages in any book is at most 1000. The list of print ranges will be not be longer than 1000 characters.
 
 
 
 Output
 For each problem instance, the output will be a single number, displayed at the beginning of a new line. It will be the number of pages printed by the print command.
 
 
 
 Sample Input
 30
 10-15,25-28,8-4,13-20,9,8-8
 19
 10-15,25-28,8-4,13-20,9,8-8
 0
 Sample Output
 17
 12
*/