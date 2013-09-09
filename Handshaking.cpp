#include <iostream>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        cout << n << '\n';
    }
    return 0;
}
/*
 Problem description
 In our daily human communication, greetings between each other are primarily necessary. The differences between cultures and customs cause the differences between the courtesies in greeting, which colors the customs in greeting, such as nodding, bowing, hands-folding, hugging and handshaking, and among these, handshaking is regarded as a universal language in greetings.
 What shall we notice while shaking hands with others, since it is a regular courtesy in our social life? The most important point is that we should pay attention to the orders. Who should hand first while shaking hands? The seniors, the ladies and the teachers should give hands to the juniors, the men and the students. If two couples meet with each other, ladies greet each other first, then the husbands greet other's wives, and the greetings between men comes last. While the guests pay a visit, generally, the hosts hand first; and while saying goodbye, the guests hand first, meaning 'don't bother to see me out'.
 Based on what has been described above, there is a tough task left to you to complete:
 One day, the Lee’s invite N couples to dinner. Before the dinner they will shake hands with each other. The handshaking rules are: the couple does not shake hands with each other and at most one handshaking happens between two people. During the dinner, Mr. Lee asks the other people how many handshaking they took. And all the answers are different. Do you know how many times Mrs. Lee shakes hand with the others? 
 
 Input
 There will be several test cases. The input of each test case is only one line with one integer N（0 < n < 100）, which is the number of couples the Lee’s has invited. 
 
 Output
 For each test case, you only need to output how many times Mrs. Lee will shake hands with the others. 
 
 Sample Input
 2
 Sample Output
 2
*/