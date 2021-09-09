#include "List.h"
#include <iostream>
#include <fstream>
using namespace std;

void List::put_first(int value) { // czy elementy listy musza byc tworzone dynamicznie kiedy umieraja jak nie sa dynamiczne - po to dynamicznie bo by znikne³y po wyjsciu z funkci
	ListElement* new_element = new ListElement;

	new_element->data = value;
	new_element->previous = NULL;
	new_element->next = head;
	if (head != NULL)
		new_element->next->previous = new_element;
	else tail = new_element;								//it means there was nothing before
	head = new_element;
	size++;
}

void List::put_last(int value) {
	ListElement* new_element = new ListElement;

	new_element->data = value;
	new_element->next = NULL;
	new_element->previous = tail;
	if (tail != NULL)
		new_element->previous->next = new_element;
	else head = new_element;

	tail = new_element;
	size++;
}

void List::put(int value, int index) {
	if (index < 0 or index > size)
		return;
	if (index == 0) {
		put_first(value);
		return;
	}
	
	if (index == size) {
		put_last(value);
		return;
	}

	ListElement* iterator = head;
	for (int i = 0; i < index; i++) 
		iterator = iterator->next;
	
	ListElement* new_element = new ListElement;
	new_element->data = value;
	new_element->previous = iterator->previous;
	new_element->previous->next = new_element;
	new_element->next = iterator;
	iterator->previous = new_element;
	size++;
}

void List::remove_first() {
	if (head == NULL)
		return;

	ListElement* to_delete;
	to_delete = head;
	if (to_delete != tail)
		to_delete->next->previous = NULL;
	else tail = NULL;
	head = to_delete->next;
	delete to_delete;
	size--;
}

void List::remove_last() {
	if (tail == NULL)
		return;

	ListElement* to_delete;
	to_delete = tail;
	if (to_delete != head)
		to_delete->previous->next = NULL;
	else head = NULL;
	tail = to_delete->previous;
	delete to_delete;
	size--;
}

void List::remove(int index) {
	if (index < 0 or index >= size)
		return;

	if (index == 0) {
		remove_first();
		return;
	}

	if (index == size - 1) {
		remove_last();
		return;
	}

	ListElement* to_delete;
	if (size - index > size / 2) {
		to_delete = head;
		for (int i = 0; i < index; i++)
			to_delete = to_delete->next;
	}
	else {
		to_delete = tail;
		for (int i = size - 1; i > index; i--)
			to_delete = to_delete->previous;
	}

	to_delete->previous->next = to_delete->next;
	to_delete->next->previous = to_delete->previous;
	delete to_delete;
	size--;
}

int List::get(int index) {
	if (index < 0 or index >= size) {
		cout << "ERROR - BAD INDEX";
		return NULL;
	}

	ListElement* iterator;
	if (size - index > size / 2) {
		iterator = head;
		for (int i = 0; i < index; i++)
			iterator = iterator->next;
	}
	else {
		iterator = tail;
		for (int i = size - 1; i > index; i--)
			iterator = iterator->previous;
	}

	return iterator->data;
}

int List::find(int value) {
	ListElement* iterator;
	iterator = head;
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (iterator->data == value)
			return index;
		iterator = iterator->next;
		index++;
	}

	return NULL;
}
void List::read_file(string file_path) {
	int s, value;
	clean();
	ifstream file;
	file.open(file_path);

	if (file.is_open())
	{
		file >> s;
		if (file.fail())
			cout << "File error - READ SIZE" << endl;
		else {
			for (int i = 0; i < s; i++)
			{
				file >> value;
				if (file.fail())
				{
					cout << "File error - READ DATA" << endl;
					break;
				}
				else
					put_last(value);
			}
			size = s;
		}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

void List::show() {
	ListElement* iterator;
	iterator = head;

	cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "List: " << endl;

	while (iterator != tail) {
		cout << iterator->data << " ";
		iterator = iterator->next;
	}
	if (iterator != NULL)
		cout << iterator->data;


	cout << endl << "List from back: " << endl;
	iterator = tail;
	while (iterator != head) {
		cout << iterator->data << " ";
		iterator = iterator->previous;
	}
	if (iterator != NULL)
		cout << iterator->data;
}

void List::clean() {
	int s = size;
	for (int i = 0; i < s; i++) {
		remove_last();
	}
}
List::~List() {
	ListElement* to_delete = head;
	while (to_delete != tail) {
		to_delete = to_delete->next;
		delete to_delete->previous;
	}

	if (tail != NULL)
		delete tail;
}