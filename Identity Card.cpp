#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--) {
        char a[20]={0};
        int i;
        cin >> a;
        cout << "He/She is from ";
        if (a[0]=='3'&&a[1]=='3')
            cout << "Zhejiang";
        else if (a[0]=='1'&&a[1]=='1')
            cout << "Beijing";
        else if (a[0]=='7'&&a[1]=='1')
            cout << "Taiwan";
        else if (a[0]=='8'&&a[1]=='1')
            cout << "Hong Kong";
        else if (a[0]=='8'&&a[1]=='2')
            cout << "Macao";
        else if (a[0]=='5'&&a[1]=='4')
            cout << "Tibet";
        else if (a[0]=='2'&&a[1]=='1')
            cout << "Liaoning";
        else if (a[0]=='3'&&a[1]=='1')
            cout << "Shanghai";
        cout << ",and his/her birthday is on ";
        for (i=10; i<12; i++)
            cout << a[i];
        cout << ',';
        for (i=12; i<14; i++)
            cout << a[i];
        cout << ',';
        for (i=6; i<10; i++)
            cout << a[i];
        cout << " based on the table.\n";
    }
    return 0;
}
/*
 Problem Description
 Do you own an ID card?You must have a identity card number in your family's Household Register. From the ID card you can get specific personal information of everyone. The number has 18 bits,the first 17 bits contain special specially meanings:the first 6 bits represent the region you come from,then comes the next 8 bits which stand for your birthday.What do other 4 bits represent?You can Baidu or Google it.
 Here is the codes which represent the region you are in.
 
 However,in your card,maybe only 33 appears,0000 is replaced by other numbers.
 Here is Samuel's ID number 331004198910120036 can you tell where he is from?The first 2 numbers tell that he is from Zhengjiang Province,number 19891012 is his birthday date (yy/mm/dd).
 
 
 Input
 Input will contain 2 parts:
 A number n in the first line,n here means there is n test cases. For each of the test cases,there is a string of the ID card number.
 
 
 Output
 Based on the table output where he is from and when is his birthday. The format you can refer to the Sample Output.
 
 
 Sample Input
 1
 330000198910120036
 
 
 Sample Output
 He/She is from Zhejiang,and his/her birthday is on 10,12,1989 based on the table.
*/