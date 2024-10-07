// Vector20Main.cpp

#include <iostream>
#include <iomanip>
#include "Vector20.h"
using namespace std;

// printing values in a Vector20 object
void print_Vector20(Vector20<int>);

int main(){
	Vector20<int> myvec;

	for (int i = 1; i <= 25; i++)
	{
		myvec.push_back(i * 11); // entering 25 values into myvec;
	}

	print_Vector20(myvec); // showing contents of myvec

	// asking for target index and how many times an erase is to happen
	// at this index;


	int target;
	int howmany;
	cout << "Enter index of element to erase [0 - " << myvec.size() - 1 << "]: ";
	cin >> target;
	cout << endl;
	cout << "Erase at this index how many times [0 - " << myvec.size() - target << "]: ";
	cin >> howmany;
	cout << endl;
	for (int i = 1; i <= howmany; ++i)
	{
		myvec.erase(target);
		print_Vector20(myvec);
		cout << endl;
	}
	cout << endl;

	// asking for a target index and how many times value 999 is
	// to be inserted at this index

	cout << "Enter index of element to insert 999 [0 - " << myvec.size() - 1 << "]: ";
	cin >> target;
	cout << endl;
	cout << "Insert at this index how many times [0 - " << myvec.size() - 1 << "]: ";
	cin >> howmany;
	cout << endl;
	for (int i = 1; i <= howmany; ++i)
	{
		myvec.insert(target,999);
		print_Vector20(myvec);
		cout << endl;
	}


	return 0;
}

void print_Vector20(Vector20<int> vec)
{
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl
		 << endl;
}
