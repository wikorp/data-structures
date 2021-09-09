#pragma once
#include <iostream>
using namespace std;

class Heap
{
public:
	int size = 0; 
	int* tab = new int[size];

	int parent(int index);
	int left(int index);
	int right(int index);
	void heapify(int index);				
	void build();

	int get_max();
	void remove_first();
	void put(int value);
	int find(int value);

	void read_file(string file_path);
	void show();

	~Heap();
};

