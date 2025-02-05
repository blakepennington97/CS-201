#include <iostream>
#include "CDA.cpp"
using namespace std;

template <typename T, typename T2>
struct Heap_Node {
	int index;
	T key;
	T2 value;
};

template <typename T, typename T2>
class Heap {
private:
	int size;
 	CDA<Heap_Node<T, T2>> arr;

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
	template <typename any>
	void swap(any* x, any* y) {
		any temp = *x;
		*x = *y;
		*y = temp;
	}

	void heapify(int i) {
		int left = leftChild(i);
		int right = rightChild(i);
		int smallest = i;

		// check if the left node is smaller than the current node
		if (left < size && arr[left].key < arr[smallest].key) {
			smallest = left;
		}

		// check if the right node is smaller than the current node & left node 
		if (right < size && arr[right].key < arr[smallest].key) {
			smallest = right;
		}

		// swap the smallest node with the current node, repeat this process until the current node is smaller than the right and left node
		if (smallest != i) {
			Heap_Node<T, T2> temp = arr[i];
			arr[i] = arr[smallest];
			arr[smallest] = temp;
			heapify(smallest);
		}

	}

public:
	Heap() {
		size = 0;
	}

	Heap(T *k, T2 *v, int s) {
		int start = (s / 2) - 1;
		size = s;
		for (int i = 0; i < size; i++) {
			Heap_Node<T, T2> temp;
			temp.index = i;
			temp.key = k[i];
			temp.value = v[i];
			arr.AddEnd(temp);
		}

		for (int i = start; i >= 0; i--) {
			heapify(i);
		}

	}

	~Heap() {
		//delete(arr);
	}

	T peekKey() {
		return arr[0].key;
	}

	T2 peekValue() {
		return arr[0].value;
	}

	T extractMin() {
		Heap_Node<T, T2> minItem = arr[0];

		// replace the first item with the last item
		arr[0] = arr[size - 1];
		size = size - 1;

		// maintain the heap property by heapifying the first item
		heapify(0);
		return minItem.key;
	}

	void insert(T k, T2 v) {
		//first insert a last position in array
		Heap_Node<T, T2> new_node;
		new_node.key = k;
		new_node.value = v;
		new_node.index = size;
		arr.AddEnd(new_node);
		size++;

		//bubble up until heap property satisfied
		int i = size - 1;
		while (i != 0 && ( arr[parent(i)].key > arr[i].key) ) { 
			swap<T>( &(arr[parent(i)].key), &(arr[i].key) ); 
			swap<T2>( &(arr[parent(i)].value), &(arr[i].value) ); 
			i = parent(i); 
		}


	}
	void printKey() {
		for (int i = 0; i < size; i++) {
			cout << arr[i].key << " ";
		}
		cout << endl;
	}
};


