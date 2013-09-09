#include <iostream>
using namespace::std;

int main()
{
	int m,n;
	cin >> m;
	while(m--)
	{
		int i,l=0,a;
		cin >> n;
		for(i=0;i<n;i++)
		{
			cin >> a;
			l+=a;
		}
		if(l==0)
			cout << "Equilibrium\n";
		if(l>0)
			cout << "Right\n";
		if(l<0)
			cout << "Left\n";
	}
	return 0;
}
/*
 Problem description
 Ever since you started studying, your whole family have been expecting you to know the answers to a whole lot of difficult questions. What is wrong with my computer? What is the name of Prince Harry's new girlfriend? Have you seen my new pants? Your grandfather has just found a new problem for you, and you are yet again under the pressure of finding the answers to one of life's most fundamental questions. You are given a 20 meter long lever balanced exactly on the middle by a massless support. A number of weights are applied to the lever. You need to figure out which side will drop, if any. Being such a brilliant mind, you immediately notice that each of the weights will contribute to the total torque applied on the lever, and that this will determine the answer. The torque from a single weight is determined by
 τ = m x d (1)
 where <τ is the total torque applied, m is the mass of the weight and d is its distance from the center. The lever's angular acceleration can then be found by the equation
 α = τ / I (2)
 where α is the angular acceleration and I is the lever's moment of inertia. The moment of inertia is given by the function
 I = ∫r2dm (3)
 where r is the perpendicular distance to the axis of rotation. 
 
 
 Input
 The first line of input contains a single number T, the number of test cases to follow. Each test case starts with a line containing N, the number of weights in the test case. This is followed by a line containing N numbers, W1 W2 ... WN the locations of the N weights. 
 
 
 Output
 For each test case, output one line containing Left if the weight tips to the left, Right if the weight tips to the right or Equilibrium if the weight does not tip to any of the sides.
 
 
 Sample Input
 3
 3
 -2 0 2
 1
 4
 4
 4 -2 0 -3
 Sample Output
 Equilibrium
 Right
 Left
*/