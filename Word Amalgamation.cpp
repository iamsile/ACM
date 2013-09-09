#include<iostream>  
#include <algorithm>  
using namespace std;  
char a[110][20],str[20],temp[50];  

int cmp(const void *k,const void *l)  
{  
	return(strcmp((char*)k,(char*)l));  
}  

int main()  
{  
    int i=0,j;  
    while(1)  
    {  
        cin>>a[i];  
        if(a[i][0]=='X')  
            break;  
        else  
            i++;  
    }  
    qsort(a,i,sizeof(a[0]),cmp);  
    while(1)  
    {  
        cin>>str;  
        if(str[0]=='X')  
            break;  
        sort(str,str+strlen(str));  
        int lab=0;  
        for(j=0;j<i;j++)  
        {  
            strcpy(temp,a[j]);  
            sort(temp,temp+strlen(temp));  
            if(!strcmp(str,temp))  
            {  
                lab=1;  
                cout<<a[j]<<endl;  
            }  
        }  
        if(lab==0)  
            cout<<"NOT A VALID WORD"<<endl;  
        cout<<"******"<<endl;  
    }  
    return 0;  
} 
/*
 Problem description
 
 In millions of newspapers across the United States there is a word game called Jumble. The object of this game is to solve a riddle, but in order to find the letters that appear in the answer it is necessary to unscramble four words. Your task is to write a program that can unscramble words.
 
 Input
 
 The input file contains four parts: 1) a dictionary, which consists of at least one and at most 100 words, one per line; 2) a line containing XXXXXX, which signals the end of the dictionary; 3) one or more scrambled 'words' that you must unscramble, each on a line by itself; and 4) another line containing XXXXXX, which signals the end of the file. All words, including both dictionary words and scrambled words, consist only of lowercase English letters and will be at least one and at most six characters long. (Note that the sentinel XXXXXX contains uppercase X's.) The dictionary is not necessarily in sorted order, but each word in the dictionary is unique. 
 
 Output
 
 For each scrambled word in the input, output an alphabetical list of all dictionary words that can be formed by rearranging the letters in the scrambled word. Each word in this list must appear on a line by itself. If the list is empty (because no dictionary words can be formed), output the line "NOT A VALID WORD" instead. In either case, output a line containing six asterisks to signal the end of the list. 
 
 Sample Input
 tarp
 given
 score
 refund
 only
 trap
 work
 earn
 course
 pepper
 part
 XXXXXX
 resco
 nfudre
 aptr
 sett
 oresuc
 XXXXXX
 Sample Output
 score
 ******
 refund
 ******
 part
 tarp
 trap
 ******
 NOT A VALID WORD
 ******
 course
 ******
*/