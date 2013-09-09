#include <iostream>  
using namespace std;  

int main()  

{  
    int i,j,len_a,len_b,num[26] = {0};  
    char a[1001] = {'\0'},b[1001] = {'\0'},  
	ch[27] = "abcdefghijklmnopqrstuvwxyz";  
    while(cin >> a)  
    {  
		cin >> b;
        len_a=strlen(a);  
        len_b=strlen(b);  
		for(i=0;i<len_a;i++)
            for(j=0;j<len_b;j++)  {  
                if(a[i]==b[j])  {  
                    b[j] -= b[j]-32;  
                    num[a[i]-'a']++;  
                    break;  
                }  
            }  
        for(i=0;i<26;i++)  
        {  
            if(num[i]>0) 
            {  
                for(j=0;j<num[i];j++)  
					cout << ch[i]; 
            }  
        }  
        cout << '\n'; 
        memset(a,'\0',sizeof(a));  
        memset(b,'\0',sizeof(b));  		
        memset(num,0,sizeof(num));  
    }  
    return 0;  
}  
/*
 Problem description
 Given two strings of lowercase letters, a and b, print the longest string x of lowercase letters such that there is a permutation of x that is a subsequence of a and there is a permutation of x that is a subsequence of b.
 
 Input
 Input consists of pairs of lines. The first line of a pair contains a and the second contains b. Each string is on a separate line and consists of at most 1,000 lowercase letters. 
 
 Output
 For each subsequent pair of input lines, output a line containing x. If several x satisfy the criteria above, choose the first one in alphabetical order. 
 
 Sample Input
 pretty
 women
 walking
 down
 the
 street
 Sample Output
 e
 nw
 et
 */
