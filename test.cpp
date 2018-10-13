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
		mySequence.attach(i);
	}
	mySequence.start();
	for (int i = 0; i < 9; i++)
	{ 
		cout << mySequence.current() << endl;
		mySequence.advance();
	}
	
	if (!mySequence.is_item()) {
		cout << "There is no current item." << endl;
	}
	else {
		cout << "The current item is " << mySequence.current() << endl;
	}

	cout << "attaching just before end" << endl;	
	mySequence.attach(69);
	mySequence.start();
	while (mySequence.is_item())
	{
		cout << mySequence.current() << endl;
		mySequence.advance();
	}
	system("PAUSE");
	return 0;
}