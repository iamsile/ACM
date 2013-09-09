#include <iostream>
using namespace std;

int main()
{
    int n,lab=1;
    while (cin >> n&&n) {
        int i,m,r,c,w,h,nn,mm,a[151][4];
        cout << "Desktop " << lab++ << ":\n";
        for (i=1; i<=n; i++) {
            cin >> r >> c >> w >> h;
            a[i][0]=r;
            a[i][1]=c;
            a[i][2]=r+h-1;
            a[i][3]=c+w-1;
        }
        cin >> m;
        while (m--) {
            cin >> nn >> mm;
            for (i=n; i>=1; i--) {
                if (a[i][0]<=nn&&nn<=a[i][2])
                    if (a[i][1]<=mm&&mm<=a[i][3]) {
                        cout << "window " << i << '\n';
                        break;
                    }
            }
            if (i<1)
                cout << "background\n";
        }
    }
    return 0;
}
/*
 #include"iostream"
 #include"algorithm" 
 #define maxn 101
 using namespace std;
 int N,M;
 long r[maxn],c[maxn],w[maxn],h[maxn],cr[maxn],cc[maxn];
 
 int isIn(int x)
 {
 for(int k = 1;k <= N;k++)
 {
 if(cr[x]>=r[k]&&cr[x]<=r[k]+h[k]-1&&cc[x]>=c[k]&&cc[x]<=c[k]+w[k]-1)
 {
 return k;
 break;
 }            
 }    
 return 0;
 }   
 
 int main()
 {
 int cnt = 0;
 freopen("input.txt","r",stdin);
 //freopen("output.txt", "w", stdout);
 while(cin >> N && N)
 {
 cnt++;
 for(int i = 1;i <= N;i++)
 cin >> r[i] >> c[i] >> w[i] >> h[i];
 cin >> M;
 for(int j = 1;j <= M;j++)
 cin >> cr[j] >> cc[j];
 cout << "Desktop " << cnt << ":" << endl; 
 for(int k = 1;k <= M;k++)
 {
 if(isIn(k)) cout << "Window " << isIn(k) << endl;
 else cout << "Background" << endl;
 }       
 }
 system("pause");
 return 0;    
 }   
 Problem description
 Emma is not very tidy with the desktop of her computer. She has the habit of opening windows on the screen and then not closing the application that created them. The result, of course, is a very cluttered desktop with some windows just peeking out from behind others and some completely hidden. Given that Emma doesn’t log oﬀ for days, this is a formidable mess. Your job is to determine which window (if any) gets selected when Emma clicks on a certain position of the screen. Emma’s screen has a resolution of 106 by 106. When each window opens its position is given by the upper-left-hand corner, its width, and its height. (Assume position (0,0) is the location of the pixel in the upper-left-hand corner of her desktop. So, the lower-right-hand pixel has location (999999, 999999).)
 
 Input
 Input for each test case is a sequence of desktop descriptions. Each description consists of a line containing a positive integer n, the number of windows, followed by n lines, n ≤ 100, describing windows in the order in which Emma opened them, followed by a line containing a positive integer m, the number of queries, followed by m lines, each describing a query. Each of the n window description lines contains four integers r, c, w, and h, where (r, c) is the row and column of the upper left pixel of the window, 0 ≤ r, c ≤ 999999, and w and h are the width and height of the window, in pixels, 1 ≤ w, h. All windows will lie entirely on the desktop (i.e., no cropping). Each of the m query description lines contains two integers cr and cc, the row and column number of the location (which will be on the desktop). The last test case is followed by a line containing 0.
 
 Output
 Using the format shown in the sample, for each test case, print the desktop number, beginning with 1, followed by m lines, one per query. The i-th line should say either “window k”, where k is the number of the window clicked on, or “background” if the query hit none of the windows. We assume that windows are numbered consecutively in the order in which Emma opened them, beginning with 1. Note that querying a window does not bring that window to the foreground on the screen.
 
 Sample Input
 3
 1 2 3 3
 2 3 2 2
 3 4 2 2
 4
 3 5
 1 2
 4 2
 3 3
 2
 5 10 2 10
 100 100 100 100
 2
 5 13
 100 101
 0
 Sample Output
 Desktop 1:
 window 3
 window 1
 background
 window 2
 Desktop 2:
 background
 window 2
*/