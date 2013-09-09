#include <iostream>
using namespace::std;

int main()
{
    int i,j,k,m,n;
    while(scanf("%d%d%d%d%d",&i,&j,&k,&m,&n)==5)
	{
		if(i^j^(k+m+n-1)%2)
			printf("Red\n");
		else 
			printf("Black\n");
	}
    return 0;
}
/*
 通常的Nim游戏的定义是这样的：有若干堆石子，每堆石子的数量都是有限的，合法的移动是“选择一堆石子并拿走若干颗（不能不拿）”，
 如果轮到某个人时所有的石子堆都已经被拿空了，则判负（因为他此刻没有任何合法的移动）。 
 本题就如有五堆石子，数量为m，n，s1，s2，s3，对于s1，s2，s3三堆石子来说，每次只能取一颗石子，而且每堆要保留一颗。
 对于m，n两堆石子来说，每次只能取任意颗石子，取完为止，谁取到最后一颗将获得胜利。
 以Nim游戏为例来进行一下计算。比如说我刚才说当只有两堆石子且两堆石子数量相等时后手有必胜策略，也就是这是一个P-position，
 下面我们依靠定义证明一下(3,3)是一个P是一个P是一个P-position。首先(3,3)的子局面（也就是通过合法移动可以导致的局面）
 有(0,3)(1,3)(2,3)（显然交换石子堆的位置不影响其性质，所以把(x,y)和(y,x)看成同一种局面），只需要计算出这三种局面的
 性质就可以了。 
(0,3)的子局面有(0,0)、(0,1)、(0,2)，其中(0,0)显然是P-position，所以(0,3)是N-position
 （只要找到一个是P-position的子局面就能说明是N-position）。(1,3)的后继中(1,1)是P-position（因为(1,1)的唯一
 子局面(0,1)是N-position），所以(1,3)也是N-position。同样可以证明(2,3)是N-position。所以(3,3)的所有子局面
 都是N-position，它就是P-position。通过一点简单的数学归纳，可以严格的证明“有两堆石子时的局面是P-position当且仅
 当这两堆石子的数目相等”。 
 对于一个Nim游戏的局面(a1,a2,...,an)，它是P-position当且仅当a1^a2^...^an=0，其中^表示异或(xor)运算。
 怎么样，是不是很神奇？我看到它的时候也觉得很神奇，完全没有道理的和异或运算扯上了关系。但这个定理的证明却也不复杂，
 基本上就是按照两种position的证明来的。
 具体到本题，由于s1，s2，s3三堆石子每次只能取一颗，所以将三堆看成一堆即可，同样由于每次只能取一颗，
 影响结果的只是总数的奇偶性。所以，对于本题来说，只需要计算
 m^n^(( s1+s2+s3-3)%2)= m^n^(( s1+s2+s3-1)&1)
 如果其值为0，则黑胜，否则，红胜
*/
/*
 Problem description
 Both Xnby and Hekui like playing Chinese Chess. There are two sides: black and red in Chinese Chess. Each side take moves in turns. One day, they made a composition(Now, it's red's turn):
 
 By the way, each side can only move the "Cannon"and the "Pawn".. The cannon can move in straight lines at any distance (from one cross to another) if no other chess pieces block its way. And the pawn can only move forward, one unit per turn. (For the red, top-bottom is forward, and for the black, bottom-top).
 
 After the discussion,they all agree that only when one side, for example, the black cannon is forced to take a horizonal move which makes the red cannon can get to the hemline of the black, then the red wins (See the following figure).
 
 
 So, they make a few rules:
 
 1.The cannon can only move forward. If one side has to move the "cannon" to left or right, he loses. Notice that it doesn't change situation if a cannon moves backward, because the opposite side can move its cannon forward for the same distance.
 2.Only the pawns which haven't crossed the river can move and the pawn can only move forward. The distance between each pair of pawns (one red, one black) can not be less than 1.
 3.The winner only depends on the distance m and n(between the pair of cannons in the same vertical line counting from the left side), S1,S2,S3 (between the pair of pawns' which not cross the river in the same vertical line counting from the left side).
 (See the following figure)
 
 Xnby and Hekui want to know: which side is the winner when each of them moves in the best strategy. To make it more interesting, m,n, S1,S2,S3 are not limited by Chinese Chessboard, in other words, Chessboard of this game is large enough. 
 
 
 Input
 There are several test cases, each case in a single line which contains 5 integers separated by a blank: m, n,S1,S2,S3 , 0≤m,n≤1000000,1≤ S1,S2,S3 ≤1000. The input terminates when one line contains a single negative integer, which needn't to be processed.
 
 Output
 For each test case, output the winner(Red or Black)
 
 Sample Input
 4 1 2 2 1
 0 0 1 1 1
 -1
 Sample Output
 Red
 Black
*/