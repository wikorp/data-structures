#pragma once
#include <iostream>
using namespace std;

struct ListElement {
	int data;
	ListElement* previous;
	ListElement* next;
};


class List
{
public:
	int size = 0;
	ListElement* head = NULL;
	ListElement* tail = NULL;

	void put_last(int value);
	void put_first(int value);
	void put(int value, int index);

	void remove_last();
	void remove_first();
	void remove(int index);

	int get(int index);
	int find(int value);

	void read_file(string file_path);

	void show();

	void clean();
	~List();
};

