#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace::std;
char symbol[4][14]={ 
    "`1234567890-=",
    "QWERTYUIOP[]\\",
    "ASDFGHJKL;\'",
    "ZXCVBNM,./"
};

int main()
{
    char a[1010];
    while (gets(a)!=NULL)
    {
        int i,j,k=0;
        for (k=0;k<strlen(a);k++) 
        {
            for(i=0;i<4;i++)
                for(j=0;j<14;j++)
                    if (a[k]==symbol[i][j])
                        a[k]=symbol[i][j-1];
        }
        for (i=0; i<strlen(a); i++)
            cout << a[i];
        cout << '\n';
    }
    return 0;
}
/*#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace::std;
namespace KeyBoard{
	char symbol[4][14]={
        "`1234567890-=",
        "QWERTYUIOP[]\\",
        "ASDFGHJKL;\'",
        "ZXCVBNM,./"
    };
}

int main()
{
    char a[1010];
    while (gets(a)!=NULL)
    {
        int i,j,len;
        for(i=0;i<4;i++)
        {
            len=strlen(KeyBoard::symbol[i]);
            for(j=0;j<len-1;j++)
            {
                a[KeyBoard::symbol[i][j+1]]=KeyBoard::symbol[i][j];
            }
        }
        for(int i=0;a[i];++i)
            cout << a[a[i]];
        cout << '\n';
    }
}*/
/*
 A common typing error is to place your hands on the keyboard one row to the right of the correct position. Then ``Q'' is typed as ``W'' and ``J'' is typed as ``K'' and so on. Your task is to decode a message typed in this manner.
 
 Input
 
 Input consists of several lines of text. Each line may contain digits, spaces, uppercase letters (except ``Q'', ``A'', ``Z''), or punctuation shown above [except back-quote (`)]. Keys labeled with words [Tab, BackSp, Control, etc.] are not represented in the input.
 Output
 
 You are to replace each letter or punctuation symbol by the one immediately to its left on the QWERTY keyboard shown above. Spaces in the input should be echoed in the output.
 Sample Input
 
 O S, GOMR YPFSU/
 Sample Output
 
 I AM FINE TODAY.
*/