#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    unsigned int n,flag=1;
    while (cin >> n&&n) {
        getchar();
        int i,j;
        char a[40]={0},b[40]={0};
        for (i=0; i<2*n-1; i++)
        {
            memset(b, 0, sizeof(b));
            gets(b);
            for (j=0; j<40;j++)
                a[j]^=b[j];
        }
        cout << "Scenario #" << flag++ << '\n' << a << '\n';
    }
    return 0;
}
/*
 Problem description
 This time,suddenly,teacher Li wants to find out who have missed interesting DP lesson to have fun.The students who are found out will get strictly punishment.Because,teacher Li wants all the students master the DP algorithm.
 However,Li doesn't want to waste the class time to call over the names of students.So he let the students to write down their names in one paper.To his satisfaction,this time, only one student has not come.
 He can get the name who has not come to class,but,it is troublesome,and,teacher always have many things to think about,so,teacher Li wants you, who is in the ACM team, to pick out the name.
 
 
 Input
 There are several test cases.The first line of each case have one positive integer N.N is the number of the students,and N will not greater than 500,000.
 Then,following N lines,each line contains one name of students who have attended class.The N-1 lines are presented after N lines.These N-1 lines indicates the names of students who have come to class this time,one name in one line.
 The length of student's name is not greater than 30.
 Process to the end of file.
 
 Output
 For each test case, first print a line saying "Scenario #k", where k is the number of the test case.Then output the name of the student who have not come to class.One case per line.Print a blank line after each test case, even after the last one.
 
 Sample Input
 3
 A
 B
 C
 B
 C
 Sample Output
 Scenario #1
 A
*/