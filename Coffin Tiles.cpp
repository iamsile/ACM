#include <iostream>
using namespace std;
#define N 1000000
int a[N];
int main()
{
    int i,j,n,t,b[1010]={0};
    for (i=1; i*i<=N; i++)
        for (j=i*i; j<=N; j+=i)
            a[j]++;
    for (i=1; i<=N; i++)
        if (b[a[i]]==0)
            b[a[i]]=i;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        if (n<N&&b[n])
            printf("%d\n",b[n]);
        else printf("Too big\n");
    }
    return 0;
}
/*
 Description

 The Pumpkin King has a great idea for this Christmas: Personalized coffins for all the good little boys and girls! To make them extra special, Jack has ordered that the coffins have various designs based upon the interests of the children (This was of course determined by what Google searches the children do most often. The Clown with the Tear-Away face has mad hacking skills).

 Most little girls, and some of the boys (Bronies) happen to be really into My Little Pony: Friendship is Magic, and so a large number of Twilight Sparkle themed coffins have been ordered (Twilight is of course, the most awesome pony on the show). These coffins are decorated by affixing alternating tiles in a rectangle up the middle of the coffin lid (They're flat). Now, all the children are different sizes and shapes. Some lids will need a rectangle 3 tiles wide, some less, and some more. In order to keep from ordering too many tiles from the.. ummm... coffin tile factory (Just go with it). The Mayor wants to know how many tiles he needs to order, based upon how many dimensionally unique rectangles can be made using tiles of a certain number.

 So, the mayor has asked you to write a program that will, for each given integer, "n", output the minimal number of tiles (The tiles are square) that can be arranged into exactly n unique rectangles. For example, if the number two was given, the minimal number of tiles required to make 2 unique rectangles is 4. With 4 you can make a 1x4 and a 2x2 rectangle.

 Input consists of a single integer indicating the number of integers to read and a sequence of positive integers separated by whitespace. For each input integer n your program should output either a single line containing the minimal number of unit squares that can be arranged into exactly n rectangles, or "Too big" if the number of needed unit squares is bigger than 1000000.


 Input

 5
 1 4 19 48 71

 Output


 Sample Input
 5
 1 4 19 48 71
 Sample Output
 1
 24
 786432
 27720
 Too big
*/