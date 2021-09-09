#include "Heap.h"
#include <iostream>
#include <fstream>
using namespace std;

int Heap::parent(int index) {
	return (index - 1) / 2;
}

int Heap::left(int index) {
	return (index * 2) + 1;
}

int Heap::right(int index) {
	return (index * 2) + 2;
}

void Heap::heapify(int index) {									//filter down
	int max = index;
	if (left(index) < size and tab[max] < tab[left(index)])
		max = left(index);
	if (right(index) < size and tab[max] < tab[right(index)])
		max = right(index);

	if (max == index)
		return;
	
	int bufor = tab[index];
	tab[index] = tab[max];
	tab[max] = bufor;

	heapify(max);
}

void Heap::build() {
	int firstLeaf = (size - 2) / 2 + 1;

	for (int i = firstLeaf - 1; i >= 0; i--)
		heapify(i);
}

void Heap::remove_first() {
	if (size == 0)
		return;

	tab[0] = tab[size - 1];
	size--;
	heapify(0);
	int* new_tab = new int[size];
	for (int i = 0; i < size; i++)
		new_tab[i] = tab[i];

	delete[] tab;
	tab = new_tab;
}

int Heap::get_max() {
	if (size > 0)
		return tab[0];
	else return NULL;
}

void Heap::put(int value) {
	int* new_tab = new int[size + 1];
	for (int i = 0; i < size; i++)
		new_tab[i] = tab[i];
	delete tab;
	tab = new_tab;
	size++;

	int i = size - 1;
	while (i > 0 and tab[parent(i)] < value) {
		tab[i] = tab[parent(i)];
		i = parent(i);
	}

	tab[i] = value;
}

int Heap::find(int value) {
	for (int i = 0; i < size; i++) {
		if (tab[i] == value) 
			return i;
	}
	return NULL;
}

void Heap::show() {
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Heap:      !MIGHT BE NECESSARY MAXIMAZE THE WINDOW!" << endl;
	for (int i = 0; i < size; i++) {
		cout << tab[i] << " ";
	}
	cout << endl;

	int floor = 1;
	int scale = 128;
	for (int i = 0; i < size; i++) {

		int elements = floor;
		while (elements > 0 and i < size) {
			for (int i = 0; i <= scale/(floor + 1); i++)
				cout << " ";

			cout << tab[i] << " ";
			elements--;
			i++;
		}
		cout << endl;
		floor *= 2;
		i--;
	}
}

void Heap::read_file(string file_path) {
	int s, value;
	ifstream file;
	file.open(file_path);

	if (file.is_open())
	{
		file >> s;
		if (file.fail())
			cout << "File error - READ SIZE" << endl;
		else {
			int* new_tab = new int[s];
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

	build();
}

Heap::~Heap() {
	delete[] tab;
}