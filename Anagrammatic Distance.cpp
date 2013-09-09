#include <iostream>
#include <cmath>
using namespace::std;

int main()
{
	long n;
	while(cin >>n&&n)
	{
		int i,j,l=1;
		getchar();
		for(i=0;i<n;i++)
		{
			char a[50]={0},b[50]={0};
			int c[50]={0},d[50]={0},num=0;
			gets(a);
			gets(b);
			for(j=0;j<strlen(a);j++)
				c[a[j]-'a']++;
			for(j=0;j<strlen(b);j++)
				d[b[j]-'a']++;
			for(j=0;j<26;j++)
				num+=abs(c[j]-d[j]);
			printf("Case #%d:  %d\n",l++,num);
		}
	}
	return 0;
}
/*
 在求两个单词a和b的anagrammatic距离时,去掉这两个单词的某些字母后,单词a中剩余字母任意重排顺序,看是否是单词b的剩余字母组成的单词.
 因此,实际上只需对单词a中的每个字母x扫描单词b,如果能找到相同的字母,则字母x可以保留,否则不保留.但要注意,
 由于在单词中同一个字母可能出现多次,所以需要用数组记录每个字母是否保留.
 还可以将两个字符串中各字母出现的次数统计后求相应差,并对这些差求和.和上面程序效率一样.应该还可以用最长公共子序列(LCS)来求解
*/
/*
 Problem description
 Two words are said to be anagrams of each other if the letters from one word can be rearranged to form the other word. For example, occurs is an anagram of succor; however, dear is not an anagram of dared (because the d appears twice in dared, but only once in dear). The most famous anagram pair (in English) is dog and god.
 The anagrammatic distance between any two words is the minimum number of letters which must be removed so that the remaining portions of the two words become anagrams. For example, given the words sleep and leap, we need to remove a minimum of three letters --- two from sleep and one from leap --- before what's left are anagrams of each other (in each case, lep). With words such as dog and cat, where the two have absolutely no letters in common, the anagrammatic distance is an extreme (explicitly 6) since all the letters need to be removed. (Here, a word is always an anagram of itself.)
 
 You must write a program to calculate the anagrammatic distance between any two given words.
 
 
 Input
 The first line of the input will contain a positive integer value N (less than 60,000) indicating the number of cases. Each case will consist of two words, possibly empty, each given on a single line (for a total of 2N additional lines).
 Although they may have zero length, the words are simple --- the letter are all lowercase and are taken from the usual twenty-six letter English alphabet (abcdefghijklmnopqrstuvwxyz). The longest word is pneumonoultramicroscopicsilicovolcanoconiosis.
 
 
 Output
 The output should consist of the case number and the anagrammatic distance, formatted as shown. There are two spaces after the colon.
 
 Sample Input
 4
 crocus
 succor
 dares
 seared
 empty
 
 smell
 lemon
 Sample Output
 Case #1:  0
 Case #2:  1
 Case #3:  5
 Case #4:  4
*/