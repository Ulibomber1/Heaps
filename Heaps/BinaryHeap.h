#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <cassert>
#include <iostream>
#include "Vector.h"
using namespace std;

template <typename T>
class BinaryHeap
{
public:
	//constructor: empty heap with capacity 100+1
	BinaryHeap(int capacity = 100)
		: theheap(capacity + 1), theSize(0)
	{}

	//constructor: initialize with any vector:
	//will convert Vector to Heap;
	BinaryHeap(const Vector<T>& items)
		: theheap(items.size() + 10), theSize(items.size())
	{
		// copy items to heap; leave field at index 0 unoccupied
		for (int i = 0; i < items.size(); ++i)
			theheap[i + 1] = items[i];
		buildHeap();
	}

	bool empty() const
	{
		return theSize == 0;
	}

	// Find the smallest item in the heap
	const T& findmin() const
	{
		assert(!theheap.empty());
		return theheap[1];
	}

	// Insert item x, allowing duplicates;
	void insert(const T& x)
	{
		if (theSize == theheap.size() - 1)
			theheap.resize(theheap.size() * 2);
		int hole = theSize + 1; // index of new field
		theSize++;

		T copy = x;
		// unused position 0 to hold new value until proper place is found
		theheap[0] = copy;

		// moving up parents as long as parent has larger value than x; also called "percolate up"
		for (; x < theheap[hole / 2]; hole /= 2)
			theheap[hole] = theheap[hole / 2];
		theheap[hole] = theheap[0];// Drop new value into place
	}

	//remove the minimum item
	void deleteMin()
	{
		assert(!theheap.empty());
		theheap[1] = theheap[theSize];
		theSize--;
		percolateDown(1);
	}
	// Removes the minimum item AND places it in output parameter minItem;
	void deleteMin(T& minItem)
	{
		assert(!theheap.empty());
		minItem = theheap[1];
		theheap[1] = theheap[theSize];
		theSize--;
		percolateDown(1);
	}

	void makeEmpty()
	{
		theSize = 0;
	}

	void print_heap()
	{
		cout << endl;
		if (empty())
			cout << "empty heap";
		else
			print_heap(1, 0);
		cout << endl;
	}


private:
	int theSize;
	Vector<T> theheap;

	void buildHeap()
	{
		for (int i = theSize / 2; i > 0; --i)
			percolateDown(i);
	}

	void percolateDown(int hole)
	{
		int child;
		T tmp = theheap[hole];

		for (; hole * 2 <= theSize; hole = child)
		{
			child = hole * 2;
			if (child != theSize && theheap[child + 1] < theheap[child])
				++child;

			if (theheap[child] < tmp)
				theheap[hole] = theheap[child];

			else
				break;
		}
		theheap[hole] = tmp;
	}

	void print_heap(int index, int offset)
	{
		if (index > theSize)
			return;
		for (int i = 1; i <= offset; i++)
			cout << "..";
		cout << theheap[index] << endl;
		print_heap(2 * index, offset + 1);
		print_heap(2 * index + 1, offset + 1);
	}

};
#endif
