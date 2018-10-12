#include <iostream>
#include "sequence4.h"
#include "node2.h"

using namespace std;
using namespace CISP430_A3;

int main()
{
	cout << "Test" << endl;
	sequence<int> mySequence; 
	for (int i = 0; i < 10; i++)
	{
		mySequence.insert(i);
		cout << "The current is " << mySequence.current() << endl;
	}
	cout << "Reseting cursor to the beginning" << endl;
	mySequence.start();
	cout << "All the numbers, in order," << endl;
	while (mySequence.is_item())
	{
		cout << mySequence.current() << endl;
		mySequence.advance();
	}
	system("PAUSE");
	return 0;
}