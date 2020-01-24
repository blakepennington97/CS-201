#include "CircularDynamicArray.h"
#include <iostream>
using namespace std;

CircularDynamicArray::CircularDynamicArray() {
	size = 0;
	capacity = 2;
	array = new int[capacity] {}; //intialize a dynamic array of capacity 2
	front_ptr = array;
	back_ptr = front_ptr;
}

CircularDynamicArray::CircularDynamicArray(int s) {
	size = capacity = s;
	front_ptr = new int[capacity];
	back_ptr = front_ptr;
}

CircularDynamicArray::~CircularDynamicArray() {
	//delete stuff
}

void CircularDynamicArray::addEnd(int x) {
	if (size == capacity)
		grow();
	*back_ptr = x;
	cout << "I just added " << x << endl;
	size += 1;
	//if back_ptr 
	back_ptr++;
}

void CircularDynamicArray::addFront(int x) {
	if (size == capacity)
		grow();
	if (size == 0)
		addEnd(x);
	else
	{
		//startIndex = decrementIndex(startIndex);
		//store[startIndex] = value;
		//size += 1;
	}
}

void CircularDynamicArray::printArray() {
	temp_ptr = front_ptr;
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << temp_ptr[i];
		if (i < size - 1)
			cout << ", ";
	}
	cout <<  "]" << endl;
}

void CircularDynamicArray::printFrontBack() {
	cout << "HEAD: " << *front_ptr << endl;
	cout << "BACK: " << *back_ptr << endl;
}

void CircularDynamicArray::grow() {
	capacity *= 2;
	int *temp_array = new int[capacity] {}; //intialize a grown dynamic array of capacity c
	for (int i = 0; i < size; i++) {
		temp_array[i] = array[i];
		cout << "im growinggg" << endl;
	}
	array = temp_array;
	delete[] temp_array;
	/*
	allocate a new store with the new capacity
	copy the elements from the old store to the new store
	free the old store
	set the data structure's store to the new store
	update the capacity
	the start index is usually reset to zero. 
	Thus, the element at the start index of the old store 
	gets placed in the leftmost slot in the new store, and so on. 
	When computing the index of the next element to be transferred, 
	the incrementIndex or correctIndex functions should be used.
	*/

}