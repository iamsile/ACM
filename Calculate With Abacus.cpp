#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int cal(int k)
{
	int i,m=1;
	for(i=0;i<k;i++)
		m=m*10;
	return m;
}

int main()
{
	int t,lab=0;
	scanf("%d",&t);
	while(t--) {
		int i,j,x,y,flag=0,sum=0,num=0;
		int a[10];
		char map[10][10];
		memset(a,0,sizeof(a));
		memset(map,0,sizeof(map));
		if(lab)
			scanf("\n");
		scanf("%d%d",&x,&y);
		for(i=x;i<=y;i++)
			sum+=i;
		for(i=0;i<8;i++)
			scanf("%s",map[i]);
		for(j=5;j>=0;j--) {
			for(i=0; i<8; i++) {
				if(map[i][j]=='o'&&flag==0)
					if(i==1)
						a[j]=5*cal(5-j);
				if(map[i][j]=='-')
					flag=1;
				if(map[i][j]=='|'&&flag) {
					if(j==5)
						a[j]+=(i-3);
					else a[j]+=(i-3)*cal(5-j);
				}
			}
			flag=0;
		}
		for(i=0;i<6;i++)
			num+=a[i];
		if(num==sum)
			printf("No mistake\n");
		else printf("Mistake\n");
		lab++;
	}
	return 0;
}
/*
 Abacus is a manual computing device consisting of a frame holding parallel rods strung with movable beads.
 
 
 How to calculate with Abacus:
 
 Each rod is divided into two parts by the separator. The upper part has 1 bead while the lower part has 4 beads.
 Each rod has its own unit. From right to left, the units are in 1, 10, 100, 1000, ... The leftmost rod is with the largest unit and the rightmost one with the smallest unit(1).
 Each upper bead represents 5 units of its rod and one lower bead represents 1 unit.
 Initially, all the upper beads are moved up and all the lower beads are moved down. This represents the number 0. When you add some number, you move upper beads down or move lower beads up. For example, when two lower beads in the first (from right) rod are moved up, it represents the number 2. When one upper bead in the first rod is moved down and three lower beads in the third rod are moved up, it represents 305.
 
 Now with the abacus, your teacher asks you to calculate the sum from number x to number y, both inclusive. After you finish the work, you want to check whether you make any mistake during the calculation.
 
 Input
 
 The first line of the input contains an integer T (T <= 50), indicating the number of cases.
 
 Each case has two parts. The first part in one line consists of two integers x and y (1 <= x <= y <= 1000), indicating the start number and the end number for the sum calculation. The second part is a description for the abacus after you finish the calculation. This part consists of 8 lines and each line consists of 6 characters. Each character is one of 'o' (bead), '|' (rod) and '-' (separator). The first two lines represent the upper beads. The third line always consists of '-', representing the separator. The fourth to the eighth lines represent the lower beads. One column represents one rod. Exactly one '|' appears in the upper part and one '|' appears in the lower part in each rod. All the input represents a valid abacus.
 
 Cases are separated by one blank line.
 Output
 
 If there is no mistake in the calculation, output "No mistake", else output "Mistake".
 
 Sample Input
 
 3
 1 3
 ooooo|
 |||||o
 ------
 |||||o
 ooooo|
 oooooo
 oooooo
 oooooo
 
 2 4
 oooooo
 ||||||
 ------
 ||||o|
 oooooo
 oooo|o
 oooooo
 oooooo
 
 20 21
 oooooo
 ||||||
 ------
 ||||oo
 ooooo|
 oooooo
 oooooo
 oooo|o
 
 Sample Output
 
 No mistake
 Mistake
 No mistake