#include <iostream>
#include <random>
using namespace std;

template <typename T>
struct Node_Type {
	int index;
	T* ptr;
};


template <typename T>
class CDA {
private:
	int size;
	int capacity;
	int ordered;
	T junk;
	T* array;
	T* temp_array;
	Node_Type <T> temp_ptr;
	Node_Type <T> front;
	Node_Type <T> back;
public:
	CDA() {
		size = 0;
		capacity = 1;
		ordered = false;
		temp_array = NULL;
		array = new T[capacity]{}; //initialize a dynamic array of capacity 2
		front.ptr = array;
		front.index = 0;
		back.ptr = array;
		back.index = 0;
		temp_ptr.ptr = NULL;
		temp_ptr.index = 0;
	}

	CDA(int s) {
		size = s;
		capacity = s;
		ordered = false;
		temp_array = NULL;
		array = new T[capacity]{}; //intialize a dynamic array of capacity s
		front.ptr = array;
		front.index = 0;
		back = front;
		if (size != 0) {
			back.ptr += size - 1;
			back.index += size - 1;
		}
		else {
			back.ptr = array;
			back.index = 0;
		}
		temp_ptr.ptr = NULL;
		temp_ptr.index = 0;
		printArray();
	}

	~CDA() {
		//delete stuff
		//delete[]array;
	}

	T& operator[](int i) {
		if (i > capacity) {
			cout << "INDEX OUT OF BOUNDS" << endl;
			return junk;
		}
		else {
			if (front.index == 0) {
				return array[front.index + i];
			}
			else if (back.index < front.index) {
				return array[(front.index + i) % capacity];
			}
			else {
				return array[(front.index + i)];
			}
		}
	}

	void AddEnd(T x) {
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
		//cout << "I just added " << x << endl;
		printArray();
		printFrontBack();

		if (ordered == 1) {
			SetOrdered();
		}
	}

	void AddFront(T x) {
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
		//cout << "I just added " << x << endl;
		size += 1;
		printArray();
		printFrontBack();

		if (ordered == 1) {
			SetOrdered();
		}
	}

	void DelEnd() {
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
		//cout << "I just deleted end" << endl;

		if (size > 0) {
			if ((double(size) / double(capacity)) <= 0.25) {
				shrink();
			}
		}
		printArray();
		printFrontBack();
	}

	void DelFront() {
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
		//cout << "I just deleted front" << endl;
		if (size > 0) {
			if ((double(size) / double(capacity)) <= 0.25) {
				shrink();
			}
		}
		printArray();
		printFrontBack();
	}

	int Length() {
		return size;
	}

	int Capacity() {
		return capacity;
	}

	void Clear() {
		delete[] array;
		size = 0;
		capacity = 1;
		ordered = -1;
		temp_array = NULL;
		array = new T[capacity]{}; //intialize a dynamic array of capacity 1
		front.ptr = array;
		front.index = 0;
		back = front;
		back.ptr = array;
		back.index = 0;
		temp_ptr.ptr = NULL;
		temp_ptr.index = NULL;
	}

	bool Ordered() {
		return ordered;
	}

	int SetOrdered() {
		//temp_array = new T[Length()]{};

		//for (int i = 0; i < Length(); i++) {
		//	if (front.index == 0) {
		//		temp_array[i] = array[front.index + i];
		//	}
		//	else if (back.index < front.index) {
		//		temp_array[i] = array[(front.index + i) % capacity];
		//	}
		//	else {
		//		temp_array[i] = array[(front.index + i)];
		//	}
		//}
		////iterate through array to check if array is ordered
		//ordered = true;
		//for (int i = 0; i < (Length() - 1); i++) {
		//	if (temp_array[i] < temp_array[i + 1]) {
		//		/*cout << "size = " << Length() << endl;
		//		cout << "i = " << i << endl;
		//		cout << temp_array[i] << " < " << temp_array[i + 1] << endl;*/
		//		continue;
		//	}
		//	else {
		//		//cout << "ORDERED IS FALSE" << endl;
		//		ordered = false;
		//		return -1;
		//	}
		//}
		return 1;
	}


	T Select(int k) {
		if (ordered == 1) {
			return array[k - 1];
		}
		else {
			//build array front -> back
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
			return QuickSelect(0, Length(), k);
		}
	}

