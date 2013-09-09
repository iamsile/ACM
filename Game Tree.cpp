#include <iostream>
using namespace std;

typedef struct {
    int p,v,lab;
    char c;
}T;
T tree[1001];

int main()
{
    int n;
    while (cin >> n&&n) {
        int i,lab=1;
        for (i=2; i<=n; i++) {
            cin >> tree[i].c;
            if (tree[i].c=='N') {
                cin >> tree[i].p;
                tree[i].lab=i;
            }
            else if (tree[i].c=='L') {
                cin >> tree[i].p >> tree[i].v;
                tree[i].lab=i;
            }
        }
        for (i=n; i>=lab+1; i--)
            if (tree[i].p==lab) {
                if (tree[i].c=='L')
                    break;
                if (tree[i].c=='N') {
                    lab=tree[i].lab;
                    i=n+1;
                }
            }
        if (tree[i].v==1)
            cout << "+1\n";
        else if (tree[i].v==0)
            cout << "0\n";
        else 
            cout << "-1\n";
    }
    return 0;
}
/*
 Problem description
 A game for two players is determined by its tree. The competitors make moves in turn. The first competitor starts the game. The game ends up with either a draw, or a victory of one of the players. The leaf nodes of the tree of this game may have values equal to one of three numbers: “+1” - victory of the first competitor, “-1” - victory of the second competitor, “0” - draw. You have to find out who will win if both competitors follow the right strategy.
 
 Input
 The nodes of the tree are numbered with successive integer numbers. The root of the tree always has number 1. The first line of the input file contains an integer N (1 < N <= 1000) - the number of the nodes in the game tree, 0 present the end of input and should not be processed. Next N-1 lines describe the nodes - one line for each node (with exception for the first node). The second line will contain the description of the second node of the tree, the third line - the description of the third node, and so on. If the node is a leaf of the tree, the first symbol of the line is “L”, followed by a space, then the number of the ancestor of this node goes, another space, and the result of the game (+1: victory of the first player, -1: victory of the second one, 0: draw). If the node is an inner one then the line contains the first symbol “N”, a space character and the number of the ancestor of this node.
 
 Output
 contains "-1" if the second competitor wins, "+1" if so does the first and "0" if the result is a draw.
 
 Sample Input
 7
 N 1
 N 1
 L 2 -1
 L 2 +1
 L 3 +1
 L 3 +1
 
 7
 N 1
 N 1
 L 2 -1
 L 2 +1
 L 3 +1
 L 3 0
 
 18
 N 1
 N 1
 N 2
 L 2 +1
 N 3
 L 3 +1
 L 3 +1
 L 4 -1
 L 4 +1
 N 4
 N 6
 L 6 -1
 L 6 -1
 L 11 -1
 L 11 +1
 L 12 +1
 L 12 -1
 
 0
 Sample Output
 +1
 0
 +1
*/