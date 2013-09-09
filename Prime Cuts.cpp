#include <iostream>
using namespace std;

int main()
{
    int n, c;
    while(cin >> n >> c)
    {
        // 變數初始化
        bool *prime =new bool[n];
        for(int i=0;i<n;i++)
            prime[i] = true;
        // 紀錄哪些數是質數
        int num=1;
        for(int i=2;i<=n;i++)
            if(prime[i-1])
            {
                num++;
                for(int j=2;j*i<=n;j++)
                    prime[j*i-1]=false;
            }
        cout << n << " " << c << ":";
        int i,x,p=2*c-(num%2?1:0);
        // 跳過不需輸出的質數
        x=0;
        for(i=0;x<(num-p)/2;i++)
            if(prime[i]) 
				x++;
        // 開始輸出的質數
        x = 0;
        for( ;x<p&&i<n;i++)
            if (prime[i])
            {
                cout << " " << i + 1;
                x++;
            }
        cout << endl << endl;
    }
    return 0;
}
/*
 這一題，我利用埃氏篩法(Sieve of Eratosthenes)來找出兩數字之間的所有質數。
 首先，我先建立一個大小為 n 的布林陣列 - prime，代表某數字是否為質數。
 由於我們已知：若是一個正整數為另一個正整數的倍數，則這個整數必定不是質數。所以，我們利用迴圈，從已知的最小質數 2 開始，將所有小於等於 n 的 2 的倍數標記為「非質數」。
 接著，我們從下一個質數 3 開始，進行相同的步驟，將所有小於等於 n 的 3 的倍數標記為「非質數」。接著再找下一個質數，不斷重複，直到找出所有小於等於 n 的質數為止。
 找出所有質數之後，只要根據質數的數量，依照題目要求輸出中間 2 * C (或是 2 * C - 1)個質數，就完成了。
*/
/*
 Problem description
 A prime number is a counting number (  ) that is evenly divisible only by 1 and itself. In this problem you are to write a program that will cut some number of prime numbers from the list of prime numbers between (and including) 1 and N. Your program will read in a number N; determine the list of prime numbers between 1 and N; and print the C*2 prime numbers from the center of the list if there are an even number of prime numbers or (C*2)-1 prime numbers from the center of the list if there are an odd number of prime numbers in the list. 
 
 Input
 Each input set will be on a line by itself and will consist of 2 numbers. The first number (  ) is the maximum number in the complete list of prime numbers between 1 and N. The second number (  ) defines the C*2 prime numbers to be printed from the center of the list if the length of the list is even; or the (C*2)-1 numbers to be printed from the center of the list if the length of the list is odd. 
 
 Output
 For each input set, you should print the number N beginning in column 1 followed by a space, then by the number C, then by a colon (:), and then by the center numbers from the list of prime numbers as defined above. If the size of the center list exceeds the limits of the list of prime numbers between 1 and N, the list of prime numbers between 1 and N (inclusive) should be printed. Each number from the center of the list should be preceded by exactly one blank. Each line of output should be followed by a blank line. Hence, your output should follow the exact format shown in the sample output. 
 
 Sample Input
 21 2
 18 2
 18 18
 100 7
 Sample Output
 21 2: 5 7 11
 
 18 2: 3 5 7 11
 
 18 18: 1 2 3 5 7 11 13 17
 
 100 7: 13 17 19 23 29 31 37 41 43 47 53 59 61 67
 
*/