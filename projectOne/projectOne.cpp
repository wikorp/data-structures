#include <iostream>
#include "DynamicArray.h"
#include "List.h"
#include "Heap.h"
#include "BinarySearchTree.h"
#include "Timer.h"
using namespace std;

int choiceMenu();
int choiceStructure();
void arrayMenu();
void listMenu();
void heapMenu();
void binarySearchTreeMenu();

int main() {
    while (true) {
        int menu = choiceMenu();

        if (menu == 1) {
            while (true) {
                int menu_structures = choiceStructure();

                if (menu_structures == 1) {
                    arrayMenu();
                }

                if (menu_structures == 2) {
                    listMenu();
                }

                if (menu_structures == 3) {
                    heapMenu();
                }

                if (menu_structures == 4) {
                    binarySearchTreeMenu();
                }

                if (menu_structures == 5) {
                    break;
                }

             }
        }

        if (menu == 2) { 
            while (true) {
                int menu_structures = choiceStructure();

                if (menu_structures == 1) {
                    DynamicArray d;
                    Timer::measure(&d);                     //make measurments for data structure and show time of operations 
                }

                if (menu_structures == 2) {
                    List l;
                    Timer::measure(&l);
                }

                if (menu_structures == 3) {
                    Heap h;
                    Timer::measure(&h);
                }

                if (menu_structures == 4) {
                    BinarySearchTree b;
                    Timer::measure(&b);
                }

                if (menu_structures == 5) {
                    break;
                }
            }
        }

        if (menu == 3) {
            break;
        }
    }

    return 0;
}

int choiceMenu() {
    int menu_main;

    cout << ">>>>>>>>MENU<<<<<<<     (MAIN)" << endl << endl;
    cout << "1.Operations on data structures for exemplary data" << endl;
    cout << "2.Time dependencies for different data structures and operations on them" << endl;
    cout << "3.Exit" << endl << endl << endl;

    while (true) {
        cout << "Type '1' or '2' or '3'" << endl;
        cin >> menu_main;
        if (menu_main == 1 || menu_main == 2 || menu_main == 3)
            break;
    }

    return menu_main;
}

int choiceStructure() {
    int menu_structures;
    cout << ">>>>>>>>MENU<<<<<<<<    (CHOICE OF STRUCTURE)" << endl << endl;
    cout << "1.Dynamic array" << endl;
    cout << "2.list" << endl;
    cout << "3.Heap" << endl;
    cout << "4.Binary search tree - BST" << endl;
    cout << "5.Exit" << endl << endl << endl;

    while (true) {
        cout << "Type '1' or '2' or '3' or '4' or '5'" << endl;
        cin >> menu_structures;
        if (menu_structures == 1 or menu_structures == 2 or menu_structures == 3 or menu_structures == 4 or menu_structures == 5)
            break;
    }
    return menu_structures;
}

