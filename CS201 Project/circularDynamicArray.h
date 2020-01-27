#pragma once
template <typename T>
class CircularDynamicArray {
	private:
		int size;
		int capacity;
		T* array;
		T* temp_array;
		T* front_ptr;
		T* back_ptr;
		T* temp_ptr;
		void grow(bool x);
	public:
		CircularDynamicArray();
		CircularDynamicArray(int s);
		~CircularDynamicArray();
		void addEnd(T x);
		void addFront(T x);
		void printArray();
		void printFrontBack();
};

