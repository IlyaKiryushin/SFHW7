#include "IntArray.h"
#include "bad_length.h"
#include "bad_range.h"
IntArray::IntArray(int length)
{
	if (length < 0)
	{
		throw bad_length();
	}
	{
		this->_length = length;
		_data = new int[length];
	}
}
void IntArray::FormArray()
{
	for (int i = 0; i < _length; i++)
	{
		_data[i] = i;
	}
}
void IntArray::show()
{
	for (size_t i = 0; i < _length; i++)
	{ 
		std::cout << _data[i] << '\n';
		std::cout << '\n';
	}
		
}
IntArray::IntArray(const IntArray& other)
{
	_length = other._length;
	if (other._length <= 0)
	{
		throw bad_length();
	}
	_data = new int[other._length];
	for (size_t i = 0; i < other._length; i++)
	{
		_data[i] = other._data[i];
	}
}
void IntArray::erase()
{
	delete[] _data;
	_data = nullptr;
	_length = 0;
}
int& IntArray::operator[](int index)
{
	if (index <0 || index>_length)
	{
		throw bad_range();
	}
	return _data[index];
}
void IntArray::resize(int newLength)
{
	if (newLength == _length)
	{
		return;
	}
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* data{ new int[newLength] };
	if (_length > 0)
	{
		int elementsToCopy{ (newLength > _length) ? _length : newLength };
		for (size_t index{ 0 }; index < elementsToCopy; ++index)
		{ 
			data[index] = _data[index];
		}		
	}
	delete[] _data;
	_data = data;
	_length = newLength;
}
void IntArray::Insert(int value, int index)
{
	if (index < 0 || index > _length)
	{
		throw bad_range();
	}
	int* data{ new int[_length + 1] };
	for (size_t i{ 0 }; i < index; ++i)
	{
		data[i] = _data[i];
	}
		data[index] = value;
	
	for (int j{ index }; j < _length; ++j)
		{
			data[j + 1] = _data[j];
		}
	delete[] _data;
	_data = data;
	++_length;
}
void IntArray::Remove(int index)
{
	if (index < 0)
	{
		throw bad_range();
	}
	if (_length == 1)
	{
		erase();
		return;
	}
	int* data{ new int[_length - 1] };
	for (size_t i{ 0 }; i < index; ++i)
	{
		data[i] = _data[i];
	}
	for (int j{ index + 1 }; j < _length; ++j)
	{
		data[j - 1] = _data[j];
	}	
	delete[] _data;
	_data = data;
	--_length;
}