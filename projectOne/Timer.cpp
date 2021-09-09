#include "BinarySearchTree.h" //jak na dole to sie kod nie kompiluje dlaczego
#include "Timer.h"
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <random>
#include "DynamicArray.h"
#include "List.h"
#include "Heap.h"
using namespace std;

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void Timer::measure(DynamicArray* data) {
    int size = 100;
    int averge = 10;
    for (int i = 0; i < 5; i++) {
        double put_last = 0, put_first = 0, put = 0, remove_last = 0, remove_first = 0, remove = 0, get = 0, find = 0; 
        for (int i = 0; i < averge; i++) {
            generate(data, size);

            long long int frequency, start, elapsed;
            QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);

            int random = generate();
            start = read_QPC();
            data->put_first(random);
            elapsed = read_QPC() - start;
            put_first += (1000000.0 * elapsed) / frequency;
          
            random = generate();
            start = read_QPC();
            data->put_last(random);
            elapsed = read_QPC() - start;
            put_last += (1000000.0 * elapsed) / frequency;

            random = generate();
            int random_s = generate(0, data->size - 1);
            start = read_QPC();
            data->put(random, random_s);
            elapsed = read_QPC() - start;
            put += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            data->remove_last();
            elapsed = read_QPC() - start;
            remove_last += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            data->remove_first();
            elapsed = read_QPC() - start;
            remove_first += (1000000.0 * elapsed) / frequency;

            random_s = generate(0, data->size - 1);
            start = read_QPC();
            data->remove(random_s);
            elapsed = read_QPC() - start;
            remove += (1000000.0 * elapsed) / frequency;

            random_s = generate(0, data->size - 1);
            start = read_QPC();
            data->get(random_s);
            elapsed = read_QPC() - start;
            get += (1000000.0 * elapsed) / frequency;    

            int compilator_opt;                         //if it is just data->find(random); compilator see that is blind operation and dont do it
            random = generate();
            start = read_QPC();
            compilator_opt = data->find(random);
            elapsed = read_QPC() - start;
            find += (1000000.0 * elapsed) / frequency;
        }
        cout << "SIZE OF STRUCTURE =" << size << endl;
        cout << "Time [us] = " << put_first / averge << " -put first" << endl;
        cout << "Time [us] = " << put_last / averge << " -put last" << endl;
        cout << "Time [us] = " << put / averge << " -put by index" << endl;
        cout << "Time [us] = " << remove_last / averge << " -remove last" << endl;
        cout << "Time [us] = " << remove_first / averge << " -remove first" << endl;
        cout << "Time [us] = " << remove / averge << " -remove by index" << endl;
        cout << "Time [us] = " << get / averge << " -get by index" << endl;
        cout << "Time [us] = " << find / averge << " -find element by value" << endl << endl;
        size *= 10;
    }
}

void Timer::measure(List* data) {
    int compiler_opt = NULL;
    int size = 100;
    int averge = 10;
    for (int i = 0; i < 5; i++) {
        double put_last = 0, put_first = 0, put = 0, remove_last = 0, remove_first = 0, remove = 0, get = 0, find = 0; 
        for (int i = 0; i < averge; i++) {
            generate(data, size);

            long long int frequency, start, elapsed;
            QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);

            int random = generate();
            start = read_QPC();
            data->put_first(random);
            elapsed = read_QPC() - start;
            put_first += (1000000.0 * elapsed) / frequency;

            random = generate();
            start = read_QPC();
            data->put_last(random);
            elapsed = read_QPC() - start;
            put_last += (1000000.0 * elapsed) / frequency;

            random = generate();
            int random_s = generate(0, data->size - 1);
            start = read_QPC();
            data->put(random, random_s);
            elapsed = read_QPC() - start;
            put += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            data->remove_last();
            elapsed = read_QPC() - start;
            remove_last += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            data->remove_first();
            elapsed = read_QPC() - start;
            remove_first += (1000000.0 * elapsed) / frequency;

            random_s = generate(0, data->size - 1);
            start = read_QPC();
            data->remove(random_s);
            elapsed = read_QPC() - start;
            remove += (1000000.0 * elapsed) / frequency;

            random_s = generate(0, data->size - 1);
            start = read_QPC();
            compiler_opt = data->get(random_s);
            elapsed = read_QPC() - start;
            get += (1000000.0 * elapsed) / frequency;
            if (compiler_opt != NULL and compiler_opt > 10000300)
                cout << compiler_opt;

            random = generate();
            start = read_QPC();
            compiler_opt = data->find(random);
            elapsed = read_QPC() - start;
            find += (1000000.0 * elapsed) / frequency;
        }
        cout << "SIZE OF STRUCTURE =" << size << endl;
        cout << "Time [us] = " << put_first / averge << " -put first" << endl;
        cout << "Time [us] = " << put_last / averge << " -put last" << endl;
        cout << "Time [us] = " << put / averge << " -put by index" << endl;
        cout << "Time [us] = " << remove_last / averge << " -remove last" << endl;
        cout << "Time [us] = " << remove_first / averge << " -remove first" << endl;
        cout << "Time [us] = " << remove / averge << " -remove by index" << endl;
        cout << "Time [us] = " << get / averge << " -get by index" << endl;
        cout << "Time [us] = " << find / averge << " -find element by value" << endl << endl; 

        data->clean();
        size *= 10;
    }
}

