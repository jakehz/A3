#include <iostream>
#include "sequence4.h"
#include "node2.h"

using namespace std;
using namespace CISP430_A3;

void print(sequence<double> myseq)
{
	if (myseq.is_item())
	{
		cout << "The current is " << myseq.current() << endl;
	}
	else {
		cout << "No current item." << endl;
	}
	myseq.start();
	while (myseq.is_item())
	{
		cout << myseq.current() << endl;
		myseq.advance();
	}
}

int main()
{

	 const size_t TESTSIZE = 30;
    
    sequence<double> test;

    // Within this function, I create several different sequences using the
    // items in these arrays:
    double items1[1] = { 30 };
    double items2[2] = { 10, 30 };
    double items3[3] = { 10, 20, 30 };
    
    size_t i;       // for-loop control variable

    // Build a sequence with three items 10, 20, 30, and remove the middle,
    // and last and then first.
    cout << "Using attach to build a sequence with 10,30." << endl;
    test.attach(10);
	test.attach(30);
    cout << "Insert a 20 before the 30, so entire sequence is 10,20,30." << endl;
    test.insert(20);
	print(test);
    cout << "Remove the 20, so entire sequence is now 10,30." << endl;
    test.start( );
    test.advance( );
    test.remove_current( );
    print(test);
    cout << "Remove the 30, so entire sequence is now just 10 with no cursor.";
    cout << endl;
    test.start( );
    test.advance( );
    test.remove_current( );
    print(test);
	
    cout << "Set the cursor to the start and remove the 10." << endl;
    test.start( );
    test.remove_current( );
	print(test);
	
    // Build a sequence with three items 10, 20, 30, and remove the middle,
    // and then first and then last.
    cout << "Using attach to build another sequence with 10,30." << endl;
    test.attach(10);
    test.attach(30);
    cout << "Insert a 20 before the 30, so entire sequence is 10,20,30." << endl;
    test.insert(20);
	print(test);
    cout << "Remove the 20, so entire sequence is now 10,30." << endl;
    test.start( );
    test.advance( );
    test.remove_current( );
	print(test);
    cout << "Set the cursor to the start and remove the 10," << endl;
    cout << "so the sequence should now contain just 30." << endl;
    test.start( );
    test.remove_current( );
	print(test);
    cout << "Remove the 30 from the sequence, resulting in an empty sequence." << endl;
    test.start( );
    test.remove_current( );
	print(test);

    // Build a sequence with three items 10, 20, 30, and remove the first.
    cout << "Build a new sequence by inserting 30, 10, 20 (so the sequence\n";
    cout << "is 20, then 10, then 30). Then remove the 20." << endl;
    test.insert(30);
    test.insert(10);
    test.insert(20);
    test.remove_current( );
	print(test);
    test.start( );
    test.remove_current( );
    test.remove_current( );

    // Just for fun, fill up the sequence, and empty it!
    cout << "Just for fun, I'll empty the sequence then fill it up, then\n";
    cout << "empty it again. During this process, I'll try to determine\n";
    cout << "whether any of the sequence's member functions access the\n";
    cout << "array outside of its legal indexes." << endl;
    for (i = 0; i < TESTSIZE; i++)
        test.insert(0);
    for (i = 0; i < TESTSIZE; i++)
        test.remove_current( );

    // All tests passed
    cout << "All tests of this third function have been passed." << endl; 	system("PAUSE");
	system("PAUSE");
	return 0;
}