#include <iostream>
#include <string>
using namespace std;

bool test(const string& dig){
    int i=0,j=dig.size()-1;
    for(; j>i ; j--,i++)
        if(dig[i]!=dig[j])
            return false;
    return true;
}
int main(){
    string dig,source,tmp;
    string::iterator it;
    string::reverse_iterator rit;
    int n,i,j,t,s;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> source;
        dig=source;
        for(j=0; j<1000; j++){
            if(test(dig))
                break;
            tmp=dig;
            rit=dig.rbegin();
            it=tmp.begin();
            for(t=0; rit!=dig.rend(); rit++,it++){
                s=t;
                t=(*rit+*it+t-96)/10;
                *rit=(*rit+*it+s-96)%10+48;
            }
            if(t!=0){
                tmp=char(t+48);
                dig=tmp+dig;
            }
        }
        cout << source << ' ';
        if(j<1000)
            cout << j << ' '<< dig << '\n';
        else
            cout << "No palindrome was found after 1,000 iterations\n";
    }
    return 0; 
}
/*
 Problem description
 Consider the decimal number 193. Reverse its digits and add the result to the starting number. The answer is 193 + 391 = 584. Repeat the process, 584 + 485 = 1,069. Continue the process until a palindrome is formed (a number that is the same when read in the forward or reverse directions). In this example, the palindrome is 233332, formed after eight applications of the “reverse and add” rule. All numbers are thought to yield palindromes eventually, although there is no proof of this, and, for some numbers, no palindrome has ever been found. Your task is to determine, for each input number, how many applications of the “reverse and add” rule are necessary to form a palindrome, and to find the palindrome.
 
 Assume that no input number will be larger than 10,000. You can also assume that no palindrome will be larger than 4,668,731,596,684,224,866,951,378,664. If a palindrome has not been formed within 1,000 iterations, abandon the search and print the line of text beginning with the input number being tested, then a space character, then the string “No palindrome was found after 1,000 iterations”.
 
 Input
 A number P on a line by itself giving the number of data sets to follow and, for each data set, a line containing the number N to be tested.
 
 Output
 For each data set, a line containing three space separated integers: the input number, then the number of iterations, then the palindrome.
 
 If a palindrome has not been formed within 1,000 iterations, abandon the search and print the line of text beginning with the input number being tested, then a space character, then the string “No palindrome was found after 1,000 iterations”. 
 
 Sample Input
 5
 193
 21
 111
 462
 1097
 Sample Output
 193 8 233332
 21 1 33
 111 0 111
 462 3 4884
 1097 1 8998
*/