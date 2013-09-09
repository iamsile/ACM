#include <iostream>
using namespace::std;

int main()
{
	float a,b,c;
	while(scanf("%f%f%f",&a,&b,&c)!=EOF)
	{
		if(a<b&&a<c)
			cout << "bound\n";
		else 
			cout << "scattering\n";
	}
	return 0;
}
/*
 Problem description
 Quantum Mechanics is one of the two most important theories to come out of the 20th century, the other one being General Relativity. Everything we've seen indicates that Quantum Mechanics is a correct theory. Of course it's a strange theory that no one quite understands yet. But nonetheless, it seems correct.
 The central equation of quantum is the Schrodinger Equation. The solutions of that equation are called wave functions and they describe the state of a particle. A particle can be in a bound state, or a scattering state. In a bound state, the potential energy at some barrier is greater than the energy of the particle, while a scattering state is where the energy of the particle is greater than the potential energy at the barrier. (This is a horribly simplified view, but oh well.)
 
 In the case of a number of potentials it's easy to determine if the particle will be in a bound or scattering state. If the energy of a particle is smaller than the value of the potential energy at infinity, and -inifinity then the particle is in a bound state. Otherwise, it's in a scattering state. (Again, this is simplified).
 
 In this problem, you get to tell if a particle is in a bound state or a scattering state. 
 
 
 Input
 Each line of input will have 3 numbers, separated by spaces. The first number is the energy of the particle. The next two are the values of the potential energy at plus or minus infinity. The energy will never be 0 (it's not a very interesting particle if it has no energy, now is it?)
 
 Output
 Output the word "bound" or "scattering" depending on whether the particle is in a bound state or scattering state.
 
 Sample Input
 45 300.000 3400.000
 -10.034 0 0
 45 -300.34 3004.00
 Sample Output
 bound
 bound
 scattering
*/