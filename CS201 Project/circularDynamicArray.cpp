#include "CircularDynamicArray.h"
#include <iostream>
using namespace std;

template <typename T>
CircularDynamicArray<T>::CircularDynamicArray() {
	size = 0;
	capacity = 1;
	temp_array = NULL;
	temp_ptr = NULL;
	array = new T[capacity] {}; //intialize a dynamic array of capacity 2
	front_ptr = NULL;
	back_ptr = NULL;
}

template <typename T>
CircularDynamicArray<T>::CircularDynamicArray(int s) {
	size = capacity = s;
	front_ptr = new int[capacity];
	back_ptr = front_ptr;
}

template <typename T>
CircularDynamicArray<T>::~CircularDynamicArray() {
	//delete stuff
}

template <typename T>
void CircularDynamicArray<T>::addEnd(T x) {
	if (size == 0) {
		front_ptr = array;
		back_ptr = array;
	}
	else {
		back_ptr++;
	}
	if (size == capacity) {
		grow(1);
	}
	*back_ptr = x;
	//cout << "endIndex = " << endIndex << endl;
	
	cout << "I just added " << x << endl;

	/*for (int i = 0; i < capacity; i++) {
		cout << array[i] << endl;
	}*/
	if (size == 0) {
		front_ptr = array;
	}
	size += 1;
	/*if (size != 1) {
		back_ptr++;
	}
	else {
		front_ptr = array;
	}*/
	printArray();
	printFrontBack();
}

template <typename T>
void CircularDynamicArray<T>::addFront(T x) {
	if (size == capacity)
		grow(0, x);
	else {
		front_ptr++;
	}
	if (size == 0) {
		addEnd(x);
		front_ptr = array;
	}
	else
	{
		//if (startIndex == -1) { //if startIndex is too small
		//	startIndex += capacity;
		//	cout << "startIndex too small." << endl;
		//}
		//if (startIndex > capacity) { //if startIndex is too large
		//	startIndex -= capacity;
		//	cout << "startIndex too thicc." << endl;
		//}
		//else {
		//	startIndex--;
		//}
		*front_ptr = x;
		cout << "I just added " << x << endl;
		size += 1;
		printArray();
		printFrontBack();
	}
}

template <typename T>
void CircularDynamicArray<T>::printArray() {
	cout << "[";
	for (int i = 0; i < capacity; i++) {
		cout << array[i];
		if (i < capacity - 1)
			cout << ", ";
	}
	cout <<  "]" << endl;
}

template <typename T>
void CircularDynamicArray<T>::printFrontBack() {
	cout << "HEAD: " << *front_ptr << endl;
	cout << "BACK: " << *back_ptr << endl;
}

template <typename T>
void CircularDynamicArray<T>::grow(bool x) {
	capacity *= 2;
	temp_array = new T[capacity] {}; //intialize a larger dynamic array of capacity c
	for (int i = 0; i < (capacity / 2); i++) {
		//TODO: rearrange in corrected head->tail order
		temp_array[i] = array[i];
		cout << "im growinggg" << endl;
	}
	array = temp_array;
	if (x) {
		front_ptr = array;
		back_ptr = array;
		back_ptr += size;
	}
	else {
		front_ptr = array;
		front_ptr += size;
		back_ptr = array;
	}
	cout << "new capacity = " << capacity << endl;

	//TODO
	/*
	delete old array (caused bug in past)
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