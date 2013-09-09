#include <iostream>
using namespace std;
#define FF(i,n) for(int i=0;i<n;i++)

struct tree{
    bool m;
    int len;
    tree *next[26];
    tree() {
        m=0;
        len=0;
        FF(i,26)
        next[i]=NULL;
    }
};

void build(tree *root, char a[])
{
    tree *p=root;
    int i,k=strlen(a);
    FF(i, k) {
        p->len++;
        if (p->next[a[i]-'a']==NULL) {
            tree *np=new tree;
            np->m=1;
            p->next[a[i]-'a']=np;
        }
        p=p->next[a[i]-'a'];
    }
    p->len++;
    p->m=1;
}

int dfs(tree *root, char d[])
{
    int i=0;
    while (root->len>1&&d[i]) {
        root=root->next[d[i]-'a'];
        i++;
    }
    return i;
}

int main()
{
    char a[30],c[100][30];
    tree *root=new tree;
    int i,j,k,cnt=0;
    while (~scanf("%s",a)) {
        strcpy(c[cnt++], a);
        build(root,a);
    }
    FF(i, cnt) {
        k=dfs(root,c[i]);
        cout << c[i] << ' ';
        FF(j, k)
        cout << c[i][j];
        cout << '\n';
    }
    cout << '\n';
    return 0;
}
/*
 Problem description
 A prefix of a string is a substring starting at the beginning of the given string. The prefixes of "carbon" are: "c", "ca", "car", "carb", "carbo", and "carbon". Note that the empty string is not considered a prefix in this problem, but every non-empty string is considered to be a prefix of itself. In everyday language, we tend to abbreviate words by prefixes. For example, "carbohydrate" is commonly abbreviated by "carb". In this problem, given a set of words, you will find for each word the shortest prefix that uniquely identifies the word it represents. 
 
 In the sample input below, "carbohydrate" can be abbreviated to "carboh", but it cannot be abbreviated to "carbo" (or anything shorter) because there are other words in the list that begin with "carbo". 
 
 An exact match will override a prefix match. For example, the prefix "car" matches the given word "car" exactly. Therefore, it is understood without ambiguity that "car" is an abbreviation for "car" , not for "carriage" or any of the other words in the list that begins with "car". 
 
 
 Input
 The input contains at least two, but no more than 1000 lines. Each line contains one word consisting of 1 to 20 lower case letters. 
 
 Output
 The output contains the same number of lines as the input. Each line of the output contains the word from the corresponding line of the input, followed by one blank space, and the shortest prefix that uniquely (without ambiguity) identifies this word. 
 
 Sample Input
 carbohydrate
 cart
 carburetor
 caramel
 caribou
 carbonic
 cartilage
 carbon
 carriage
 carton
 car
 carbonate
 Sample Output
 carbohydrate carboh
 cart cart
 carburetor carbu
 caramel cara
 caribou cari
 carbonic carboni
 cartilage carti
 carbon carbon
 carriage carr
 carton carto
 car car
 carbonate carbona
*/