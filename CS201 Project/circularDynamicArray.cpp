#include "CircularDynamicArray.h"
#include <iostream>
using namespace std;

template <typename T>
CircularDynamicArray<T>::CircularDynamicArray() {
	size = 0;
	capacity = 1;
	temp_array = NULL;
	array = new T[capacity] {}; //intialize a dynamic array of capacity 2
	front.ptr = array;
	front.index = 0;
	back.ptr = array;
	back.index = 0;
	temp_ptr.ptr = NULL;
	temp_ptr.index = NULL;
}

template <typename T>
CircularDynamicArray<T>::CircularDynamicArray(int s) {
	size = capacity = s;
	temp_array = NULL;
	array = new T[capacity] {}; //intialize a dynamic array of capacity 2
	front.ptr = array;
	front.index = 0;
	back.ptr = array;
	back.index = 0;
	temp_ptr.ptr = NULL;
	temp_ptr.index = NULL;
}

template <typename T>
CircularDynamicArray<T>::~CircularDynamicArray() {
	//delete stuff
}

template <typename T>
void CircularDynamicArray<T>::addEnd(T x) {
	if (size == capacity) {
		grow();
	}
	if (back.index > capacity) {
		back.index -= capacity;
		back.ptr -= capacity;
		*back.ptr = x;
		back.ptr++;
		back.index++;
	}
	if (size == 0) { //base case
		*back.ptr = x;
	}
	else {
		back.ptr++;
		back.index++;
		*back.ptr = x;
	}
	size += 1;
	cout << "I just added " << x << endl;
	printArray();
	printFrontBack();
}

template <typename T>
void CircularDynamicArray<T>::addFront(T x) {
	if (size == capacity) {
		grow();
	}
	if (size == 0) {
		addEnd(x);
		size--; //this is just to subtract from the addition made in addEnd
	}
	else {
		front.index--;
		if (front.index < 0) { // if just growed, dont do this?
			front.index += capacity; // need mod formula here
			front.ptr += capacity - 1; // front.ptr %= capacity
		}
		else {
			front.ptr--;
		}
		*front.ptr = x;
	}
	/*else {
		*front.ptr = x;
	}*/
	cout << "I just added " << x << endl;
	size += 1;
	printArray();
	printFrontBack();
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
	//cout << "[";
	//int i = 0;
	//if (front.index == back.index) { //happens when array is size = 1 (in the beginning)
	//	temp_ptr = front;
	//	cout << *temp_ptr.ptr;
	//}
	//else {
	//	for (temp_ptr = front; temp_ptr.index != back.index; temp_ptr.index++, temp_ptr.ptr++) {
	//		if (temp_ptr.index > size - 1) {
	//			temp_ptr.index -= size;
	//			temp_ptr.ptr -= size;
	//			cout << *temp_ptr.ptr;
	//			if (temp_ptr.index == back.index) {
	//				break;
	//			}
	//		}
	//		else {
	//			cout << *temp_ptr.ptr;
	//		}
	//		i++;
	//		//cout << "im printingggg" << endl;
	//	}
	//}
	//if (i < capacity - 1)
	//	cout << ", ";
	//cout << "]" << endl;
}

template <typename T>
void CircularDynamicArray<T>::printFrontBack() {
	cout << "HEAD: " << *front.ptr << endl;
	cout << "HEAD INDEX: " << front.index << endl;
	cout << "BACK: " << *back.ptr << endl;
	cout << "BACK INDEX: " << back.index << endl;
}

template <typename T>
void CircularDynamicArray<T>::grow() {
	capacity *= 2;
	temp_array = new T[capacity] {}; //intialize a larger dynamic array of capacity c
	//for (int i = 0; i < capacity / 2; i++) {
	//	temp_array[i] = array[i];
	//	cout << "im growinggg" << endl;~
	//}
	int i = 0;
	if (front.index == back.index) { //happens when array is size = 1 (in the beginning)
		temp_ptr = front;
		temp_array[i] = *temp_ptr.ptr;
		cout << "im growinggg" << endl;
	}
	else { //if front before back
		for (temp_ptr = front; i < capacity / 2; i++) {
			if (temp_ptr.index > size - 1) {
				temp_ptr.index -= size;
				temp_ptr.ptr -= size;
				temp_array[i] = *temp_ptr.ptr;
				if (temp_ptr.index == back.index) {
					break;
				}
			}
			else {
				temp_array[i] = *temp_ptr.ptr;
			}
			cout << "im growinggg" << endl;
			temp_ptr.index++;
			temp_ptr.ptr++;
		}
	}
	//else if (back.index < front.index) { //if back before front
	//	for (temp_ptr = back; temp_ptr.index != front.index; temp_ptr.index--) {
	//		int i = capacity / 2;
	//		//temp_ptr.index--;
	//		if (temp_ptr.index < 0) {
	//			temp_ptr.index += capacity;
	//			temp_ptr.ptr += capacity;
	//		}
	//		else {
	//			temp_ptr.ptr--;
	//		}
	//		temp_array[i] = *temp_ptr.ptr;
	//		i--;
	//		cout << "im growinggg" << endl;
	//	}
	//}
	array = temp_array;
	front.index = 0;
	front.ptr = array;
	back.index = 0; 
	back.index += (size - 1); //can't be += size , could be index % size
	back.ptr = array; 
	back.ptr += (size - 1); 
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