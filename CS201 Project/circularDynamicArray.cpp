#include "CircularDynamicArray.h"
#include <iostream>
#include <random>
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
bool CDA<T>::Ordered() {
	return ordered;
}

template <typename T>
int CDA<T>::SetOrdered() {
	//iterate through array to check if array is ordered
	ordered = true;
	for (int i = 0; i < Length() - 1; i++) {
		if (array[i] < array[i + 1]) {
			continue;
		}
		else {
			ordered = false;
		}
	}
	return ordered;
}


template <typename T>
T CDA<T>::Select(int k) {
	if (ordered == true) {
		return array[k - 1];
	}
	else {
		cout << "QUICKSORTING BITCHES" << endl;
		return QuickSelect(front.index, back.index, k);
	}
}

template <typename T>
void CDA<T>::InsertionSort() {
	//perform insertion sort on array, then set ordered to true

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

template <typename T>
int CDA<T>::Partition(int left, int right, int pivot_index) {
	temp_array = array;
	// Pick pivot_index as pivot from the array
	T pivot = temp_array[pivot_index];

	// Move pivot to end
	swap(temp_array[pivot_index], temp_array[right]);

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int p_index = left;
	int i;

	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot.
	for (i = left; i < right; i++)
	{
		if (temp_array[i] <= pivot)
		{
			swap(temp_array[i], temp_array[p_index]);
			p_index++;
		}
	}

	// Move pivot to its final place
	swap(temp_array[p_index], temp_array[right]);

	// return p_index (index of pivot element)
	return p_index;
}

template <typename T>
int CDA<T>::QuickSelect(int left, int right, int k) {
	// If the array contains only one element, return that element
	if (left == right)
		return array[left];

	// select a pivotIndex between left and right
	if (left <= right) {
		int pivot_index = left + rand() % (right - left);
	}
	else { //right > left
		int pivot_index = 0; // work stopped here, 0 is not right
	}

	pivot_index = Partition(left, right, pivot_index);

	// The pivot is in its final sorted position
	if (k == pivot_index)
		return array[k];

	// if k is less than the pivot index
	else if (k < pivot_index)
		return QuickSelect(left, pivot_index - 1, k);

	// if k is more than the pivot index
	else
		return QuickSelect(pivot_index + 1, right, k);
}