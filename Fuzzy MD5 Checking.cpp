#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int i,k,t,n;
    while (cin >> t >> n) {
        int num1=0,num2=0;
        while (t--) {
            char a[200],b[200];
            int lab=1,flag=1;
            cin >> a >> b;
            k=strlen(a);
            for (i=0; i<n; i++)
                if (a[i]!=b[i]) {
                    lab=0;
                    break;
                }
            for (i=k-n; i<k; i++)
                if (a[i]!=b[i]) {
                    flag=0;
                    break;
                }
            if (lab&&flag)
                num1++;
            if (!strcmp(a, b))
                num2++;
        }
        cout << num1 << ' ' << num2 << '\n';
    }
    return 0;
}
/*
 Problem description
 Background:
 
 MD5 is a fast algorithm that takes an arbitrarily long message and computes a 128 bit "message digest." It can be used to verify integrity of messages or of files. The distributor of files computes the MD5 checksums and then distributes the files and checksums. Who ever downloads the files can then verify the checksum to discover if the download was successful or not. Unix machines often include the nifty program `md5sum' that will compute and verify checksums. 
 
 Recently, Jenna has gotten into downloading music of taper friendly bands, such as the Grateful Dead, Umphrey's McGee, moe., Pearl Jam, etc. Concert files from these bands can be downloaded and include MD5 checksums to verify the (likely) integrity. Every once in a while, though, she gets an MD5 sum file that md5sum can't parse. She has to check those files manually by running md5sum and comparing the results to given check sums. She notices that she only checks n digits from the front and back to verify the checksum. This, of course, isn't perfect. She wonders about the accuracy of this method and has asked you to write a program to help explore the issue. 
 
 Input
 Input is a series of test cases. Each test case starts with two integers, T and n. T pairs of lines then follow. Each pair is the MD5sum found in the check file and the MD5sum computed by `md5sum'. You may assume that n will never exceed 10. 
 
 Output
 For each test case, print a line given the number of files that are "correct" by checking only the first and last n characters followed by the number of files that are correct by checking the entire checksum. 
 
 Sample Input
 1 1
 52e000512f2d6e360bc4efe7fad69f01
 52e000512f2d6e360bc4efe7fad69f01
 1 1
 52e000512f2d6e360bc4efe7fad69f01
 52e000512f2d6e360bc4efe7fad69ff1
 1 4
 52e000512f2d6e360bc4efe7fad69f01
 52e000512f2d6e360bc4efe7fad69e01
 Sample Output
 1 1
 1 0
 0 0
*/