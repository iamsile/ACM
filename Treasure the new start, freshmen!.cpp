#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int k,flag=0;
        float n,lab,sum1=0,sum2=0;
        char name[31];
        cin >> k;
        while (k--) {
            getchar();
            cin >> name >> n >> lab;
            if (lab<60&&lab>=0)
                flag=1;
            sum1+=n*lab;
            sum2+=n;
        }
        if (flag)
            cout << "Sorry!\n";
        else
            printf("%.2f\n",sum1/sum2);
        if (t)
            cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 background:
 A new semester comes , and the HDU also meets its 50th birthday. No matter what's your major, the only thing I want to tell you is:"Treasure the college life and seize the time." Most people thought that the college life should be colorful, less presure.But in actual, the college life is also busy and rough. If you want to master the knowledge learned from the book, a great deal of leisure time should be spend on individual study and practise, especially on the latter one. I think the every one of you should take the learning attitude just as you have in senior school.
 "No pain, No Gain", HDU also has scholarship, who can win it? That's mainly rely on the GPA(grade-point average) of the student had got. Now, I gonna tell you the rule, and your task is to program to caculate the GPA.
 If there are K(K > 0) courses, the i-th course has the credit Ci, your score Si, then the result GPA is
 GPA = (C1 * S1 + C2 * S2 +……+Ci * Si……) / (C1 + C2 + ……+ Ci……) (1 <= i <= K, Ci != 0)
 If there is a 0 <= Si < 60, The GPA is always not existed. 
 
 Input
 The first number N indicate that there are N test cases(N <= 50). In each case, there is a number K (the total courses number), then K lines followed, each line would obey the format: Course-Name (Length <= 30) , Credits(<= 10), Score(<= 100).
 Notice: There is no blank in the Course Name. All the Inputs are legal
 
 Output
 Output the GPA of each case as discribed above, if the GPA is not existed, ouput:"Sorry!", else just output the GPA value which is rounded to the 2 digits after the decimal point. There is a blank line between two test cases. 
 
 Sample Input
 
 2
 3
 Algorithm 3 97
 DataStruct 3 90
 softwareProject 4 85
 2
 Database 4 59
 English 4 81
 
 
 Sample Output
 
 90.10
 
 Sorry!
*/