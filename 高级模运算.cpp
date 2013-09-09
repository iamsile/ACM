#include <stdio.h>
__int64 find(__int64 a,__int64 b,__int64 n)
{
	__int64 d=1;
	__int64 t=a;
	while(b>0)
	{
		if(b%2==1)
			d=(d*t)%n;
		b=b/2;
		t = (t*t) % n;
	}
	return d;
}
int main()
{
	__int64 m,h,n,a,b;
	scanf("%I64d%I64d",&m,&h);
	n=0;
	while(h--)
	{
		scanf("%I64d%I64d",&a,&b);
		n+=find(a,b,m);
	}
	n=n%m;
	printf("%I64d\n",n);
	return 0;
}
/*
 令rec[1]=(a^1)%m,rec[2]=(a^2)%m,rec[3]=(a^4)%m,rec[4]=(a^8)%m,rec[5]=(a^16)%m....... 
 即: 
 rec[1]=a%m,rec[2]=(rec[1]^2)%m,rec[3]=(rec[2]^2)%m,rec[4]=(rec[3]^2)%m,rec[5]=(rec[4]^2)%m....... 
 初始化ans=1; 
 然后求出b的二进制形式,若b的二进制的第i位为1,则ans=(ans*rec[i])%m; 
 最后输出ans
 最后把所有对应的ans加起来对m取余
 */
/*
 Problem description
 人与人是不同的,有些人喜欢阅读满是图片的杂志，有些人喜欢在地下室引爆炸弹，而还有一些却喜欢一些麻烦的数字游戏。比如ESSE论坛的一次活动：
 每个人选择两个数字Ai和Bi写在纸上，其他人不能看见。过了一段时间后，每个人说出自己纸上的数字，然后每个人的目标是求出所有的AiBi 的和模M的值，最先算出结果的，就是胜利者。
 作为一个程序员，你当然有办法编一个程序，以最快的速度算出结果，赢得比赛。
 
 Input
 第一行是一个数字M (1≤M≤45000)。第二行是数字H（1≤H≤45000）表示参加游戏的人数。
 接下来H行，每行两个数Ai和Bi（1≤Ai，Bi≤231）。
 
 Output
 输出一个数字， (A1B1+ A2B2 + ... + AnBn) mod M 的值。 
 
 Sample Input
 16
 4
 2 3
 3 4
 4 5
 5 6
 Sample Output
 2
*/