void arrayMenu() {
    DynamicArray d; //czy jest potrzeba aby tworzyc dynamicznie tutaj - nie bo czas życia ograniczony przez klamry
    while (true) {
        int menu_operations;
        cout << ">>>>>>>>DYNAMIC ARRAY<<<<<<<<    (CHOICE OF OPERATION)" << endl << endl;
        cout << "1.Create new Dynamic Array through terminal" << endl;
        cout << "2.Create new Dynamic Array from file" << endl;
        cout << "3.Show current Dynamic Array" << endl;
        cout << "4.Put new element at the end" << endl;
        cout << "5.Put new element at the begin" << endl;
        cout << "6.Put new element at the specified index" << endl;
        cout << "7.Remove last element" << endl;
        cout << "8.Remove first element" << endl;
        cout << "9.Remove element at the specified index" << endl;
        cout << "10.Get element at the specified index" << endl;
        cout << "11.Find index of element by value" << endl;
        cout << "12.Exit" << endl << endl << endl;

        while (true) {
            cout << "Type '1' or '2' or '3' or '4' or '5' or '6' or '7' or'8' or '9' or '10' or 11 or '12'" << endl;
            cin >> menu_operations;
            if (menu_operations == 1 || menu_operations == 2 || menu_operations == 3 || menu_operations == 4 || menu_operations == 5 || menu_operations == 6 || menu_operations == 7 || menu_operations == 8 || menu_operations == 9 || menu_operations == 10 || menu_operations == 11 || menu_operations == 12)
                break;
        }

        int element;
        int index;
        string file_name;
        switch (menu_operations) {
        case 1:
            d.read();
            d.show();
            break;

        case 2:
            cout << "Give path to file" << endl;
            cin >> file_name;
            d.read_file(file_name);
            d.show();
            break;

        case 3:
            d.show();
            break;

        case 4:
            cout << "Give element you want put at the end" << endl;
            cin >> element;
            d.put_last(element);
            d.show();
            break;

        case 5:
            cout << "Give element you want put at the begin" << endl;
            cin >> element;
            d.put_first(element);
            d.show();
            break;

        case 6:
            cout << "Give the value of element" << endl;
            cin >> element;
            cout << "Give the index of element" << endl;
            cin >> index;
            d.put(element, index);
            d.show();
            break;

        case 7:
            d.remove_last();
            d.show();
            break;

        case 8:
            d.remove_first();
            d.show();
            break;

        case 9:
            cout << "Give index of element you want to remove" << endl;
            cin >> index;
            d.remove(index);
            d.show();
            break;

        case 10:
            cout << "Give index of element you want get" << endl;
            cin >> index;
            element = NULL;
            element = d.get(index);
            if (element != NULL)
                cout << endl << "Value: " << element;
            d.show();
            break;

        case 11:
           cout << "Give value of element you want get index" << endl;
            cin >> element;
            index = d.find(element);
            if (index != NULL)
                cout << endl << "Index: " << index;
            if (element == d.tab[0])
                cout << endl << "Index: " << index;
            else cout << endl << "No element with this value in array";
            d.show();
            break;
        }

        if (menu_operations == 12) {
            break;
        }
        cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void listMenu() {
    List l; //czy to jest to samo co List l = new List();
    while (true) {
        int menu_operations;
        cout << ">>>>>>>>BIDERECTIONAL LIST<<<<<<<<    (CHOICE OF OPERATION)" << endl << endl;
        cout << "1.Create new List from file" << endl;
        cout << "2.Show current List" << endl;
        cout << "3.Put new element at the begin" << endl;
        cout << "4.Put new element at the end" << endl;
        cout << "5.Put new element at speciefied index" << endl;
        cout << "6.Delete element at the begin" << endl;
        cout << "7.Delete element at the end" << endl;
        cout << "8.Delete element by index" << endl;
        cout << "9.Get element by index" << endl;
        cout << "10.Find index of element by value" << endl;
        cout << "11.Exit" << endl << endl << endl;

        while (true) {
            cout << "Type '1' or '2' or '3' or '4' or '5' or '6' or '7' or '8' or '9' or '10' or '11'" << endl;
            cin >> menu_operations;
            if (menu_operations == 1 || menu_operations == 2 || menu_operations == 3 || menu_operations == 4 || menu_operations == 5 or menu_operations == 6 or menu_operations == 7 || menu_operations == 8 || menu_operations == 9 or menu_operations == 10 or menu_operations == 11)
                break;
        }

        int element, index;
        string file_name;
        switch (menu_operations) {
        case 1:
            cout << "Give path to file" << endl;
            cin >> file_name;
            l.read_file(file_name);
            l.show();
            break;

        case 2:
            l.show();
            break;

        case 3:
            cout << "Give element you want put at the begin" << endl;
            cin >> element;
            l.put_first(element);
            l.show();
            break;

        case 4:
            cout << "Give element you want put at the end" << endl;
            cin >> element;
            l.put_last(element);
            l.show();
            break;

        case 5:
            cout << "Give index of element" << endl;
            cin >> index;
            cout << "Give value of element" << endl;
            cin >> element;
            l.put(element, index);
            l.show();
            break;

        case 6:
            l.remove_first();
            l.show();
            break;

        case 7:
            l.remove_last();
            l.show();
            break;

        case 8:
            cout << "Give index of element you want to remove" << endl;
            cin >> index;
            l.remove(index);
            l.show();
            break;

        case 9:
            cout << "Give index of element you want get value" << endl;
            cin >> index;
            element = l.get(index);
            if (element != NULL)
                cout << endl << "Value:" << element;
            l.show();
            break;

        case 10:
            cout << "Give value of element you want get index" << endl;
            cin >> element;
            index = l.find(element);
            if (index != NULL)
                cout << endl << "Index: " << index;
            if (element == l.head->data)
                cout << endl << "Index: " << index;
            else cout << endl << "No element with this value in array";
            l.show();
            break;
        }

        if (menu_operations == 11) {
            break;

        }
        cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void heapMenu() {
    Heap h;
    while (true) {
        int menu_operations;
        cout << ">>>>>>>>HEAP<<<<<<<<    (CHOICE OF OPERATION)" << endl << endl;
        cout << "1.Create new Heap from file" << endl;
        cout << "2.Show current heap" << endl;
        cout << "3.Put new element" << endl;
        cout << "4.Delete element at the begin (max -'root')" << endl;
        cout << "5.Get element at the begin (max -'root')" << endl;
        cout << "6.Find index of element by value" << endl;
        cout << "7.Exit" << endl << endl << endl;

        while (true) {
            cout << "Type '1' or '2' or '3' or '4' or '5' or '6' or '7'" << endl;
            cin >> menu_operations;
            if (menu_operations == 1 || menu_operations == 2 || menu_operations == 3 || menu_operations == 4 || menu_operations == 5 || menu_operations == 6 || menu_operations == 7)
                break;
        }

        int element, index;
        string file_name;
        switch (menu_operations) {
        case 1:
            cout << "Give path to file" << endl;
            cin >> file_name;
            h.read_file(file_name); 
            h.show();
            break;

        case 2:
            h.show();
            break;

        case 3:
            cout << "Give value of the element" << endl;
            cin >> element;
            h.put(element);
            h.show();
            break;

        case 4:
            h.remove_first();
            h.show();
            break;
        
        case 5:
            if (h.get_max() != NULL)
                cout << endl << "Max: " << h.get_max();
            h.show();
            break;

        case 6:
            cout << "Give value of element you want get index" << endl;
            cin >> element;
            index = h.find(element);
            if (index != NULL)
                cout << endl << "Index: " << index;
            if (element == h.tab[0])
                cout << endl << "Index: " << index;
            else cout << endl << "No element with this value in heap";
            h.show();
            break;
        }

        if (menu_operations == 7) {
            break;

        }
        cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void binarySearchTreeMenu()
{
    BinarySearchTree b;
    while (true) {
        int menu_operations;
        cout << ">>>>>>>>BINARY SEARCH TREE - BST<<<<<<<<    (CHOICE OF OPERATION)" << endl << endl;
        cout << "1.Create new BST from file" << endl;
        cout << "2.Show current BST" << endl;
        cout << "3.Insert new element" << endl;
        cout << "4.Find element by value" << endl;
        cout << "5.Delete element by value" << endl;
        cout << "6.Find min elemenet of the tree" << endl;
        cout << "7.Find maximum element of the tree" << endl;
        cout << "8.Find succesor of element by value" << endl;
        cout << "9.Clean Tree" << endl;
        cout << "10.Rotate left element by value" << endl;
        cout << "11.Rotate right element by value" << endl;
        cout << "12.DSW balance tree" << endl;
        cout << "13.Exit" << endl << endl << endl;

        while (true) {
            cout << "Type '1' or '2' or '3' or '4' or '5' or '6' or '7' or '8' or '9' or '10' or '11 or '12' or '13'" << endl;
            cin >> menu_operations;
            if (menu_operations == 1 || menu_operations == 2 || menu_operations == 3 || menu_operations == 4 || menu_operations == 5 or menu_operations == 6 or menu_operations == 7 || menu_operations == 8 || menu_operations == 9 or menu_operations == 10 || menu_operations == 11 || menu_operations == 12 || menu_operations == 13)
                break;
        }

        int element, index;
        string file_name;
        TreeElement* search;
        switch (menu_operations) {
        case 1:
            cout << "Give filename" << endl;
            cin >> file_name;
            b.read_file(file_name);
            b.show_in_order();
            break;

        case 2:
            b.show_in_order();
            break;

        case 3:
            cout << "Give value of the element" << endl;
            cin >> element;
            b.insert(element);
            b.show_in_order();
            break;

        case 4:
            cout << "Give value of the element" << endl;
            cin >> element;
            search = b.find_element(element);
            if (search != NULL)
                cout << endl << "Value: " << search->key << "  Address: " << search;
            else cout << endl << "There is no element with this value in tree";
            b.show_in_order();
            break;

        case 5:
            cout << "Give value of the element" << endl;
            cin >> element;
            search = b.find_element(element);
            if (search != NULL)
                b.remove(search);
            else cout << endl << "There is no element with this value in tree";
            b.show_in_order();
            break;

        case 6:
            if (b.min_tree() != NULL)
                cout << endl << "Min of tree: " << b.min_tree()->key;
            else cout << endl << "There is no elements in tree";
            b.show_in_order();
            break;  

        case 7:
            if (b.min_tree() != NULL)
                cout << endl << "Max of tree: " << b.max_tree()->key;
            else cout << endl << "There is no elemens in tree";
            b.show_in_order();
            break;

        case 8:
            cout << "Give value of the element" << endl;
            cin >> element;
            if (b.succesor(b.find_element(element)) != NULL)
                cout << endl << "Succesor of the element: " << element << " is: " << b.succesor(b.find_element(element))->key;
            else cout << endl << "There is no element in tree with this value so there is no succesor of this element or this is max";
            b.show_in_order();
            break;

        case 9:
            b.clean();
            b.show_in_order();
            break;

        case 10:
            cout << "Give value of the element" << endl;
            cin >> element;
            search = b.find_element(element);
            if (search != NULL)
                b.rotate_l(search);
            b.show_in_order();
            break;

        case 11:
            cout << "Give value of the element" << endl;
            cin >> element;
            search = b.find_element(element);
            if (search != NULL)
                b.rotate_r(search);
            b.show_in_order();
            break;

        case 12:
            b.dsw_balance();
            b.show_in_order();
            break;
        }
        if (menu_operations == 13) {
            break;
        }
        cout << endl << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
}
