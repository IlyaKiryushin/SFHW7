#pragma once
class IntArray
{
private:
	int _length;
	int* _data;
public:
	IntArray() = default;
	IntArray(int length);
	IntArray(const IntArray& other);
	~IntArray()
	{
		delete[] _data;
	}
	void FormArray();
	void show();
	void erase();
	int& operator[] (int index);
	int getLength() const { return _length; }
	void resize(int newLenght);
	void Insert(int value, int index);
	void insertAtBeginning(int value) { Insert(value, 0); }
	void insertAtEnd(int value) { Insert(value, _length); }
	void Remove(int index);

};
