#include <iostream>
#include <exception>
#include "IntegerArray.h"
#include <new>
#include <cassert>
#include <algorithm>
#include <string>


using namespace std;

int main()
{
	int index;
	cout << "Enter the size of the array:" << endl;
	cin >> index;


	try
	{
		IntegerArray IntArray(index);

		for (int i = 0; i < index; ++i)
			IntArray[i] = i + 1;
		cout << "Array filled in" << endl;

		while (true) // �������� � ��������
		{
			string input = "";
			int operation = 0;
			cout << "Select operation on the array: 1 - print, 2 - insert, 3 - get size, 4 - find the value, 5 - end" << endl;
			cin >> input;

			try
			{
				operation = stoi(input); // ����������� ��������� ���������� � ����� �����, ��������� ����������
				if (operation <= 0 || operation > 5)  // �������� ������ ����
				{
					cout << "Try again. Only displayed numbers from the menu are allowed" << endl;
				}
			}
			catch (invalid_argument& e) // ���� ��������� ����������
			{
				cout << e.what() << endl;
				cout << "Try again. Only displayed numbers from the menu are allowed" << endl;
			}
			catch (out_of_range& e)
			{
				cout << e.what() << endl;
				cout << "Try again. Only displayed numbers from the menu are allowed" << endl;
			}

			if (operation == 1)  // ������ ��������� �������
			{
				IntArray.printArray();
			}
			if (operation == 2) // ������� �������� � ������
			{
				int val, ind;
				cout << "Please type the value: " << endl;
				cin >> val; // �������� ��������
				cout << "Please type the index: " << endl;
				cin >> ind; // ������ ��� �������
				IntArray.insert(val, ind);
			}
			if (operation == 3) // ������ �������
			{
				cout << "Size of the array: " << IntArray.getSize() << endl;
			}
			if (operation == 4) // ����� ��������� ������� � ������� ���������
			{
				int val;
				cout << "Please type the value you are looking for in the array: " << endl;
				cin >> val; // ���� �������� ��������
				IntArray.GetIndex(val);
			}
			if (operation == 5)  // ���������� ������
			{
				cout << "End of the program" << endl;
				break;
			}
		}
	}

	catch (bad_alloc& ba) // �������� ���������� �� ������������� �������
	{
		cout << "Bad array allocation caught" << endl;
		cout << ba.what() << endl;
	}

	catch (const exception& e) // �������� ���������� ������ exception
	{
		cout << e.what() << endl;
	}
	return 0;
}