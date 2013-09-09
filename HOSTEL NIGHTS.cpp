#include <iostream>
using namespace std;

struct node {
    int num,cnt;
    char a[20];
};

int main()
{
    int n,k=1;
    scanf("%d",&n);
    while (n--) {
        node stu[21];
        int i,m,j,flag,sum,maxn=-1;
        bool lab[21][2000];
        char c,l;
        for (i=1; i<=20; i++)
            scanf("%d%s",&stu[i].num,stu[i].a);
        getchar();
        for (i=1; i<=20; i++)
            stu[i].cnt=0;
        for (j=1; j<=5; j++) {
            scanf("%c %d %c",&c,&m,&l);
            getchar();
            if (c=='O')
                flag=1;
            else flag=0;
            for (i=1; i<=20; i++) {
                if (flag) {
                    if (stu[i].num%2==1||stu[i].num%m==0||stu[i].a[0]==l)
                        lab[i][j]=0;
                    else
                        lab[i][j]=1;
                }
                else {
                    if (stu[i].num%2==0||stu[i].num%m==0||stu[i].a[0]==l)
                        lab[i][j]=0;
                    else lab[i][j]=1;
                }
            }
        }
        maxn=-1;
        for (i=1; i<=20; i++) {
            sum=0;
            for (j=1; j<=5; j++)
                if (lab[i][j])
                    sum++;
            if (sum>maxn)
                maxn=sum;
            stu[i].cnt=sum;
        }
        printf("Week %d\n",k++);
        for (i=1; i<=20; i++)
            if (stu[i].cnt==maxn)
                printf("%s\n",stu[i].a);
    }
    return 0;
}
/*
 Problem description
 Students staying in a hostel on the first floor have a reputation for being a bit too noisy. The warder decides to investigate reports of noisiness over the course of 5 nights of a week. Other students are not willing to dob in their floor-mates directly but will help him eliminate some rooms where the students were not noisy. They are eliminated through being either odd or even, because they are a multiple of some number n, or because the inhabitant’s name starts with a particular letter.
 Over the 5 nights the warden manages to form 3 variables from various other students’ help. At the end of 5 nights he will be able to work out who the noisiest students are. There is at least one as this floor is notorious.
 
 Input
 Input begins with a single integer, W, being the number of weeks worth of data (each week being 5 nights). The data for each week begins with 20 lines, each showing a room number and the name of a student, separated by a space. Rooms are numbered from 101 to 120. A student is represented by a single name.
 This names list is followed by 5 lines each representing one night of the week. Each line consists of a letter, a number and another letter, each of which is separated by a space. The first letter is E or O to indicate whether even (E) or odd (O) numbered rooms may be eliminated. The number is used to eliminate all rooms that are a multiple of that number. The second letter may be used to eliminate any students whose name begins with that letter.
 
 Output
 Output for each week consists of the week number, where the first week is 1, followed by a list of the noisiest students; that is those who have not been eliminated on the greatest number of nights. Names are output in room number order, one per line. Turn over for sample input and output.
 
 Sample Input
 1
 101 Fred
 102 Gregory
 103 Susan
 104 Rewi
 105 Albert
 106 Georgina
 107 Peter
 108 Bethany
 109 Sarah
 110 Justine
 111 Barry
 112 Matthew
 113 Francis
 114 Chris
 115 Devina
 116 Yong
 117 William
 118 Edward
 119 Ruth
 120 Luckylast
 O 5 G
 E 3 F
 E 5 S
 E 1 A
 O 4 C
 Sample Output
 Week 1
 Peter
 Edward
 Ruth
*/