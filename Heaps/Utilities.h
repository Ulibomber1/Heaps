#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <iostream>
#include "Vector.h"
//#include "List.h"
using namespace std;

template <typename T>
void print_Vector(const Vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	return;
}


/*
template <typename T>
void print_List(const List<T> lst)
{
	typename List<T>::const_iterator itr;
	for (itr = lst.begin(); itr != lst.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	return;
}
*/

#endif
