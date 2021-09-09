#pragma once
#include <iostream>
using namespace std;

struct TreeElement {
	TreeElement* left;
	TreeElement* right;
	TreeElement* parent;
	int key;
};

class BinarySearchTree
{
public:
	TreeElement* root;

	TreeElement* min_tree();
	TreeElement* max_tree();
	TreeElement* min(TreeElement* element);
	TreeElement* max(TreeElement* element);
	TreeElement* succesor(TreeElement* element);
	void insert(int key);
	void insert(TreeElement* new_element);
	TreeElement* find_element(int key);
	TreeElement* find_element(TreeElement* element, int key);
	void remove(TreeElement* element);

	void rotate_l(TreeElement* element);
	void rotate_r(TreeElement* element);
	void dsw_balance();
	int count_elements();
	
	void read_file(string file_name);
	void in_order(TreeElement* element);
	void show_in_order();
	void draw();
	int find_space(TreeElement* element);
	void post_order(TreeElement* element);
	void clean();
	~BinarySearchTree();
};

