#pragma once
#include <iostream>
using namespace std;

class DynamicArray {
public:
	int size = 0;
	int* tab = new int[size];

	void put_last(int value);
	void put_first(int value);
	void put(int value, int index);

	void remove_last();
	void remove_first();
	void remove(int index);
	
	int get(int index);
	int find(int value);

	void read();							//crate new array from data inserted by user thru terminal
	void read_file(string filePath);		//create new array from data readed from file

	void show();							//visualization of array

	~DynamicArray();
};