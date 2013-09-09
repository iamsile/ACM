#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int st[65];
int mark[65];
int s, j, n;

bool cmp(int a, int b){
    return a > b;
}

bool dfs(int sum, int k, int cnt){  //sum 是正在拼的木棍已经拼出的长度， k是从哪跟碎木块开始拼，cnt是正在拼第几根木块
    if (cnt == s) return true;                   //如果拼的木块数等于总长度除以所枚举的木棍长度
    else if (sum == j) return dfs(0, 0, cnt + 1);   //如果本根木块拼完，拼下一根，再次从第0根木棍开始找
    else{
        int pre, i;
        for (pre = 0, i = k; i < n; i++)                          //枚举木棍
            if (mark[i] && st[i] != pre && st[i] + sum <= j){      //如果这根木棍被加过，并且它不等于前一块的长度
                pre = st[i];                                                                   
                mark[i] = false;
                if (dfs(sum + st[i], i + 1, cnt)) break;                           //从下一根木棍开始搜索
                mark[i] = true;                                                             //如果向下搜索不成功回溯
                if (k == 0) return false;                                                //如果回溯后k==0说明这根正在被还原的这根木棍还原失败了.也就是说剩下的木棍不足以拼出原始木棍 
            }
        if (i == n) return false; else return true;                      //如果i < n 说明 搜索到成果了,若搜到 i == n-1 还未搜索到说明失败, 需要回退了 
    }
}

int main(){
    int i, sum;
    while(cin>>n, n){
        for (i = sum = 0; i < n; i++){
            cin>>st[i];
            sum += st[i];
        }
        sort(st, st + n, cmp);                                                         
        for (j = st[0]; j < sum; j++) 
            if (sum % j == 0){                //最长的木棍的长度一定不会超过以前的木棍长度，所以从最长的长度开始枚举
                s = sum / j;
                memset(mark, true, sizeof(mark));
                if (dfs(0, 0, 0)) break;
            }
        if (j == sum) cout<<sum<<endl; else cout<<j<<endl;
    }
    return 0;
}
/*
 Description
 
 George took sticks of the same length and cut them randomly until all parts became at most 50 units long. Now he wants to return sticks to the original state, but he forgot how many sticks he had originally and how long they were originally. Please help him and design a program which computes the smallest possible original length of those sticks. All lengths expressed in units are integers greater than zero.
 Input
 
 The input contains blocks of 2 lines. The first line contains the number of sticks parts after cutting, there are at most 64 sticks. The second line contains the lengths of those parts separated by the space. The last line of the file contains zero.
 Output
 
 The output should contains the smallest possible length of original sticks, one per line.
 Sample Input
 
 9
 5 2 1 5 2 1 5 2 1
 4
 1 2 3 4
 0
 Sample Output
 
 6
 5
*/