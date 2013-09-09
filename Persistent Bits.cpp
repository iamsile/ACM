#include <iostream>
using namespace std;
const int flag=0xffff;

int main()
{
    int a,b,c,s;
    while (cin >> a&&a) {
        cin >> b >> c >> s;
        int i,k=s,lab=0,m=0x8000;
        for (i=1; i<c; i++) {
            k=(a*k+b)%c;
            lab|=(s^k)&flag;
        }
        for (i=0; i<16; i++) {
            if (lab&m)
                cout << '?';
            else {
                if (s&m)
                    cout << '1';
                else cout << '0';
            }
            m=m>>1;
        }
        cout << '\n';
    }
    return 0;
}
/*Problem description
WhatNext Software creates sequence generators that they hope will produce fairly random sequences of 16-bit unsigned integers in the range 0?5535. In general a sequence is specified by integers A, B, C, and S, where 1 ≤ A < 32768, 0 ≤ B < 65536, 2 ≤ C < 65536, and 0 ≤ S < C. S is the first element (the seed) of the sequence, and each later element is generated from the previous element. If X is an element of the sequence, then the next element is

(A*X + B) % C
where '%' is the remainder or modulus operation. Although every element of the sequence will be a 16-bit unsigned integer less than 65536, the intermediate result A*X + B may be larger, so calculations should be done with a 32-bit int rather than a 16-bit short to ensure accurate results.

Some values of the parameters produce better sequences than others. The most embarrassing sequences to WhatNext Software are ones that never change one or more bits. A bit that never changes throughout the sequence is persistent. Ideally, a sequence will have no persistent bits. Your job is to test a sequence and determine which bits are persistent.

For example, a particularly bad choice is A = 2, B = 5, C = 18, and S = 3. It produces the sequence 3, (2*3+5)%18 = 11, (2*11+5)%18 = 9, (2*9+5)%18 = 5, (2*5+5)%18 = 15, (2*15+5)%18 = 17, then (2*17+5)%18 = 3 again, and we're back at the beginning. So the sequence repeats the the same six values over and over:

Decimal	16-Bit Binary
3	0000000000000011
11	0000000000001011
9	0000000000001001
5	0000000000000101
15	0000000000001111
17	0000000000010001
overall	00000000000????1
The last line of the table indicates which bit positions are always 0, always 1, or take on both values in the sequence. Note that 12 of the 16 bits are persistent. (Good random sequences will have no persistent bits, but the converse is not necessarily true. For example, the sequence defined by A = 1, B = 1, C = 64000, and S = 0 has no persistent bits, but it's also not random: it just counts from 0 to 63999 before repeating.) Note that a sequence does not need to return to the seed: with A = 2, B = 0, C = 16, and S = 2, the sequence goes 2, 4, 8, 0, 0, 0, ....



Input
There are from one to sixteen datasets followed by a line containing only 0. Each dataset is a line containing decimal integer values for A, B, C, and S, separated by single blanks.


Output
There is one line of output for each data set, each containing 16 characters, either '1', '0', or '?' for each of the 16 bits in order, with the most significant bit first, with '1' indicating the corresponding bit is always 1, '0' meaning the corresponding bit is always 0, and '?' indicating the bit takes on values of both 0 and 1 in the sequence.


Sample Input
2 5 18 3
1 1 64000 0
2 0 16 2
256 85 32768 21845
1 4097 32776 248
0
Sample Output
00000000000????1
????????????????
000000000000???0
0101010101010101
0???000011111???
*/