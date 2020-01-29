#pragma once
template <typename T>
struct Node {
	int index;
	T* ptr;
};


template <typename T>
class CircularDynamicArray {
	private:
		int size;
		int capacity;
		T* array;
		T* temp_array;
		Node <int> temp_ptr;
		Node <int> front;
		Node <int> back;
		void grow();
	public:
		CircularDynamicArray();
		CircularDynamicArray(int s);
		~CircularDynamicArray();
		void addEnd(T x);
		void addFront(T x);
		void printArray();
		void printFrontBack();
};

