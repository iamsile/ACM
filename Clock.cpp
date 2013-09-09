#include <iostream>
using namespace std;

struct T{
    int h,m;
    double v;
}tim[5];

int cmp(const void *a,const void *b)
{
    struct T *c=(T*)a;
    struct T *d=(T*)b;
    if (c->v > d->v) 
        return 1;
    else if (c->v < d->v) 
        return -1;
    else if (c->h > d->h) 
        return 1;
    else if (c->h < d->h) 
        return -1;
    else return c->m - d->m;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int i;
        for (i=0;i<5;i++) {
            scanf("%d:%d",&tim[i].h,&tim[i].m);
            tim[i].v=tim[i].m*1.0/60*360-(tim[i].h*1.0*30+tim[i].m*1.0/60*30);
            while(tim[i].v<0||tim[i].v>180) {
                if (tim[i].v<0) 
                    tim[i].v=0-tim[i].v;
                if (tim[i].v>180) 
                    tim[i].v=360-tim[i].v;
            }
        }
        qsort(tim,5,sizeof(tim[0]),cmp);
        printf("%02d:%02d\n",tim[2].h,tim[2].m);
    }
    return 0;
}
/*
 Problem description
 There is an analog clock with two hands: an hour hand and a minute hand.
 The two hands form an angle. The angle is measured as the smallest angle between the two hands. The angle between the two hands has a measure that is greater than or equal to 0 and less than or equal to 180 degrees.
 Given a sequence of five distinct times written in the format hh : mm , where hh are two digits representing full hours (00 <= hh <= 23) and mm are two digits representing minutes (00 <= mm <= 59) , you are to write a program that finds the median, that is, the third element of the sorted sequence of times in a nondecreasing order of their associated angles. Ties are broken in such a way that an earlier time precedes a later time.
 For example, suppose you are given a sequence (06:05, 07:10, 03:00, 21:00, 12:55) of times. Because the sorted sequence is (12:55, 03:00, 21:00, 06:05, 07:10), you are to report 21:00.
 
 Input
 The input consists of T test cases. The number of test cases (T) is given on the first line of the input file. Each test case is given on a single line, which contains a sequence of five distinct times, where times are given in the format hh : mm and are separated by a single space.
 
 Output
 Print exactly one line for each test case. The line is to contain the median in the format hh : mm of the times given. The following shows sample input and output for three test cases.
 
 Sample Input
 3
 00:00 01:00 02:00 03:00 04:00
 06:05 07:10 03:00 21:00 12:55
 11:05 12:05 13:05 14:05 15:05
 Sample Output
 02:00
 21:00
 14:05
*/