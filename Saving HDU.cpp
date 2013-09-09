#include <iostream>
#include <algorithm>
using namespace std;
#define max 200
struct bao {
    int m,p;
}b[max];

int cmp(const void *a,const void *b)
{
    return (*(struct bao *)b).p - (*(struct bao *)a).p;
}

int main()
{
    int v,n;
    while (cin >> v >> n) {
        int i;
        for (i=0; i<n; i++)
            cin >> b[i].p >> b[i].m;
        qsort(b, n, sizeof(b[0]), cmp);
        int h=0,f=0;
        for (i=0; i<n; i++)
            if ((f+b[i].m)<=v) {
                h+=b[i].p*b[i].m;
                f+=b[i].m;
            }
            else {
                h+=b[i].p*(v-f);
                break;
            }
        cout << h << '\n';
    }
}
/*
 Problem Description
 话说上回讲到海东集团面临内外交困，公司的元老也只剩下XHD夫妇二人了。显然，作为多年拼搏的商人，XHD不会坐以待毙的。
 一天，当他正在苦思冥想解困良策的时候，突然想到了自己的传家宝，那是公司成立的时候，父亲作为贺礼送来的一个锦囊，徐父当时交代，不到万不得已的时候，不要打开它。“现在不正是最需要的时候吗？”，一边想，XHD一边找到了这个精心保管的锦囊，打开一看，里面只有一句话“杭城北麓千人洞有宝”。
 二话不说，XHD拿起一个大口袋就出发了，这个千人洞他是知道的，小的时候，爸爸曾经带他来过这个隐蔽的路口，并告诉他，这是千人洞。他现在才明白爸爸当初这句话的含义。
 尽管有点印象，XHD还是花了很大的精力才找到这个异常隐蔽的洞口，走进一看，几乎惊呆了，真的是眼花缭乱！不过尽管宝贝的种类不少，但是每种宝贝的量并不多，当然，每种宝贝单位体积的价格也不一样，为了挽救HDU，现在请你帮忙尽快计算出来XHD最多能带回多少价值的宝贝？（假设宝贝可以分割，分割后的价值和对应的体积成正比）
 
 
 Input
 输入包含多个测试实例，每个实例的第一行是两个整数v和n(v,n<100)，分别表示口袋的容量和宝贝的种类，接着的n行每行包含2个整数pi和mi(0<pi,mi<10)，分别表示某种宝贝的单价和对应的体积，v为0的时候结束输入。
 
 
 Output
 对于每个测试实例，请输出XHD最多能取回多少价值的宝贝，每个实例的输出占一行。
 
 
 Sample Input
 2 2
 3 1
 2 3
 0
 
 
 Sample Output
 5
*/