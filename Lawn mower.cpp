#include <iostream>
using namespace std;

bool judge(int n,int max,double w)
{
    double d[10001];
    int i;
    for (i=0; i<n; i++)
        cin >> d[i];
    sort(d, d+n);
    bool flag=(d[0]<=w/2)&&((max-d[n-1])<=w/2);
    for (i=0; i<n-1&&flag; i++)
        if (d[i+1]-d[i]>w)
            flag=false;
    return flag;
}

int main()
{
    int n,m;
    double w;
    while (cin >> n >> m >> w) {
        if (!n&&!m&&w==0.0)
            break;
        bool a=judge(n,75,w),b=judge(m, 100, w);
        if (a&&b)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}//模仿标程写的，惭愧
/*
 Problem description
 The International Collegiate Soccer1 Competition (ICSC) is famous for its well-kept rectangular stadiums. The grass playing fields in ICSC stadiums are always 100 meters long, and 75 meters wide. The grass is mowed every week with special lawn mowers, always using the same strategy: first, they make a series of passes along the length of the field, and then they do the same along the width of the field. All passes are straight lines, parallel to the sides of the field.
 
 
 The ICSC has hired a new lawn-mower, Guido. Guido is very chaotic, and instead of covering the field incrementally, he likes to choose random starting positions for each of his passes. But he is afraid of not doing a good job and being fired by the ICSC, so he has asked you to help him. Write a program to make sure that the grass in the field is perfectly cut: all parts of the field have to be mowed at least once when the mower goes from end to end, and again when the mower goes from side to side. 
 
 Input
 Each test case contains 3 lines. The first line contains two integers, nx (0 < nx < 1000) and ny (0 < nx < 1000), and a real number w (0 < w ≤ 50), which represents the width of the cut of that particular lawn mower. The next line describes the end-to-end passes (along the length of the field), and contains nx real numbers xi (0 ≤ xi ≤ 75) describing the starting positions of the mower's center in Guido's end-to-end passes. The last line describes the side-to-side passes, with ny real numbers yi (0 ≤ yi ≤ 100).
 The end of the test cases is signalled with a line that contains the numbers 0 0 0.0. You should generate no output for this line, as it is not a test case.
 Real numbers for w, xi and yi can have up to 7 digits after the decimal point, and any cut will also include its boundaries. For example, if a 2.0-meter wide cut is performed along the 10.0-meter mark, then a strip of grass from 9.0 to 11.0 (including both) will be considered "cut".
 
 Output
 Print YES if Guido has done a good job, or NO if some part of the field has not been mowed at least once when the mower was travelling along the length of the field, and again when it was travelling along the width.
 
 Sample Input
 8 11 10.0
 0.0 10.0 20.0 30.0 40.0 50.0 60.0 70.0
 0.0 10.0 20.0 30.0 40.0 50.0 60.0 70.0 80.0 90.0 100.0
 8 10 10.0
 0.0 10.0 20.0 30.0 40.0 50.0 60.0 70.0
 0.0 10.0 30.0 40.0 50.0 60.0 70.0 80.0 90.0 100.0
 4 5 20.0
 70.0 10.0 30.0 50.0
 30.0 10.0 90.0 50.0 70.0
 4 5 20.0
 60.0 10.0 30.0 50.0
 30.0 10.0 90.0 50.0 70.0
 0 0 0.0
 Sample Output
 YES
 NO
 YES
 NO
*/