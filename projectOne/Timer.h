#pragma once
#include <iostream>
#include "DynamicArray.h"
#include "List.h"
#include "Heap.h"
#include "BinarySearchTree.h"
using namespace std;


class Timer
{
public:
	static void measure(DynamicArray* data); //dlaczego sie psulo gdy dynaicArray data?
	static void measure(List* data);
	static void measure(Heap* data);
	static void measure(BinarySearchTree* data);

	static void generate(DynamicArray* data, int size);
	static void generate(List* data, int size);
	static void generate(Heap* data, int size);
	static void generate(BinarySearchTree* data, int size);
	static int generate();
	static int generate(int from, int to);
};

