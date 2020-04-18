//This is a binary heap class
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


#include <iostream>
#include "CDA.cpp"
using namespace std;

template <typename T, typename T2>
struct Node {
	int index;
	T key;
	T2 value;
};

template <typename T, typename T2>
class Heap {
private:
	int size;
 	CDA<Node<T, T2>> arr;
	//Node <T, T2>* arr;

	// return index of the parent node
	int parent(int i) {
		return (i - 1) / 2;
	}

	// return index of the left child 
	int leftChild(int i) {
		return 2 * i + 1;
	}

	// return index of the right child 
	int rightChild(int i) {
		return 2 * i + 2;
	}

	//helper function to assist insertion
	void swap(T* x, T* y) {
		T temp = *x;
		*x = *y;
		*y = temp;
	}

	
public:
	Heap() {
		//arr = new Node<T, T2>;
		size = 0;
		//capacity = 1;
	}
	Heap(T k, T2 V, int s) {
		size = s;
	}
	~Heap() {

	}
	T peekKey() {

	}
	T2 peekValue() {

	}
	T extractMin() {

	}
	void insert(T k, T2 v) {
		//first insert a last position in array
		Node<T, T2> new_node;
		new_node.index = 0;
		new_node.key = 0;
		new_node.value = 0;

		new_node.key = k;
		new_node.value = v;
		new_node.index = size;
		//arr[size] = *new_node; //add to end of tree
		arr.AddEnd(new_node);
		size++;

		//bubble up until heap property satisfied
		int i = size - 1;
		while (i != 0 && ( arr[parent(i)].key < arr[i].key) ) { //heap[BinaryHeap::parent(i)] < heap[i]
			swap( &(arr[parent(i)].key), &(arr[i].key) ); //swap(&heap[BinaryHeap::parent(i)], &heap[i]);
			swap( &(arr[parent(i)].value), &(arr[i].value) ); //swap(&heap[BinaryHeap::parent(i)], &heap[i]);
			//ANOTHER SWAP VALUE HERE?
			i = parent(i); //i = BinaryHeap::parent(i);
		}


	}
	void printKey() {
		for (int i = 0; i < size; i++) {
			cout << arr[i].key << " ";
		}
		cout << endl;
	}
};


