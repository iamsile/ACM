#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        int x[10001],i,y[10001],sum=0;
        for (i=0; i<n; i++)
            cin >> x[i] >> y[i];
        sort(x, x+n);
        sort(y, y+n);
        for (i=0; i<n; i++)
            x[i]-=i;
        sort(x, x+n);
        for (i=0; i<n/2; i++)
            sum+=abs(x[i]-x[n-1-i])+abs(y[i]-y[n-1-i]);
        cout << sum << '\n';
    }
    return 0;
}
/*
 该题目是给出N个坐标,求他们移动到同一直线上,而且相互靠着的时候的最小步数.
 因为移动步数可以分解为移动到同一直线,再移动到相邻位置,因此可以分开求
 移动直线的时候,就是求 的最小值.如果对于两个点,那么对于任意一条在他们之间的直线, 的值是相同的,这个值就是他们两个的y值的差的绝对值,因此,将所有点根据y值排序后,从两头取点,作差,那么这个最小值就是这些值的和了.
 这样子,移动到同一直线上这个问题就解决了.
 那么相邻这个怎么办呢?  
 因为是相邻,因此可以假设最左边的点,相邻后还是最左边,因此如果不是的话,可以与最左边的点交换,步数一个增一个减,总步数还是一样的.这样,相邻后的点的位置就和原来的相对位置是一样的了.
 因此这样就是求 的最小值了.
 可是这个值一看上去好像有点难求,又不能用不等式,又不能像上面那样,因为后面多了个i.
 可是如果我们可以把这个i归到ai里面去的话,由于i的值是固定的,不就是变成 的最小值了么?
 这样一来,就变成和上面一样了.
 因此求相邻的时候,就是先把所有点按照X排序,然后每个值减去相应的i值,再排一次序,后面的做法就和上面一样了.这样最小步数也求出来了
 这是一条数论好题啊..不算难,不过也很巧妙..以后要多点做这些题目啊.
 Description
 
 N soldiers of the land Gridland are randomly scattered around the country. 
 A position in Gridland is given by a pair (x,y) of integer coordinates. Soldiers can move - in one move, one soldier can go one unit up, down, left or right (hence, he can change either his x or his y coordinate by 1 or -1). 
 
 The soldiers want to get into a horizontal line next to each other (so that their final positions are (x,y), (x+1,y), ..., (x+N-1,y), for some x and y). Integers x and y, as well as the final order of soldiers along the horizontal line is arbitrary. 
 
 The goal is to minimise the total number of moves of all the soldiers that takes them into such configuration. 
 
 Two or more soldiers must never occupy the same position at the same time. 
 Input
 
 The first line of the input contains the integer N, 1 <= N <= 10000, the number of soldiers. 
 The following N lines of the input contain initial positions of the soldiers : for each i, 1 <= i <= N, the (i+1)st line of the input file contains a pair of integers x[i] and y[i] separated by a single blank character, representing the coordinates of the ith soldier, -10000 <= x[i],y[i] <= 10000. 
 Output
 
 The first and the only line of the output should contain the minimum total number of moves that takes the soldiers into a horizontal line next to each other.
 Sample Input
 
 5
 1 2
 2 2
 1 3
 3 -2
 3 3
 Sample Output
 
 8
*/