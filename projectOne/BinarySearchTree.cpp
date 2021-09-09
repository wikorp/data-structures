#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

TreeElement* BinarySearchTree::min(TreeElement* min_element) {

	while (min_element != NULL) {
		if (min_element->left != NULL)
			min_element = min_element->left;
		else break;
	}
	return min_element;
}

TreeElement* BinarySearchTree::max(TreeElement* max_element) {

	while (max_element != NULL) {
		if (max_element->right != NULL)
			max_element = max_element->right;
		else break;
	}
	return max_element;
}

TreeElement* BinarySearchTree::max_tree() {
	return max(root);
}

TreeElement* BinarySearchTree::min_tree() {
	return min(root);
}

TreeElement* BinarySearchTree::succesor(TreeElement* element) {				//for root returns NULL
	if (element == NULL)
		return NULL;

	if (element->right != NULL) 
		return min(element->right);
	
	TreeElement* succesor = element->parent;
	while (succesor != NULL and element->parent->right == element) {		//parent != NULL because might be root
		element = succesor;
		succesor = succesor->parent;
	}
	return succesor;
	
}

void BinarySearchTree::insert(int key) {
	TreeElement* new_element = new TreeElement;
	new_element->key = key;
	new_element->left = NULL;
	new_element->right = NULL;
	new_element->parent = NULL;
	insert(new_element);
}

void BinarySearchTree::insert(TreeElement* new_element) {
	TreeElement* parent = root;												 // parent for new element
	while (parent != NULL) {
		if (new_element->key <= parent->key) {
			if (parent->left != NULL)
				parent = parent->left;
			else break;
		}

		if (new_element->key > parent->key) {
			if (parent->right != NULL)
				parent = parent->right;
			else break;
		}
	}

	new_element->parent = parent;

	if (parent == NULL)
		root = new_element;
	else if (parent->key < new_element->key)
		parent->right = new_element;
	else parent->left = new_element;
}

TreeElement*  BinarySearchTree::find_element(TreeElement* element, int key) {	
	if (element == NULL or element->key == key)
		return element;

	if (element->key >= key)
		return find_element(element->left, key);
	else return find_element(element->right, key);
}

TreeElement* BinarySearchTree::find_element(int key) {
	return find_element(root, key);
}

void BinarySearchTree::remove(TreeElement* to_remove) {
	if (to_remove == NULL)
		return;
	
	TreeElement* children = NULL;
	if (to_remove->left == NULL or to_remove->right == NULL) {	//case when element to remove have 0 or 1 children
		if (to_remove->left != NULL)							//finding children
			children = to_remove->left;
		else children = to_remove->right;						// if no children, children still NULL

		if (children != NULL)
			children->parent = to_remove->parent;

		if (to_remove->parent == NULL)							//asigment childrens from element to delete >>>>>>>>>SUCCESOR DONT HAVE TO BE LEAF, CAN HAVE CHILD<<<<<
			root = children;
		else if (to_remove->parent->right == to_remove)
			to_remove->parent->right = children;
		else to_remove->parent->left = children;

		delete to_remove;
		return;
	}

	if (to_remove->left != NULL and to_remove->right != NULL) {
		TreeElement* succesor_ = succesor(to_remove);			//case when element to remove have 2 children we need tho find succesor
		to_remove->key = succesor_->key;
	
		if (succesor_->parent->right == succesor_)
			succesor_->parent->right = succesor_->right;
		else succesor_->parent->left = succesor_->right;

		delete succesor_;
	}
}

void BinarySearchTree::rotate_l(TreeElement* element) {
	TreeElement* B = element->right;
	TreeElement* parent = element->parent;

	if (B != NULL) {
		if (B->left != 0) {
			element->right = B->left;
			element->right->parent = element;
		}
		else {
			element->right = NULL;
		}

		B->left = element;
		element->parent = B;
		B->parent = parent;

		if (parent != NULL) {
			if (parent->right == element)
				parent->right = B;
			else parent->left = B;
		} else root = B;
	}
}

