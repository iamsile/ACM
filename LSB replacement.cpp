#include <iostream>
int *a=new int[265225];

void replace( char c, int pos )
{
	for (int i=0;i<8;i++)
	{
		bool tmp=c&(1<<(7-i));
		if(a[pos+i]&1) 
			a[pos+i]^=1;
		a[pos+i]|=tmp;
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j,pos=0,sum=m*n;
	for(i=0;i<sum;i++)
		scanf("%d",&a[i]);
	char b[515<<1];
	getchar(); 
	gets(b);
	int len=strlen(b);
	if((len<<3)>sum) 
	{
		printf("LSB embedding Error!\n");
		return 0;
	}
	pos=0;
	for(i=0;b[i];i++)
	{
		replace(b[i],pos);
		pos+=8;
	}	
	pos=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j) 
				printf(" ");
			printf("%d",a[pos++]);
		}
		printf("\n");
	}  
    return 0;    
}
/*
Problem description
Information hiding in computer science is the principle of hiding of design decisions in a computer program that are most likely to change, thus protecting other parts of the program from change if the design decision is changed. The protection involves providing a stable interface which shields the remainder of the program from the implementation (the details that are most likely to change). Steganography is an application of information ahiding. The LSB(Least-significant-bit) is most widely used.LSB replacement embeds a message into the cover image by replacing the LSBs of the cover image with message bits to get the stego image.LSB replacement increases even pixel values eigher by one or leaves them unmodified,while odd values are left unchanged or decreased by one.eg.we want to embed the secret message ‘0101’ to the cover data ‘13 12 11 10’,we then get the stego data ’12 13 10 11’.First we embed the binary bit 0 to 13, since 13’s binary format is ‘1101’ ,so ,we replace the last bit 1 with 0.Now we get the stego data 1100 = 12. Now give you the secret message and the cover images, can your embedded the message into the cover image? 

Input
the there are two integer n,m,(n,m < 513),then the cover image data,m line and each line n integers.the next line is the secret message.First you need to change the message to binary stream,the message use ASCII code.Then embed the binary stream into the cover images sequently.

Output
Output the stego image data.If cannot embed all of the message in the cover image,you should print: LSB embedding Error!


Sample Input
8 1
1 2 3 4 5 6 7 8
A
Sample Output
0 3 2 4 4 6 6 9
*/