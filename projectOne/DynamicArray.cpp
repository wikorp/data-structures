#include "DynamicArray.h"
#include <iostream>
#include <fstream>
using namespace std;

void DynamicArray::put_first(int value) {
	int* new_tab = new int[size + 1];

	new_tab[0] = value;
	for (int i = 1; i <= size; i++)
		new_tab[i] = tab[i - 1];

	delete[] tab;
	tab = new_tab;
	size++;
}

void DynamicArray::put_last(int value) {
	int* new_tab = new int[size + 1];
	
	for (int i = 0; i < size; i++) 
		new_tab[i] = tab[i];

	new_tab[size] = value;
	delete[] tab;
	tab = new_tab;
	size++;
}

void DynamicArray::put(int value, int index) { 
	if (index < 0 or index > size) {
		cout << "ERROR - BAD INDEX";
		return;
	}

	int* new_tab = new int[size + 1];

	for (int i = 0; i < index; i++) {
		if (i != size)
			new_tab[i] = tab[i];
	}

	new_tab[index] = value;
	
	for (int i = index; i < size; i++)
		new_tab[i + 1] = tab[i];

	delete[] tab;
	tab = new_tab;
	size++;
}

void DynamicArray::remove_first() {
	if (size == 0)
		return;

	int* new_tab = new int[size - 1];
	
	for (int i = 0; i < size - 1; i++)
		new_tab[i] = tab[i + 1];

	delete[] tab;
	tab = new_tab;
	size--;
}

void DynamicArray::remove_last() { 
	int* new_tab = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
		new_tab[i] = tab[i];

	delete[] tab;
	tab = new_tab;
	size--;
}

void DynamicArray::remove(int index) { 
	if (index < 0 or index >= size) {
		cout << "ERROR - BAD INDEX";
		return;
	}

	int* new_tab = new int[size - 1];

	for (int i = 0; i < index; i++)
		new_tab[i] = tab[i];

	for (int i = index; i < size - 1; i++)
		new_tab[i] = tab[i + 1];

	delete[] tab;
	tab = new_tab;
	size--;
}

int DynamicArray::get(int index) {
	if (index < 0 or index >= size) {
		cout << endl << "ERROR - BAD INDEX";
		return NULL;
	}
	return tab[index];
}

int DynamicArray::find(int value) {
	for (int i = 0; i < size; i++) {
		if (tab[i] == value)
			return i;
	}
	return NULL;
}

void DynamicArray::read() {
	cout << "Put number of elements" << endl;
	int n;
	cin >> n;
	int *new_tab = new int[n];

	cout << "Put elements" << endl;
	for (int i = 0; i < n; i++)
		cin >> new_tab[i];

	delete[] tab;
	tab = new_tab;
	size = n;
}

void DynamicArray::read_file(string file_path) { 
	int s, value;
	ifstream file;
	file.open(file_path);

	if (file.is_open())
	{
		file >> s;
		if (file.fail())
			cout << "File error - READ SIZE" << endl;
		else {
			int* new_tab = new int[s]; // co by bylo jakby tu nie byla dynamiczna - umarlo by po wyjsciu z funkcji, nawet jakbysmy przypisaly do tab?
			for (int i = 0; i < s; i++)
			{
				file >> value;
				if (file.fail())
				{
					cout << "File error - READ DATA" << endl;
					break;
				}
				else
					new_tab[i] = value;
			}
			delete[] tab;
			tab = new_tab;
			size = s;
		}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

void DynamicArray::show() {
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << tab[i] << " ";
	}
}

DynamicArray::~DynamicArray() {
	delete[] tab;
}