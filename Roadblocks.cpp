#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int kMaxN = 5000 + 10;
const int kMaxM = 100000 + 10;

struct Edge {
    int v, w;
    int value;
};
struct Node {
    Node(int a, int b) : v(a), value(b) { }
    int v;
    int value;
};

Edge edges[kMaxM];
vector<Node> graph[kMaxN];
int n, m;

int dist_1[kMaxN];
int dist_n[kMaxN];

void Spfa(int beg, int *dist) {
    queue<int> q;
    static bool used[kMaxN];
    memset(used, false, sizeof(used));
    fill_n(dist, kMaxN, 0x3F3F3F3F);
    q.push(beg);
    used[beg] = true;
    dist[beg] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        used[t] = false;
        for (int i = 0; i < static_cast<int>(graph[t].size()); ++i) {
            if (dist[graph[t][i].v] > dist[t] + graph[t][i].value) {
                dist[graph[t][i].v] = dist[t] + graph[t][i].value;
                if (!used[graph[t][i].v]) {
                    used[graph[t][i].v] = true;
                    q.push(graph[t][i].v);
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int x, y, value;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &x, &y, &value);
        edges[i].v = x;
        edges[i].w = y;
        edges[i].value = value;
        graph[x].push_back(Node(y, value));
        graph[y].push_back(Node(x, value));
    }
    
    Spfa(1, dist_1);
    Spfa(n, dist_n);
    
    int shortest = dist_1[n];
    int ans = 0x7FFFFFFF;
    for (int i = 1; i <= m; ++i) {
        int v = edges[i].v;
        int w = edges[i].w;
        int value = edges[i].value;
        int tmp;
        tmp = dist_1[v] + value + dist_n[w];
        if (tmp != shortest && tmp < ans) {
            ans = tmp;
        }
        tmp = dist_1[w] + value + dist_n[v];
        if (tmp != shortest && tmp < ans) {
            ans = tmp;
        }
    }
    printf("%d\n", ans);
    //system("pause");
    return 0;
}
/*
 Description
 
 Bessie has moved to a small farm and sometimes enjoys returning to visit one of her best friends. She does not want to get to her old home too quickly, because she likes the scenery along the way. She has decided to take the second-shortest rather than the shortest path. She knows there must be some second-shortest path.
 
 The countryside consists of R (1 ≤ R ≤ 100,000) bidirectional roads, each linking two of the N (1 ≤ N ≤ 5000) intersections, conveniently numbered 1..N. Bessie starts at intersection 1, and her friend (the destination) is at intersection N.
 
 The second-shortest path may share roads with any of the shortest paths, and it may backtrack i.e., use the same road or intersection more than once. The second-shortest path is the shortest path whose length is longer than the shortest path(s) (i.e., if two or more shortest paths exist, the second-shortest path is the one whose length is longer than those but no longer than any other path).
 
 Input
 
 Line 1: Two space-separated integers: N and R
 Lines 2..R+1: Each line contains three space-separated integers: A, B, and D that describe a road that connects intersections A and B and has length D (1 ≤ D ≤ 5000)
 Output
 
 Line 1: The length of the second shortest path between node 1 and node N
 Sample Input
 
 4 4
 1 2 100
 2 4 200
 2 3 250
 3 4 100
 Sample Output
 
 450
*/