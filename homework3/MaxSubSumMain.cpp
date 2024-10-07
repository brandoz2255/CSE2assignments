#include <iostream>
#include "Random.h"
#include "MaxSubSum.h"
#include "List.h"


using namespace std;


int main()
{
	List<int> mynums;
	char yesno;
 
	rand_seed();
	
		int k = rand_int(3, 6);
		for (int i = 1; i <= 25; ++i)
		{
			int rno = rand_int(1, 1000);
			if (rand_int(1, 10) <= k)
				rno = -rno;

			mynums.push_back(rno);
		}
	
		cout << "Here are 25 numbers ... " << endl;
		printList(mynums);

		List<int> maxSub = maxSubSum(mynums);

		cout << "Max subsequence: ";
		printList(maxSub);


	return 0;
}
