#include "CircularDynamicArray.h"
#include <iostream>
#include <random>
using namespace std;

template <typename T>
CDA<T>::CDA() {
	size = 0;
	capacity = 1;
	ordered = -1;
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
	ordered = -1;
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
	//delete[]array;
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

	if (ordered == 1) {
		SetOrdered();
	}
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

	if (ordered == 1) {
		SetOrdered();
	}
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
	if (ordered == 1) {
		return true;
	}
	return false;
}

template <typename T>
int CDA<T>::SetOrdered() {
	//iterate through array to check if array is ordered
	ordered = 1;
	for (int i = 0; i < Length() - 1; i++) {
		if (array[i] < array[i + 1]) {
			continue;
		}
		else {
			ordered = -1;
		}
	}
	return ordered;
}


template <typename T>
T CDA<T>::Select(int k) {
	if (ordered == 1) {
		return array[k - 1];
	}
	else {
		cout << "quickselecting..." << endl;
		//build array front -> back
		temp_array = new T[Length()] {};

		for (int i = 0; i < Length(); i++) {
			if (front.index == 0) {
				temp_array[i] = array[front.index + i];
			}
			else if (back.index < front.index) {
				temp_array[i] = array[(front.index + i) % capacity];
			}
			else {
				temp_array[i] = array[(front.index + i)];
			}
		}
		for (int i = 0; i < Length(); i++) cout << temp_array[i] << " ";  cout << endl; // print new array
		return QuickSelect(0, Length(), k);
	}
}

template <typename T>
void CDA<T>::InsertionSort() {
	temp_array = new T[Length()]{};

	for (int i = 0; i < Length(); i++) {
		if (front.index == 0) {
			temp_array[i] = array[front.index + i];
		}
		else if (back.index < front.index) {
			temp_array[i] = array[(front.index + i) % capacity];
		}
		else {
			temp_array[i] = array[(front.index + i)];
		}
	}
	//perform insertion sort on array, then set ordered to true
	int key, j;
	for (int i = 1; i < size; i++) {
		key = temp_array[i];//take value
		j = i;
		while (j > 0 && temp_array[j - 1] > key) {
			temp_array[j] = temp_array[j - 1];
			j--;
		}
		temp_array[j] = key;   //insert in right place
	}
	array = temp_array;
	front.index = 0;
	front.ptr = array;
	back.index = 0;
	back.index += (size - 1);
	back.ptr = array;
	back.ptr += (size - 1);
}

template <typename T>
void CDA<T>::QuickSort() {
	temp_array = new T[Length()] {};

	for (int i = 0; i < Length(); i++) {
		if (front.index == 0) {
			temp_array[i] = array[front.index + i];
		}
		else if (back.index < front.index) {
			temp_array[i] = array[(front.index + i) % capacity];
		}
		else {
			temp_array[i] = array[(front.index + i)];
		}
	}
	//for (int i = 0; i < Length(); i++) cout << temp_array[i] << " ";  cout << endl; // print new array
	//perform algo
	// Create an auxiliary stack 
	int left = 0;
	int right = Length() - 1;
	int *stack = new int[right - left + 1];

	// initialize top of stack 
	int top = -1;

	// push initial values of l and h to stack 
	stack[++top] = left;
	stack[++top] = right;
	while (top >= 0) {
		// Pop h and l 
		right = stack[top--];
		left = stack[top--];

		// Set pivot element at its correct position 
		// in sorted array 
		// select a pivotIndex between left and right --> CHANGE TO MEDIAN OF THREE
		int pivot_index = left + rand() % (right - left + 1);

		pivot_index = Partition(left, right, pivot_index);

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (pivot_index - 1 > left) {
			stack[++top] = left;
			stack[++top] = pivot_index - 1;
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (pivot_index + 1 < right) {
			stack[++top] = pivot_index + 1;
			stack[++top] = right;
		}
	}
	//end algo, assign new array & pointers
	array = temp_array;
	front.index = 0;
	front.ptr = array;
	back.index = 0;
	back.index += (size - 1);
	back.ptr = array;
	back.ptr += (size - 1);
	ordered = true;
	printArray();
	printFrontBack();
	cout << "quicksortinggg..." << endl;
}


template <typename T>
void CDA<T>::printArray() {
	/*cout << "[";
	for (int i = 0; i < capacity; i++) {
		cout << array[i];
		if (i < capacity - 1)
			cout << ", ";
	}
	cout <<  "]" << endl;*/
}

template <typename T>
void CDA<T>::printFrontBack() {
	//cout << "HEAD: " << *front.ptr << endl;
	//cout << "BACK: " << *back.ptr << endl;
	//cout << "head index: " << front.index << endl;
	//cout << "back index: " << back.index << endl;
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
		return temp_array[left];

	// select a pivotIndex between left and right
	int pivot_index = left + rand() % (right - left + 1);

	pivot_index = Partition(left, right, pivot_index);

	// The pivot is in its final sorted position
	if (k == pivot_index)
		return temp_array[k];

	// if k is less than the pivot index
	else if (k < pivot_index)
		return QuickSelect(left, pivot_index - 1, k);

	// if k is more than the pivot index
	else
		return QuickSelect(pivot_index + 1, right, k);
}

template <typename T>
T CDA<T>::Search(T e) {
	temp_array = new T[Length()]{};

	for (int i = 0; i < Length(); i++) {
		if (front.index == 0) {
			temp_array[i] = array[front.index + i];
		}
		else if (back.index < front.index) {
			temp_array[i] = array[(front.index + i) % capacity];
		}
		else {
			temp_array[i] = array[(front.index + i)];
		}
	}
	for (int i = 0; i < Length(); i++) cout << temp_array[i] << " ";  cout << endl; // print new array
	if (ordered == 1) {
		//binary search
		return binarySearch(0, Length(), e);
	}
	else {
		//linear search
		for (int i = 0; i < Length(); i++) {
			cout << "looking at " << temp_array[i] << endl;
			if (temp_array[i] == e) {
				return i;
			}
		}
	}
	return -1;
}

template <typename T>
void CDA<T>::CountingSort(int m) {
	temp_array = new T[Length()]{};

	for (int i = 0; i < Length(); i++) {
		if (front.index == 0) {
			temp_array[i] = array[front.index + i];
		}
		else if (back.index < front.index) {
			temp_array[i] = array[(front.index + i) % capacity];
		}
		else {
			temp_array[i] = array[(front.index + i)];
		}
	}
	//algo begins
	int *output = new int[Length()];
	int *count = new int[Length()];
	int max = temp_array[0];
	for (int i = 1; i < m; i++)
	{
		if (temp_array[i] > max)
			max = temp_array[i];
	}
	for (int i = 0; i <= max; ++i)
	{
		count[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		count[temp_array[i]]++;
	}
	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[temp_array[i]] - 1] = temp_array[i];
		count[temp_array[i]]--;
	}
	for (int i = 0; i < size; i++)
	{
		temp_array[i] = output[i];
	}
	array = temp_array;
	front.index = 0;
	front.ptr = array;
	back.index = 0;
	back.index += (size - 1);
	back.ptr = array;
	back.ptr += (size - 1);
}

template <typename T>
int CDA<T>::binarySearch(int left, int right, T e) {
	if (right >= left) {
		int mid = left + (right - left) / 2;

		// If the element is present at the middle 
		// itself 
		if (temp_array[mid] == e)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (temp_array[mid] > e)
			return binarySearch(left, mid - 1, e);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(mid + 1, right, e);
	}
}