void Timer::measure(Heap* data) {
    int size = 100;
    int averge = 10;
    for (int i = 0; i < 5; i++) {
        double put = 0, remove_first = 0 , get_max = 0, find = 0;                            
        for (int i = 0; i < averge; i++) {
            generate(data, size);

            long long int frequency, start, elapsed;
            QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);

            int random = generate();
            start = read_QPC();
            data->put(random);
            elapsed = read_QPC() - start;
            put += (1000000.0 * elapsed) / frequency;   

            start = read_QPC();
            data->remove_first();
            elapsed = read_QPC() - start;
            remove_first += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            data->get_max();
            elapsed = read_QPC() - start;
            get_max += (1000000.0 * elapsed) / frequency;

            int compilator_opt;
            random = generate();
            start = read_QPC();
            compilator_opt = data->find(random);
            elapsed = read_QPC() - start;
            find += (1000000.0 * elapsed) / frequency;
        }
        cout << "SIZE OF STRUCTURE =" << size << endl;
        cout << "Time [us] = " << put / averge << " -put" << endl;
        cout << "Time [us] = " << remove_first / averge << " -remove first" << endl;
        cout << "Time [us] = " << get_max / averge << " -get max" << endl;
        cout << "Time [us] = " << find / averge << " -find element by value" << endl << endl; 
        size *= 10;
    }
}

void Timer::measure(BinarySearchTree* data) {
    TreeElement* compiler_opt = NULL;
    int size = 100;
    int averge = 10;
    for (int i = 0; i < 5; i++) {
        double insert = 0, find = 0, remove = 0, remove_f = 0, min = 0, max = 0, succesor = 0;
        for (int i = 0; i < averge; i++) {
            generate(data, size);
      
            long long int frequency, start, elapsed;
            QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);

            int random = generate();
            start = read_QPC();
            data->insert(random);
            elapsed = read_QPC() - start;
            insert += (1000000.0 * elapsed) / frequency;

            random = generate();
            start = read_QPC();
            compiler_opt = data->find_element(random);
            elapsed = read_QPC() - start;
            find += (1000000.0 * elapsed) / frequency;
            if (compiler_opt != NULL and compiler_opt->key > 10000300)
                cout << compiler_opt->key;

            random = generate();                        //deleting with finding element by value
            data->insert(random);
            start = read_QPC();
            data->remove(data->find_element(random));
            elapsed = read_QPC() - start;
            remove_f += (1000000.0 * elapsed) / frequency;

            random = generate();                        //deleting when we have pointer to element
            data->insert(random);
            TreeElement* pointer = data->find_element(random);
            start = read_QPC();
            data->remove(pointer);
            elapsed = read_QPC() - start;
            remove += (1000000.0 * elapsed) / frequency;

            start = read_QPC();
            compiler_opt = data->min_tree();
            elapsed = read_QPC() - start;
            min += (1000000.0 * elapsed) / frequency;
            if (compiler_opt->key > 100000)
                cout << compiler_opt->key;

            start = read_QPC();
            compiler_opt = data->max_tree();
            elapsed = read_QPC() - start;
            max += (1000000.0 * elapsed) / frequency;
            if (compiler_opt->key < 0)
                cout << compiler_opt->key;
            
            random = generate();                        
            data->insert(random);
            pointer = data->find_element(random);
            start = read_QPC();
            compiler_opt = data->succesor(pointer);
            elapsed = read_QPC() - start;
            succesor += (1000000.0 * elapsed) / frequency;   

        }
        cout << "SIZE OF STRUCTURE =" << size << endl;
        cout << "Time [us] = " << insert / averge << " -insert" << endl;
        cout << "Time [us] = " << find / averge << " -find by value" << endl;
        cout << "Time [us] = " << remove / averge << " -remove when we have pointer to element" << endl;
        cout << "Time [us] = " << remove_f / averge << " -remove with finding element by value" << endl;
        cout << "Time [us] = " << min / averge << " -find min in tree" << endl;
        cout << "Time [us] = " << max / averge << " -find max in tree" << endl;
        cout << "Time [us] = " << succesor / averge << " -finding succesor when we have pointer" << endl << endl;
        data->clean();
        size *= 10;
    }
}

void Timer::generate(DynamicArray* data, int size) {
    random_device rd;                                      
    mt19937 gen(rd());                                    
    uniform_int_distribution<> dist(-1000000, 1000000);     

    data->size = size;
    int* new_tab = new int[size];
    delete[] data->tab;
    data->tab = new_tab;

    for (int i = 0; i < size; i++)
    {
        data->tab[i] = dist(gen);                          
    }
}

void Timer::generate(Heap* data, int size) {
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> dist(-1000000, 1000000);

    data->size = size;
    int* new_tab = new int[size];
    delete[] data->tab;
    data->tab = new_tab;

    for (int i = 0; i < size; i++)
    {
        data->tab[i] = dist(gen); 
    }

    data->build();
}

void Timer::generate(List* data, int size) {
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> dist(-1000000, 1000000);
    for (int i = 0; i < size; i++)
    {
        data->put_first(dist(gen)); 
    }
}

void Timer::generate(BinarySearchTree* data, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-1000000, 1000000);
    for (int i = 0; i < size; i++)
    {
        data->insert(dist(gen));
    }
}

int Timer::generate() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-1000000, 1000000);
    return dist(gen);
}

int Timer::generate(int from, int to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(from, to);
    return dist(gen);
}