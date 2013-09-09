#include <iostream>
#include <map>
using namespace std; 

int main()
{
    int n;
    map<int, int> word;
    while (cin >> n&&n) {
        word.clear();
        int i,num,x,y,sum=0;
        for (i=0; i<n; i++) {
            cin >> num >> x >> y;
            if (x==1) {
                word[num]++;
                if (word[num]>1)
                    sum+=10;
                if (y==1)
                    sum+=40;
                else
                    sum+=20;
            }
            else
                sum+=10;
        }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 Customer support department in an "Incomprehension Amateurs, Ltd" software company has call center for answering users' questions. Support prices are as follows:
 1.	Answer to a question	10 USD
 2.	Correct answer to a question	20 USD
 3.	Correct answer to a question with explanation	40 USD
 4.	Correct answer to a question which was already correctly answered before	+10 USD for each previous correct answer
 So, for example, if user asks the same question three times, first receives incorrect answer, then correct one, and the third time correct answer with explanation, it will cost him 10 + 20 + (40 + 1 * 10) = 80 USD.
 
 Customers are billed monthly according to call log. Company engineers review the log and for each question determine:
 
 unique number, so the equivalent questions have same numbers,
 whether the answer was correct,
 whether the answer was short or included detailed enough explanation.
 Given that data, your program must calculate the payment amount.
 
 
 Input
 Input file contains number of calls N followed by N triples qi ai xi, where qi is integer question number, ai = 1 if the answer was correct, 0 otherwise, xi = 1 if explanation was given, 0 otherwise. 
 
 Output
 Output file must contain a single number — payment amount. 
 
 Sample Input
 sample input #1
 1
 9834 0 1
 
 sample input #2
 3
 33 1 0
 33 0 0
 33 1 1
 Sample Output
 sample output #1
 10
 
 sample output #2
 80
 Judge Tips
 1 ≤ N ≤ 10000, 1 ≤ qi ≤ 106. 
*/