#include <iostream>
#include "BinaryHeap.h"
#include "Random.h"
using namespace std;

int main()
{
	BinaryHeap<int> myheap;
	Vector<int> inputs;

	rand_seed();
	random_vector(7, 1, 250, inputs, 0);

	for (int i = 0; i < inputs.size(); i++)
		myheap.insert(inputs[i]);

	cout << endl << "This is my heap: " << endl;
	myheap.print_heap();
	cout << endl;

	cout << endl << "Taking down my heap... " << endl;
	int themin;
	while (!myheap.empty())
	{
		myheap.deleteMin(themin);
		cout << "Deleting minimum value " << themin << endl;
		myheap.print_heap();
		cout << endl;
	}

	return 0;
}