#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace::std;
int M=0,N=0,x,y,x1,y1,x2,y2;
char g[300][300]={'\0'},cmds,c,name[300]={'\0'};
bool vis[300][300]={false};

int mins(int a,int b)
{
    if(a>b) a=b;
    return a;
}

void find(int i,int j,char col,char F)
{
    if(g[i][j]!=col || vis[i][j]  || !M || !N) 
        return;
    vis[i][j]=true;
    g[i][j]=F;
    
    
    
    find(i-1,j,col,F);
    find(i+1,j,col,F);
    find(i,j-1,col,F);
    find(i,j+1,col,F);
}
int main()
{
    int tmp;
    while(true)
    {
        scanf("%c",&cmds);
        if(cmds=='X') break;
        if(cmds=='I')
        {
            scanf("%d %d\n",&M,&N);
            for(int i=1;i<=N;i++)
                for(int j=1;j<=M;j++) 
                    g[i][j]='O';
        }else if(cmds=='C')
        {
            for(int i=1;i<=N;i++)
                for(int j=1;j<=M;j++) 
                    g[i][j]='O';
        }
        else if(cmds=='L')
        {
            scanf("%d %d %c\n",&x,&y,&c);
            if(y<=N && x<=M)
                g[y][x]=c;
        }else if(cmds=='V')
        {
            scanf("%d %d %d %c\n",&x,&y1,&y2,&c);
            if(y1>y2) 
            { 
                tmp=y1;
                y1=y2;
                y2=tmp; 
            }
            y1=mins(y1,N); 
            y2=mins(y2,N); 
            x=mins(x,M);
            for(int i=y1;i<=y2;i++)
                g[i][x]=c;
        }else if(cmds=='H')
        {
            scanf("%d %d %d %c\n",&x1,&x2,&y,&c);
            if(x1>x2) 
            { 
                tmp=x1; 
                x1=x2;
                x2=tmp; 
            }
            y=mins(y,N); 
            x1=mins(x1,M); 
            x2=mins(x2,M);
            for(int j=x1;j<=x2;j++)
                g[y][j]=c;
        }else if(cmds=='K')
        {
            scanf("%d %d %d %d %c\n",&x1,&y1,&x2,&y2,&c);
            if(x1>x2) 
            { 
                tmp=x1; 
                x1=x2;
                x2=tmp; 
            }
            if(y1>y2) 
            { 
                tmp=y1; 
                y1=y2; 
                y2=tmp; 
            }
            y1=mins(y1,N);
            y2=mins(y2,N);
            x1=mins(x1,M); 
            x2=mins(x2,M);
            for(int i=y1;i<=y2;i++)
                for(int j=x1;j<=x2;j++)
                    g[i][j]=c;
        }else if(cmds=='F')
        {
            scanf("%d %d %c\n",&x,&y,&c);
            y=mins(y,N); 
            x=mins(x,M);
            memset(vis,false,sizeof(vis));
            find(y,x,g[y][x],c);
        }else if(cmds=='S')
        {
            scanf("%s",name);
            printf("%s\n",name);
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=M;j++)
                    printf("%c",g[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
/*
 Graphical editors such as Photoshop allow us to alter bit-mapped images in the same way that text editors allow us to modify documents. Images are represented as an M x N array of pixels, where each pixel has a given color.
 
 Your task is to write a program which simulates a simple interactive graphical editor.
 
 Input
 
 The input consists of a sequence of editor commands, one per line. Each command is represented by one capital letter placed as the first character of the line. If the command needs parameters, they will be given on the same line separated by spaces.
 
 Pixel coordinates are represented by two integers, a column number between 1...M and a row number between 1...N, where 1M, N250. The origin sits in the upper-left corner of the table. Colors are specified by capital letters.
 
 The editor accepts the following commands:
 
 I M N	 Create a new M x N image with all pixels initially colored white (O).
 C	 Clear the table by setting all pixels white (O). The size remains unchanged.
 L X Y C	 Colors the pixel (X, Y) in color (C).
 V X Y1 Y2 C	 Draw a vertical segment of color (C) in column X, between the rows Y1 and Y2 inclusive.
 H X1 X2 Y C	 Draw a horizontal segment of color (C) in the row Y, between the columns X1 and X2 inclusive.
 K X1 Y1 X2 Y2 C	 Draw a filled rectangle of color C, where (X1, Y1) is the upper-left and (X2, Y2) the lower right corner.
 F X Y C	 Fill the region R with the color C, where R is defined as follows. Pixel (X, Y) belongs to R. Any other pixel which is the same color as pixel (X, Y) and shares a common side with any pixel in R also belongs to this region.
 S Name	 Write the file name in MSDOS 8.3 format followed by the contents of the current image.
 X	 Terminate the session.
 Output
 
 On every command S NAME, print the filename NAME and contents of the current image. Each row is represented by the color contents of each pixel. See the sample output.
 
 Ignore the entire line of any command defined by a character other than I, C, L, V, H, K, F, S, or X, and pass on to the next command. In case of other errors, the program behavior is unpredictable.
 
 Sample Input
 
 I 5 6
 L 2 3 A
 S one.bmp
 G 2 3 J
 F 3 3 J
 V 2 3 4 W
 H 3 4 2 Z
 S two.bmp
 X
 Sample Output
 
 one.bmp
 OOOOO
 OOOOO
 OAOOO
 OOOOO
 OOOOO
 OOOOO
 two.bmp
 JJJJJ
 JJZZJ
 JWJJJ
 JWJJJ
 JJJJJ
 JJJJJ
*/