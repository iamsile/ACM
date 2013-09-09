#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        char a[21],*s1[21],*s2[21];
        int i,k,n,m,s,t,b[21];
        cin >> n >> m;
        for (i=0; i<n; i++) {
            cin >> a;
            s1[i]=strdup(a);
            s2[i]=NULL;
            b[i]=0;
        }
        for (i=0; i<m; i++) {
            cin >> s >> t;
            s2[t-1]=s1[s-1];
            b[s-1]=1;
        }
        for (i=0,k=0; i<n; i++)
            if (!b[i]) {
                while (s2[k]!=NULL)
                    k++;
                s2[k++]=s1[i];
            }
        for (i=0; i<n; i++) {
            if (i)
                cout << ' ';
            cout << s2[i];
        }
        cout << '\n';
    }
    return 0;
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void) {
    
    int datasets, i;
    char *queueA[20];
    char *queueB[20];
    int moved[20];
    int nextslot;
    
    scanf("%d",&datasets);
    
    for (i=0; i<datasets; i++) {
        
        int m, n, j, source, target;
        
        /* read in data set parameters */
        scanf("%d %d", &m, &n);
        
        /* read in the starting queue */
        for (j=0; j<m; j++) {
            char temp[10];
            scanf ("%s", temp);
            queueA[j]=strdup(temp);
            queueB[j]=NULL;
            moved[j]=0;
        }
        
        /* process the moves */
        for (j=0; j<n; j++) {
            scanf("%d %d", &source, &target);
            queueB[target-1]=queueA[source-1];
            moved[source-1]=1;
        }
        
        /* drop in all the unmoved items */
        nextslot=0;
        for (j=0; j<m; j++) {
            if (!moved[j]) {
                while (queueB[nextslot] != NULL) nextslot++;
                queueB[nextslot]=queueA[j];
                nextslot++;
            }
        }
        
        /* display the resulting queue */
        for (j=0; j<m; j++) {
            printf("%s ",queueB[j]);
        }
        printf("\n");
        
    }
    
}//10828
 Problem description
 You've got a queue. And you just got to mess with it. 
 Given a queue of items and a series of queue operations, return the resulting queue. 
 Queue operations are defined as follows: 
 starting-position to requested-position
 meaning one wants the item at the starting position to be moved to the requested position. So if the queue of items were: 
 Item1 Item2 Item3 Item4 Item5
 (Item1 being in position 1, Item2 in position 2, etc.) 
 after applying the queue operation: 
 5 to 2 
 the resulting queue would be: 
 Item1 Item5 Item2 Item3 Item4
 as Item5 (the item in position 5) was moved to position 2. Multiple queue operations are applied at the same time, however; e.g., given the queue of items: 
 Item1 Item2 Item3 Item4 Item5 Item6 Item7 Item8
 If the following queue operations were applied: 
 2 to 6; 6 to 3; 4 to 5; 5 to 2; 7 to 4; 8 to 1
 then the resulting queue would be: 
 Item8 Item5 Item6 Item7 Item4 Item2 Item1 Item3
 As you can see, the queue operations are strictly enforced, with other items (not involved in queue operations) maintaining their order and moving to vacant positions in the queue. Note that no two queue operations will have the same starting-position or same requested-position defined. 
 
 
 Input
 Input to this problem will begin with a line containing a single integer x indicating the number of datasets. Each data set consists of three components:
 
 Start line ? A single line, "m n" (1 <= m, n <= 20) where m indicates the number of items in the queue and n indicates the number of queue operations.
 Queue items ? A line of short (between 1 and 8 characters) alphanumeric names for the items in the queue. Names are unique for a given data set and contain no whitespace.
 Queue operations ? n lines of queue operations in the format "starting-position requested-position".
 
 
 Output
 For each dataset, output the queue after the queue operations have been applied. Print the elements of the queue on a single line, starting from the first and ending with the last, with a single space separating each item. 
 
 
 Sample Input
 3
 5 1
 alpha beta gamma delta epsilon
 5 2
 8 6
 a b c d e f g h
 2 6
 6 3
 4 5
 5 2
 7 4
 8 1
 3 2
 foo bar baz
 3 1
 1 3
 Sample Output
 alpha epsilon beta gamma delta
 h e f g d b a c
 baz bar foo
*/