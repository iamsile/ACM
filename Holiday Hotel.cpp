#include<iostream>
#include<algorithm>
using namespace std;

struct h{
    int d;
    int c;        
}data[10005];

int cmp(const void *a , const void *b)
{
    if((*(h *)a).d == (*(h *)b).d)
        return (*(h *)a).c - (*(h *)b).c;
    return (*(h *)a).d - (*(h *)b).d;    
}

int main()
{
    int n;
    while(cin >> n&&n)
    {
        for(int i=0;i<n;i++)
            cin >> data[i].d >> data[i].c;
        qsort(data,n,sizeof(h),cmp);   
        int min=data[0].c,count=1;
        for(int i=1;i<n;i++)
        {
            if(data[i].d==data[i-1].d)
                continue;
            if(data[i].c<min)
            {
                count++; 
                min=data[i].c;
            }       
        }
        cout << count << '\n';      
    }
    return 0;    
}
/*
 Problem description
 Mr. and Mrs. Smith are going to the seaside for their holiday. Before they start off, they need to choose a hotel. They got a list of hotels from the Internet, and want to choose some candidate hotels which are cheap and close to the seashore. A candidate hotel M meets two requirements: 
 Any hotel which is closer to the seashore than M will be more expensive than M. 
 Any hotel which is cheaper than M will be farther away from the seashore than M.
 
 
 
 Input
 There are several test cases. The first line of each test case is an integer N (1 <= N <= 10000), which is the number of hotels. Each of the following N lines describes a hotel, containing two integers D and C (1 <= D, C <= 10000). D means the distance from the hotel to the seashore, and C means the cost of staying in the hotel. You can assume that there are no two hotels with the same D and C. A test case with N = 0 ends the input, and should not be processed.
 
 Output
 For each test case, you should output one line containing an integer, which is the number of all the candidate hotels.
 
 Sample Input
 5
 300 100
 100 300
 400 200
 200 400
 100 500
 0
 
 Sample Output
 2
*/