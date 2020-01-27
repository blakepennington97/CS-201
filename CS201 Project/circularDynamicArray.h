#pragma once
class CircularDynamicArray {
private:
	struct Node {
		int data;
		Node* next;
	};
	int size;
	int capacity;
	int* array;
	int* temp_array;
	int* front_ptr;
	int* back_ptr;
	int* temp_ptr;
	void grow();
public:
	CircularDynamicArray();
	CircularDynamicArray(int s);
	~CircularDynamicArray();
	void addEnd(int x);
	void addFront(int x);
	void printArray();
	void printFrontBack();
};

