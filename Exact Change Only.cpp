#include <iostream>
using namespace std;

int main()
{
    double n;
    int a,b,c,d,as,bs,cs,ds,m,save;
    for(;cin>>n>>as>>bs>>cs>>ds;)
	{
        save=m=(int)(n*100+0.01);
        for(d=0;d<=ds;d++)
            for(c=0;c<=cs;c++)
                for(b=0;b<=bs;b++)
                    for(a=0;a<=as;a++)
                        if(a*25+b*10+c*5+d==save)
                            goto over;
	over:   if(d > ds)
		cout<<"NO EXACT CHANGE"<<endl;
	else
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    return 0;
} 
/*#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
//Solution type 
typedef enum {
    UNSOLVED, NOSOLUTION, SOLVED
} solution_state_t;
// coin set 
typedef struct {
    int quarters;
    int dimes;
    int nickels;
    int pennies;
} coinset_t;

#define SUCCESS 0
#define FAILURE -1

#define CALC_CENTS(a) ((25*((a).quarters))+ \
(10*((a).dimes))+ \
(5*((a).nickels))+ \
((a).pennies))

solution_state_t CalculateSolution(coinset_t available_coins, 
                  int target_cents, 
                  coinset_t *solution);

int AllocateCoin(coinset_t *available_coins, 
			 int target_cents, 
			 coinset_t *solution);

int main ()
{
    int items;
    while (1)
    {
        solution_state_t SolutionState;
        coinset_t AvailableCoins, Solution;
        int TargetCents, target_dollars, target_cents;
		// Read the input data 
        items = scanf("%d.%d %d %d %d %d", 
					  &target_dollars, 
					  &target_cents,
					  &AvailableCoins.quarters,
					  &AvailableCoins.dimes,
					  &AvailableCoins.nickels,
					  &AvailableCoins.pennies);
		//Check to see if we're done 
        if (items != 6) break;
		 // Initialize the solution 
        memset(&Solution,0,sizeof(Solution));
		// Establish the target (in cents) 
        TargetCents = (target_dollars * 100) + target_cents;
		//If the problem is probably solvable, calculate the solution 
        if (CALC_CENTS(AvailableCoins) >= TargetCents)
        {
			// First try it with all the quarters 
            SolutionState = CalculateSolution(AvailableCoins, 
                                              TargetCents, 
                                              &Solution);
			// Now try it without allocating the max # of quarters 
            if ((SolutionState != SOLVED) && (TargetCents >= 25)) 
            {
                int max_quarters, quarters_removed;
				 // Reset the solution and available coins
                memset(&Solution,0,sizeof(Solution));
				// First, what is the max # of quarters that could be used?
                max_quarters = (TargetCents / 25);
                if (max_quarters > AvailableCoins.quarters)
                {
                    max_quarters = AvailableCoins.quarters;
                }
                if (max_quarters == 0) break;
				//How many quarters should be removed? 
                quarters_removed = AvailableCoins.quarters - (max_quarters - 1);
				//Now, try the solution with just less than max quarters 
                AvailableCoins.quarters -= quarters_removed; 
                SolutionState = CalculateSolution(AvailableCoins, 
                                                  TargetCents, 
                                                  &Solution);
                AvailableCoins.quarters -= quarters_removed; 
            }
        }
        else
        {
           SolutionState = NOSOLUTION;
        }
		// Display the solution 
        if (SolutionState == SOLVED) 
        {
            printf("%d %d %d %d\n",
                   Solution.quarters, Solution.dimes, Solution.nickels, Solution.pennies);
        }
        else  //NOSOLUTION or UNSOLVED 
        {
            printf("NO EXACT CHANGE\n");
        }
    }
	return 0;
}

solution_state_t CalculateSolution(coinset_t available_coins,int target_cents,coinset_t *solution)
{
	// If we've found a solution, return SOLVED 
    if (CALC_CENTS(*solution) == target_cents)
    {
        return SOLVED;
    }
	// If we can't allocate the next coin, we've hit a NOSOLUTION 
	if (AllocateCoin(&available_coins, target_cents, solution) == FAILURE)
    {
        return NOSOLUTION;
    }
	// Otherwise, call ourselves recursively 
    return CalculateSolution(available_coins, target_cents, solution);
}

int AllocateCoin(coinset_t *available_coins, int target_cents, coinset_t *solution)
{
    int needed_cents;
    needed_cents = target_cents - CALC_CENTS(*solution);
    if (needed_cents >= 25 && available_coins->quarters > 0)
    {
        --available_coins->quarters;
        ++solution->quarters;
    }
    else if (needed_cents >= 10 && available_coins->dimes > 0)
    {
        --available_coins->dimes;
        ++solution->dimes;
    }
    else if (needed_cents >= 5 && available_coins->nickels > 0)
    {
        --available_coins->nickels;
        ++solution->nickels;
    }
    else if (available_coins->pennies > 0)
    {
        --available_coins->pennies;
        ++solution->pennies;
    }
    else
    {
        return FAILURE;
    }
    return SUCCESS;
}*/
/*
 Problem description
 Boudreaux reached over and shook awake Thibodeaux, who had dozed off somewhere in New Mexico. "Where we at?" Thibodeaux groggily yawned.
 "Not in Vegas, I gua-ran-tee, but could you get my knapsack?" Boudreaux asked, gesturing to the worn, leather backpack in the back seat of their cherry red Ford Miata.
 
 "Why, is there a problem?"
 
 "Just hand me my knapsack, problem or not."
 
 Thibodeaux complied, glancing up as Boudreaux slowed the car to a stop in a line of vehicles approaching a toll booth. "$1.65 -- Exact change only," Thibodeaux read the yellow sign on the front of a small wooden building occupied by a lone toll booth operator. "I have to get $1.65 in exact change?" Thibodeaux asked, digging through the knapsack, "all I have are ten quarters, four dimes, and three pennies. I don't have any nickels . . ."
 
 "Just give me five of the quarters and the four dimes," Boudreaux replied, holding out his hand.
 
 "Oh yeah," Thibodeaux said, handing over the coins, "that does add up to $1.65. I wish there were an easy way to figure out if you have an exact monetary amount, given a set of coins."
 
 "Hmmm," Boudreaux shrugged, "sounds like a good programming problem."
 
 
 
 
 Input
 Input to this problem will consist of a (non-empty) series of up to 100 data sets. Each data set will be formatted according to the following description, and there will be no blank lines separating data sets.
 A single data set has 1 component:
 
 Start line - A single line:
 A B C D E
 
 where:
 A: (0.01 ≤ A ≤ 5.00) is a decimal number (to two decimal places) of a monetary amount.
 B: (0 ≤ B ≤ 100) is an integer number of quarters (one quarter = $0.25).
 C: (0 ≤ C ≤ 100) is an integer number of dimes (one dime = $0.10).
 D: (0 ≤ D ≤ 100) is an integer number of nickels (one nickel = $0.05).
 E: (0 ≤ E ≤ 100) is an integer number of pennies (one penny = $0.01).
 
 
 
 Output
 For each data set, there will be exactly one line of output. If there exists one or more subsets of the given coins whose values add up to the given monetary amount exactly, the output will be a single line in the form:
 A B C D
 where A is the number of quarters, B is the number of dimes, C is the number of nickels, and D is the number of pennies, for the subset with the fewest number of coins. Otherwise, the output will be a single line with the statement:
 NO EXACT CHANGE
 
 
 
 Sample Input
 0.45 2 1 1 4
 0.75 3 7 1 75
 Sample Output
 NO EXACT CHANGE
 3 0 0 0
*/