	void InsertionSort() {
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

	void QuickSort() {
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
		//perform algo
		int left = 0;
		int right = Length() - 1;
		int* stack = new int[right - left + 1];
		int top = -1;
		stack[++top] = left;
		stack[++top] = right;

		while (top >= 0) {
			right = stack[top--];
			left = stack[top--];

			// select a pivotIndex between left and right --> CHANGE TO MEDIAN OF THREE
			int pivot_index = left + rand() % (right - left + 1);
			pivot_index = Partition(left, right, pivot_index);

			if (pivot_index - 1 > left) {
				stack[++top] = left;
				stack[++top] = pivot_index - 1;
			}

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
		//cout << "quicksortinggg..." << endl;
	}


	void printArray() {
		/*cout << "[";
		for (int i = 0; i < capacity; i++) {
			cout << array[i];
			if (i < capacity - 1)
				cout << ", ";
		}
		cout <<  "]" << endl;*/
	}

	void printFrontBack() {
		//cout << "HEAD: " << *front.ptr << endl;
		//cout << "BACK: " << *back.ptr << endl;
		//cout << "head index: " << front.index << endl;
		//cout << "back index: " << back.index << endl;
	}

	void grow() {
		capacity *= 2;
		temp_array = new T[capacity]{}; //intialize a larger dynamic array of capacity c
		int i = 0;
		if (front.index == back.index) { //happens when array is size = 1 (in the beginning)
			temp_ptr = front;
			temp_array[i] = *temp_ptr.ptr;
			//cout << "im growinggg" << endl;
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
				//cout << "im growinggg" << endl;
				temp_ptr.index++;
				temp_ptr.ptr++;
			}
		}
		array = temp_array;
		front.index = 0;
		front.ptr = array;
		back.index = 0;
		back.index += (size - 1);
		back.ptr = array;
		back.ptr += (size - 1);
		//cout << "new capacity = " << capacity << endl;
	}

	void shrink() {
		capacity /= 2;
		temp_array = new T[capacity]{}; //intialize a smaller dynamic array of capacity c
		int i = 0;
		if (front.index == back.index) { //happens when array is size = 1
			temp_ptr = front;
			temp_array[i] = *temp_ptr.ptr;
			//cout << "im shrinkinggg" << endl;
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
				//cout << "im shrinkinggg" << endl;
				temp_ptr.index++;
				temp_ptr.ptr++;
			}
		}
		array = temp_array;
		front.index = 0;
		front.ptr = array;
		back.index = 0;
		back.index += (size - 1);
		back.ptr = array;
		back.ptr += (size - 1);
		//cout << "new capacity = " << capacity << endl;
	}

	int Partition(int left, int right, int pivot_index) {
		T pivot = temp_array[pivot_index];
		swap(temp_array[pivot_index], temp_array[right]);

		int p_index = left;
		int i;

		for (i = left; i < right; i++)
		{
			if (temp_array[i] <= pivot)
			{
				swap(temp_array[i], temp_array[p_index]);
				p_index++;
			}
		}

		swap(temp_array[p_index], temp_array[right]);
		return p_index;
	}

	int QuickSelect(int left, int right, int k) {
		if (left == right)
			return temp_array[left];

		int pivot_index = left + rand() % (right - left + 1);
		pivot_index = Partition(left, right, pivot_index);

		if (k == pivot_index)
			return temp_array[k];

		else if (k < pivot_index)
			return QuickSelect(left, pivot_index - 1, k);

		else
			return QuickSelect(pivot_index + 1, right, k);
	}

	int Search(T e) {
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

		if (ordered == 1) {
			return binarySearch(0, Length(), e);
		}
		else {
			//linear search
			for (int i = 0; i < Length(); i++) {
				if (temp_array[i] == e) {
					return i;
				}
			}
		}
		return -1;
	}

	void CountingSort(int m) {
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
		int* output = new int[Length()];
		int* count = new int[Length()];
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

	int binarySearch(int left, int right, T e) {
		if (right >= left) {
			int mid = left + (right - left) / 2;

			if (temp_array[mid] == e)
				return mid;

			if (temp_array[mid] > e)
				return binarySearch(left, mid - 1, e);

			return binarySearch(mid + 1, right, e);
		}
	}
};
