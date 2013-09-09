#include<cstdio>
__int64 n,m,k;
__int64 Gcd( __int64 a, __int64 b ) {
	__int64 t;
	while( b ) {
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main(){
	int t,w; scanf( "%ld", &t );
	for( int c=1; c<=t; ++c ) {
		scanf( "%I64d %I64d", &n, &m );
		k=m;
		for( w=1; n>k; k*=m, ++w );
		k*=w;
		m = Gcd( k, n );
		k/=m; n/=m;
		printf( "Case %ld: %I64d/%I64d\n", c,k,n );
	}
    return 0;
}
/*
 Problem Description
 hh is a Board Game hobbyist, he often plays Board Game such as Catan, Carcassonne, The Werewolves, A song of ice and fire with friends. 
 To play the games, we need some dices, and these dices are very unusual. Maybe with eight or twelve sides.
 
 
 hh plays with N friends today(including himself). They'll choose one person to be the judge. But the problem is: there is only a M-sided dice. How to pick a judge with the dice, so that everyone has equal probability of being chosen (the probability should always be 1/N)?
 hh has an idea here:
 1)Get x
 Decide rolling the dice x times. x is the smallest integer to make Mx larger than or equal to N.
 
 2)Players choose sequences
 Each player chooses a sequence with x elements (1~M).
 For example, a 6-sides dice and x equal to 3, hh will gets sequence [5 4 6]. Players' sequences should be different from each other.(such as [6 4 5] is different from [5 4 6])
 
 3)Pick the judge
 Roll the dice for x times, we can get a result sequence, if someone has the same sequence as the result, he will be the judge; otherwise, repeat 1)-3), until the judge is chosen.
 
 It's a bigger project, hh wants know the expected number of times we will need to throw dice to determine the judge.
 
 
 Input
 The first line is a number T(1<=T<=100), which represents the number of cases. The next T blocks following are the cases.
 Each case contains two integer N , M(2<=N<=109, 2<=M<=20)
 
 
 Output
 For each case, output the number of case and expected number of rolling as an irreducible fraction in the following form: "a/b" (as shown in the sample output)
 
 
 Sample Input
 2
 3 2
 9 3
 
 
 Sample Output
 Case 1: 8/3
 Case 2: 2/1
*/