void BinarySearchTree::rotate_r(TreeElement* element) {
	TreeElement* B = element->left;
	TreeElement* parent = element->parent;

	if (B != NULL) {
		if (B->right != 0) {
			element->left = B->right;
			element->left->parent = element;
		}
		else {
			element->left = NULL;
		}

		B->right = element;
		element->parent = B;
		B->parent = parent;

		if (parent != NULL) {
			if (parent->right == element)
				parent->right = B;
			else parent->left = B;
		}
		else root = B;
	}
}

void BinarySearchTree::dsw_balance() {
	TreeElement* tmp = root;
	while (tmp != NULL) {				//first etap making list from tree
		if (tmp->left != NULL) {				
			rotate_r(tmp);
			tmp = tmp->parent;
		}
		else {
			tmp = tmp->right;
		}
	}

	int n = count_elements();			//etap 2
	int power = log2(n + 1);
	int m = pow(2, power) - 1;			//number of elements the biggest full subtree
	int r = n - m;						//number of leafs at the last floor

	tmp = root;
	for (int i = 0; i < r; i++) {
		rotate_l(tmp);
		tmp = tmp->parent->right;
	}

	while (m > 1) {					
		m = m / 2;
		tmp = root;
		for (int i = 0; i < m; i++) {
			rotate_l(tmp);
			tmp = tmp->parent->right;
		}
	}

}

int BinarySearchTree::count_elements() {
	queue < TreeElement* > q1;
	int elements = 0;
	if (root != NULL)
		q1.push(root);


	while (!q1.empty()) {
		TreeElement* tmp = q1.front();
		if (tmp->left != NULL)
			q1.push(tmp->left);
		if (tmp->right != NULL)
			q1.push(tmp->right);

		elements++;
		q1.pop();
	}
	return elements;
}

void BinarySearchTree::in_order(TreeElement* element) {
	if (element == NULL)
		return;
	in_order(element->left);
	cout << element->key << " ";
	in_order(element->right);
}

void BinarySearchTree::show_in_order() {
	cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "BinarySearchTree 'in order - if sorted proof that that BST is correct'" << endl;
	in_order(root);
	cout << endl;
	draw();
}


int BinarySearchTree::find_space(TreeElement* element) {
	TreeElement* tmp = root;
	int space = 60;
	int scale = 60;
	while (tmp != element) {
		scale = scale / 2;
		if (element->key > tmp->key) {
			tmp = tmp->right;
			space += scale;
		}
		else {
			tmp = tmp->left;
			space -= scale;
		}
	}
	return space;
}
void BinarySearchTree::draw() {
	queue < TreeElement* > q1; 
	queue < TreeElement* > q2;
	if (root != NULL)
		q1.push(root);

	while (!q1.empty()) {
		int act_space = 0;
		int space;
		while (!q1.empty()) {
			TreeElement* tmp = q1.front();
			if (tmp->left != NULL)
				q2.push(tmp->left);
			if (tmp->right != NULL)
				q2.push(tmp->right);

			space = find_space(tmp);
			for (int i = act_space; i < space; i++) {
				cout << " ";
				act_space++;
			}
			cout << tmp->key;
			q1.pop();
		}
		cout << endl;

		act_space = 0;
		while (!q2.empty()) {
			TreeElement* tmp = q2.front();
			if (tmp->left != NULL)
				q1.push(tmp->left);
			if (tmp->right != NULL)
				q1.push(tmp->right);

			space = find_space(tmp);
			for (int i = act_space; i < space; i++) {
				cout << " ";
				act_space++;
			}
			cout << tmp->key;
			q2.pop();
		}
		cout << endl;
	}

}

void BinarySearchTree::read_file(string file_name) {
	clean();
	int s, value;
	ifstream file;
	file.open(file_name);

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
					insert(value);
			}
		}
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;

}
void BinarySearchTree::post_order(TreeElement* element) {
	if (element == NULL)
		return;
	post_order(element->left);
	post_order(element->right);
	delete element;
}

void BinarySearchTree::clean() {
	post_order(root);
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
	clean();
}