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
		Node <T> temp_ptr;
		Node <T> front;
		Node <T> back;
		void grow();
	public:
		CircularDynamicArray();
		CircularDynamicArray(int s);
		~CircularDynamicArray();
		T& operator[](int i);
		void addEnd(T x);
		void addFront(T x);
		void printArray();
		void printFrontBack();
};

