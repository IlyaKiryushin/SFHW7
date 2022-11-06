#include "IntArray.h"
#include "bad_range.h"
#include "bad_length.h"
#include <iostream>
#include <exception>
int main()
{
	try
	{
		IntArray array1(10);
		array1.FormArray();
		array1.show();
		array1.resize(8);
		array1.Insert(7, 5);
		array1.Remove(3);
		array1.insertAtEnd(30);
		array1.insertAtBeginning(40);
		array1.show();
		IntArray array2(array1);
	}
	catch (bad_length& e)
	{
		std::cout << e.what();
	}
	catch (bad_range& e)
	{
		std::cout << e.what();
	}
	return 0;
}