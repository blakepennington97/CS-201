#include "CircularDynamicArray.h"
#include <iostream>
using namespace std;

template <typename T>
CDA<T>::CDA() {
	size = 0;
	capacity = 1;
	ordered = false;
	temp_array = NULL;
	array = new T[capacity] {}; //initialize a dynamic array of capacity 2
	front.ptr = array;
	front.index = 0;
	back.ptr = array;
	back.index = 0;
	temp_ptr.ptr = NULL;
	temp_ptr.index = NULL;
}

template <typename T>
CDA<T>::CDA(int s) {
	size = capacity = s;
	ordered = false;
	temp_array = NULL;
	array = new T[capacity] {}; //intialize a dynamic array of capacity s
	front.ptr = array;
	front.index = 0;
	back = front;
	back.ptr += size - 1;
	back.index += size - 1;
	temp_ptr.ptr = NULL;
	temp_ptr.index = NULL;
	printArray();
}

template <typename T>
CDA<T>::~CDA() {
	//delete stuff
}

template <typename T>
T&CDA<T>::operator[](int i) {
	if (i > capacity) {
		cout << "INDEX TOO LARGE HOMIE" << endl;
		//need to do more here as said by Dixon in class, something about creating a dummy variable to assign??
		return array[0]; // idk??
	}
	else {
		//temp_ptr = front;
		if (front.index == 0) {
			return array[front.index + i];
		}
		else if (back.index < front.index) {
			return array[(front.index + i) % capacity];
		}
		else {
			return array[(front.index + i)];
		}
		//else if (temp_ptr.index + i > capacity - 1) { // > capacity % (temp_ptr.index - 1)
		//	cout << "HIT" << endl;
		//	//temp_ptr.index = (i % size) + 1;
		//	temp_ptr.index = (i % size);
		//	//temp_ptr.index = ((temp_ptr.index + i) % capacity);
		//	//temp_ptr.ptr -= ((temp_ptr.index + i) % capacity);
		//	return array[temp_ptr.index];
		//}
		//else {
		//	return array[temp_ptr.index + i];
		//}
	}
	/*if (temp_ptr.index > size - 1) {
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
	temp_ptr.ptr++;*/
}

template <typename T>
void CDA<T>::AddEnd(T x) {
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
void CDA<T>::AddFront(T x) {
	if (size == capacity) {
		grow();
	}
	if (size == 0) {
		AddEnd(x);
		size--; //this is just to subtract from the addition made in addEnd
	}
	else {
		front.index--;
		if (front.index < 0) {
			front.index += capacity; 
			front.ptr += capacity - 1; 
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
void CDA<T>::DelEnd() {
	if (size == 0) {
		size++; //to nullify the size-- at the end of this function
	}
	else if (back.index == 0) {
		back.index += size - 1;
		back.ptr += size - 1;
	}
	else {
		back.index--;
		back.ptr--;
	}
	size--;
	//capacity--; //added because if I have [0 1 2 3 4 5 6 7 8 9], i DelEnd(9), then i attempt to add front, it will not grow because capacity it still believed to be 10
	cout << "I just deleted end" << endl;

	cout << ((double(size) / double(capacity))) << endl;
	if (size > 1) {
		if ((double(size) / double(capacity)) <= 0.25) {
			/*if (size == 1) {
				break;
			}*/
			shrink();
		}
		/*if (not ordered) {
			order()
		}*/
	}
	printArray();
	printFrontBack();
}

template <typename T>
void CDA<T>::DelFront() {
	if (size == 0) {
		size++; //to nullify the size-- at the end of this function
	}
	else if (front.index == capacity - 1) {
		front.index -= capacity - 1;
		front.ptr -= capacity - 1;
	}
	else {
		front.index++;
		front.ptr++;
	}
	size--;
	cout << "I just deleted front" << endl;

	cout << ((double(size) / double(capacity))) << endl;
	if (size > 1) {
		if ((double(size) / double(capacity)) <= 0.25) {
			/*if (size == 1) {
				break;
			}*/
			shrink();
		}
		/*if (not ordered) {
			order()
		}*/
	}
	printArray();
	printFrontBack();
}

template <typename T>
int CDA<T>::Length() {
	return size;
}

template <typename T>
void CDA<T>::printArray() {
	cout << "[";
	for (int i = 0; i < capacity; i++) {
		cout << array[i];
		if (i < capacity - 1)
			cout << ", ";
	}
	cout <<  "]" << endl;
}

template <typename T>
void CDA<T>::printFrontBack() {
	cout << "HEAD: " << *front.ptr << endl;
	cout << "BACK: " << *back.ptr << endl;
	cout << "head index: " << front.index << endl;
	cout << "back index: " << back.index << endl;
}

template <typename T>
void CDA<T>::grow() {
	capacity *= 2;
	temp_array = new T[capacity] {}; //intialize a larger dynamic array of capacity c
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
	array = temp_array;
	front.index = 0;
	front.ptr = array;
	back.index = 0; 
	back.index += (size - 1); //can't be += size , could be index % size
	back.ptr = array; 
	back.ptr += (size - 1); 
	cout << "new capacity = " << capacity << endl;
}

template <typename T>
void CDA<T>::shrink() {
	capacity /= 2;
	temp_array = new T[capacity]{}; //intialize a smaller dynamic array of capacity c
	int i = 0;
	if (front.index == back.index) { //happens when array is size = 1
		temp_ptr = front;
		temp_array[i] = *temp_ptr.ptr;
		cout << "im shrinkinggg" << endl;
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
			cout << "im shrinkinggg" << endl;
			temp_ptr.index++;
			temp_ptr.ptr++;
		}
	}
	array = temp_array;
	front.index = 0;
	front.ptr = array;
	back.index = 0;
	back.index += (size - 1); //can't be += size , could be index % size
	back.ptr = array;
	back.ptr += (size - 1);
	cout << "new capacity = " << capacity << endl;
}