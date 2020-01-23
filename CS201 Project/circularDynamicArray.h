#pragma once
class CircularDynamicArray {
private:
	int size;
	int capacity;
	int* front_ptr = nullptr;
	int* back_ptr = nullptr;
	int* temp_ptr = nullptr;
	void grow();
public:
	CircularDynamicArray();
	CircularDynamicArray(int s);
	~CircularDynamicArray();
	void addEnd(int x);
	void addFront(int x);
	void printArray();
};

