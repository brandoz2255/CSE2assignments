// Algorithms 4 from Weiss, DSAAC++ textbook;
// computing of maximal subsum of a vector of positive and
// negative values;

#include <iostream>
#include "List.h"

using namespace std;

void printList(const List<int>& lst){
	
	for (List<int>::const_iterator itr = lst.begin(); itr != lst.end(); ++itr){
		cout << *itr << " ";
	}

	cout << endl;
		

}

// version of alg4 that collects max subsum values; 
List<int> maxSubSum(const List<int> &numbers)
{
	int maxSum = 0; // 0;
	int localsum = 0; // 0;
	List<int> maxSubList;
	List<int> tempList;
	int thisSum = 0;


	for (List<int>::const_iterator itr = numbers.begin(); itr != numbers.end(); ++itr){
		thisSum += *itr;
		tempList.push_back(*itr);

		if (thisSum > maxSum)
		{
			maxSum = thisSum;
			maxSubList = tempList;
		}

		else if (thisSum < 0)
		{
			thisSum = 0;
			tempList.clear();
		}
	}
	
	return maxSubList;
}





