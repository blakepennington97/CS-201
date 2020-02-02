#pragma once
template <typename T>
struct Node {
	int index;
	T* ptr;
};


template <typename T>
class CDA {
	private:
		int size;
		int capacity;
		bool ordered;
		T* array;
		T* temp_array;
		Node <T> temp_ptr;
		Node <T> front;
		Node <T> back;
		void grow();
		void shrink();
		int Partition(int left, int right, int pivot_index);
		int QuickSelect(int left, int right, int k);
		void printArray();
		void printFrontBack();
	public:
		CDA();
		CDA(int s);
		~CDA();
		T& operator[](int i);
		void AddEnd(T x);
		void AddFront(T x);
		void DelEnd();
		void DelFront();
		int Length();
		bool Ordered();
		int SetOrdered();
		T Select(int k);
		void InsertionSort();
};

