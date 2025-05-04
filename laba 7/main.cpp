#include <iostream>	
using namespace std;

#include "List.h"


int main() {
	List list;

	list.Show();

	cout << endl;


	for (size_t i = 0; i < 10; i++)
	{
		list.PushBack(i);

	}

	list.Show();

	list.PopBack();

	list.PopFront();

	list.Remove(3);
	list.Show();

	int value = 1;

	if (list.Find(value))
	{
		cout << "List has " << value << endl;
	}
	else
	{
		cout << "Has nothing " << endl;
	}

	if (list.isEmpty())
	{
		cout << "List is EMPTY! " << endl;
	}

	cout << "Size of the list = " << list.Size() << endl;
}

