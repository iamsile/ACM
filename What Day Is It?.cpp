#include <iostream>
using namespace std;

char mo[12][10]={"January","February","March","April","May","June","July",
    "August","September","October","November","December"};
int m1[13]={0,0,3,3,6,1,4,6,2,5,0,3,5};
const int cnt[2][12]=
{
    31,28,31,30,31,30,31,31,30,31,30,31,
    31,29,31,30,31,30,31,31,30,31,30,31
};

bool leapyear(int y)
{
    if(y>1752)
        return (y%400==0 || ((y%4==0)&&(y%100!=0)));
    else return y%4==0;
}

bool check(int m,int d,int y)
{
    if(! (m>=1 && m<13)) return false;
    if(! (d>=1 && d<=cnt[leapyear(y)][m-1])) return false;
    if(y==1752 && m==9 && d>2 && d<14) return false;
    return true;
}


int main()
{
    int y,m,d;
    while(cin >> m >> d >> y) {
        if(!m&&!d&&!y)
            break;
        if(!check(m,d,y)) {
            printf("%d/%d/%d is an invalid date\n",m,d,y);
            continue;
        }
        int k=y-1,y1,n,mm=0;
        if(y<1752||(y==1752&&m<9)||(y==1752&&m==9&&d<3))
            y1=k+k/4+5;
        else   y1=k+k/4-k/100+k/400;
        if(leapyear(y)&&m>2)
            mm=m1[m]+1;
        else mm=m1[m];
        n=(y1+mm+d)%7;
        printf("%s %d, %d is a ",mo[m-1],d,y);
        if(n==0) printf("Sunday\n");
        else if (n==1) printf("Monday\n");
        else if (n==2) printf("Tuesday\n");
        else if (n==3) printf("Wednesday\n");
        else if (n==4) printf("Thursday\n");
        else if (n==5) printf("Friday\n");
        else if (n==6) printf("Saturday\n");
    }
    return 0;
}
/*
 Problem description
 The calendar now in use evolved from the Romans. Julius Caesar codified a calendar system that came to be known as the Julian calendar. In this system, all months have 31 days, except for April, June, September, and November, which have 30 days, and February, which has 28 days in non-leap years, and 29 days in leap years. Also, in this system, leap years happened every four years. That is because the astronomers of ancient Rome computed the year to be 365.25 days long, so that after every four years, one needed to add an extra day to keep the calendar on track with the seasons. To do this, they added an extra day (February 29) to every year that was a multiple of four. 
 
 Julian Rule:	Every year that is a multiple of 4 is a leap year, i.e. has an extra day (February 29). 
 
 In 1582, Pope Gregory's astronomers noticed that the year was not 365.25 days long, but closer to 365.2425. Therefore, the leap year rule would be revised to the following:
 
 Gregorian Rule: Every year that is a multiple of 4 is a leap year, unless it is a multiple of 100 that is not a multiple of 400. 
 
 To compensate for how the seasons had shifted against the calendar up until that time, the calendar was actually shifted 10 days: the day following October 4, 1582 was declared to be October 15.
 
 England and its empire (including the United States) didn't switch to the Gregorian calendar system until 1752, when the day following September 2 was declared to be September 14. (The delay was caused by the poor relationship between Henry VIII and the Pope.)
 
 Write a program that converts dates in the United States using a calendar of the time and outputs weekdays. 
 
 
 Input
 The input will be a series of positive integers greater than zero, three integers per line, which represent dates, one date per line. The format for a date is "month day year" where month is a number between 1 (which indicates January) and 12 (which indicates December), day is a number between 1 and 31, and year is positive number. 
 
 The input will end with three zeroes. 
 
 Output
 The output will be the input date and name of the weekday on which the given date falls in the format shown in the sample. An invalid date or nonexistent date for the calendar used in the United States at the time should generate an error message indicating a invalid date. 
 
 Sample Input
 11 15 1997
 1 1 2000
 7 4 1998
 2 11 1732
 9 2 1752
 9 14 1752
 4 33 1997
 0 0 0
 Sample Output
 November 15, 1997 is a Saturday
 January 1, 2000 is a Saturday
 July 4, 1998 is a Saturday
 February 11, 1732 is a Friday
 September 2, 1752 is a Wednesday 
 September 14, 1752 is a Thursday
 4/33/1997 is an invalid date
*/