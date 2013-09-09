#include <iostream>
#include <string>
using namespace::std;

int main()
{
    string a;
	int i;
    while(cin >> a)
    {
		i=a.find('.');
		cout << "server: ";
		while(i--&&a[i]!='/')
			cout << a[i];
		cout << '\n';
    }
    return 0;
}
/*
 Problem description
 Users of computers frequently enter URLs (Uniform Resource Locators) in the form
 
 protocol://server.network
 For example, in the URL
 
 http://www.monkey.donkey.zebra.com
 the protocol is "http", the server is "www", and the network is "monkey.donkey.zebra.com". For purposes of this problem, the protocol and server are alphanumeric strings, whereas the network is an alphanumeric string that may also contain periods (however, the URL cannot end with a period or contain two consecutive periods).
 
 
 
 Input
 Each line of the input contains a URL in the format specified above. No line will be longer than 80 characters. The input is terminated by end-of-file.
 
 Output
 Each line of input will give rise to one line of output, consisting of the word "server", followed by a colon and one blank space, and the server from the corresponding line of input.
 
 Sample Input
 http://www.monkey.donkey.zebra.com
 ftp://newton.cs.colorado.edu
 Sample Output
 server: www
 server: newton
 */
