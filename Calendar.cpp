#include <iostream>    
using namespace std;  

int main()
{
    int i=0,j=0,years[8000]={0},year=0,month=0,day=0,weekday=0,
	days[2][13]={365,31,28,31,30,31,30,31,31,30,31,30,31,366,31,29,31,30,31,30,31,31,30,31,30,31};
    long n;
    char weekdays[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    for(i=0;i<8000;i++)  
    {
        int temp=2000+i;  
        if((temp%4==0&&temp%100!=0)||temp%400==0)  
            years[i]=1;  
    }
    while(cin >> n&&n!=-1)
    {
        n++;  
        weekday=(n-1)%7;
        for(i=0;n>days[years[i]][0];i++)  
            n-=days[years[i]][0];
        year=2000+i;  
        for(j=1;n>days[years[i]][j];j++)  
            n-=days[years[i]][j]; 
        month=j; 
        day=n;  
        printf("%d-",year);  
        if(month<10) 
			printf("0%d-",month);  
        else 
			printf("%d-",month);  
        if(day<10) 
			printf("0%d ",day);  
        else 
			printf("%d ",day);  
        printf("%s\n",weekdays[weekday]);  
    }
	return 0;
}  

/*
 Problem description
 A calendar is a system for measuring time, from hours and minutes, to months and days, and finally to years and centuries. The terms of hour, day, month, year and century are all units of time measurements of a calender system. According to the Gregorian calendar, which is the civil calendar in use today, years evenly divisible by 4 are leap years, with the exception of centurial years that are not evenly divisible by 400. Therefore, the years 1700, 1800, 1900 and 2100 are not leap years, but 1600, 2000, and 2400 are leap years. Given the number of days that have elapsed since January 1, 2000 A.D, your mission is to find the date and the day of the week.
 
 Input
 The input consists of lines each containing a positive integer, which is the number of days that have elapsed since January 1, 2000 A.D. The last line contains an integer −1, which should not be processed. You may assume that the resulting date won’t be after the year 9999.
 
 Output
 For each test case, output one line containing the date and the day of the week in the format of "YYYY-MM-DD DayOfWeek", where "DayOfWeek" must be one of "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" and "Saturday".
 
 Sample Input
 1730
 1740
 1750
 1751
 -1
 Sample Output
 2004-09-26 Sunday
 2004-10-06 Wednesday
 2004-10-16 Saturday
 2004-10-17 Sunday
*/