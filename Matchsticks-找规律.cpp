#include <iostream>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};

int main()
{
    int t,i,j,k,s,len=2,b[30]={0};
    for (i=1; i<=20; i++)
        for (j=0; j<1000; j++) {
            k=j;
            s=0;
            while (k) {
                s+=a[k%10];
                k/=10;
            }
            if (s==i) {
                b[len++]=j;
                break;
            }
        }
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        if (n<=20)
            printf("%d",b[n]);
        else {
            int m=n%7+14;
            cout << b[m] << string((n-m)/7,'8');
        }
        cout << ' ' << (n%2==1?7:1) << string(n/2-1,'1') << '\n';
    }
    return 0;
}
/*
using namespace std;

#include <iostream>
#include <vector>

const int digits[10] = { 6,2,5,5,4,5,6,3,7,6 };

int main () {
    
    vector<int> best(22,INT_MAX);
    for (int i=1; i<1000; i++) {
        int j=i, x=0;
        while (j) x+=digits[j%10], j/=10;
        best[x] <?= i;
    }
    
    int runs;
    cin>>runs;
    while (runs--) {
        int n;
        cin>>n;
        
        if (n<21)
            cout<<best[n];
        else {
            int x = n%7+14;
            cout<<best[x]<<string((n-x)/7,'8');
        }
        
        cout<<" "<<(n%2==1?7:1)<<string(n/2-1,'1')<<endl;
    }
    return 0;   
}
*/
/*
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
const int s[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void gen(int N, int L, int dir) {
    for (int i = 1; i <= L; ++i)
        for (int d = 9*(1-dir)/2; 0 <= d && d <= 9; d += dir)
            if (d+i > 1 && 2*(L-i) <= N-s[d] && 7*(L-i) >= N-s[d]) {
                printf("%d", d), N -= s[d];
                break;
            }
}

void solve() {
    int N;
    scanf("%d", &N);
    gen(N, (N+6)/7, 1);
    printf(" ");
    gen(N, N/2, -1);
    printf("\n");
}

int main(void) {
    int N;
    for (scanf("%d", &N); N--; solve());
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include <ext/hash_set>
#include <ext/hash_map>
#include <ext/numeric>
#include <ext/functional>
#include <ext/rope>
#include <ext/rb_tree>
#include <ext/iterator>
#include <ext/slist>

#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define REP(i, n) for(int i=0; i<n; ++i)
#define REPD(i, n) for(int i=(n)-1; i>=0; --i)
#define FOR(i, b, e) for(typeof(e) i=b; i!=e; ++i)

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

int nmatches[]={6,2,5,5,4,5,6,3,7,6};

string dp[1000];

string &calc(int N) {
    if(N==0) return dp[0];
    if(N<0) return dp[1];
    if(SZ(dp[N])) return dp[N];
    string res=string(1000,'9');
    REP(i, 10) {
        string &tmp=calc(N-nmatches[i]);
        if(1+SZ(tmp)<SZ(res)) res=(char)('0'+i)+ tmp;
    }
    return dp[N]=res;
}

void go() {
    int N;
    cin >> N;
    if(N==0) {cout << "0 0\n"; return;}
    dp[0]=string();
    dp[1]=string(1000,'9');
    string res=string(1000,'9');
    FOR(i, 1, 10) {
        string tmp=(char)('0'+i)+calc(N-nmatches[i]);
        if(SZ(tmp)<SZ(res)) res=tmp;
    }
    cout << res << " ";
    if(N&1) cout << '7' << string((N-3)/2,'1') << endl;
    else cout << string(N/2,'1') << endl;
}

int main() {
    int nruns;
    cin >> nruns;
    while(nruns--) go();
    return 0;
}
*/
/*
 Problem description
 Matchsticks are ideal tools to represent numbers. A common way to represent the ten decimal digits with matchsticks is the following:
 
 
 
 This is identical to how numbers are displayed on an ordinary alarm clock. With a given number of matchsticks you can generate a wide range of numbers. We are wondering what the smallest and largest numbers are that can be created by using all your matchsticks.
 
 Input
 On the first line one positive number: the number of testcases, at most 100. After that per testcase:
 One line with an integer n (2 ≤ n ≤ 100): the number of matchsticks you have
 
 
 Output
 Per testcase:
 
 One line with the smallest and largest numbers you can create, separated by a single space. Both numbers should be positive and contain no leading zeroes.
 
 
 Sample Input
 4
 3
 6
 7
 15
 Sample Output
 7 7
 6 111
 8 711
 108 7111111
*/