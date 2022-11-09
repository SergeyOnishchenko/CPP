#pragma once
#include <iostream>
#include <exception>
#include <climits>

using namespace std;

class BadIntegerArray : public exception
{
private:
	// int _val;

public:
	// BadIntegerArray(int val) : _val(val) {}

	virtual const char* what() const noexcept override
	{
		return "Array length exception";
	}
};

class IntegerArray
{
private:
	int _size{};
	int* int_data{};

public:
	IntegerArray(int size) : _size(size)  // конструктор объекта с проверкой длины массива и генерации исключений
	{
		if (size < 0)
		{
			cout << "Array length is less 0" << endl;
			throw BadIntegerArray();
		}
		if ((sizeof(int) * size) >= INT_MAX) // проверка на максимальный размер массива
		{
			cout << "Array length is greater than integer max" << endl;
			throw BadIntegerArray();
		}

		int_data = new int[size] {0};  // создание и инициализаци€ массива нулевыми значени€ми после проверки допустимых значений

		cout << "Array constructed" << endl;
	}

	~IntegerArray()
	{
		delete[] int_data;
		cout << "Array destructed" << endl;
	}

	void GetIndex(int value) // метод поиска значений в массиве
	{
		_size = getSize();
		int count = 0;
		for (int i = 0; i < _size; ++i)
			if (int_data[i] == value)
			{
				count += i;
				cout << "Index " << i << " = " << value << endl;
			}
		if (count == 0)
		{
			cout << "No elements have finded" << endl;
		}
	}

	int& operator[](int index)
	{
		if (index <= 0 && index > _size)
		{
			cout << "Index is out of range" << endl;
			throw BadIntegerArray();
		}
		return int_data[index];
	}
	int getSize() const
	{
		return _size;
	}

	void insert(int value, int index)
	{
		if (index <= 0 || index > _size)
		{
			cout << "Cannot be inserted" << endl;
			throw BadIntegerArray();
		}

		int new_size = _size + 1;
		int* new_int_data = new int[new_size];

		for (int before = 0; before < index; ++before)
			new_int_data[before] = int_data[before];

		new_int_data[index] = value;  // ¬ставка нового элемента в новый массив

		for (int after = index; after < _size; ++after) //  опировани€ оставшихс€ элементов массива
			new_int_data[after + 1] = int_data[after];

		delete[] int_data;  	// Delete the old array, and use the new array instead
		int_data = new_int_data;  // Use the new array instead of the old one
		++_size; // size is increased +1

		cout << "New element with the Index: " << index << " and the Value: " << value << " inserted" << endl;
	}

	void printArray()
	{
		for (int i = 0; i < _size; ++i)
		{
			cout << int_data[i] << " ";
		}
		cout << endl;
		cout << "All elements of the array listed " << endl;
		cout << "Size of the array is " << getSize() << endl;
	}
};