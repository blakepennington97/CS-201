#include <iostream>
#include "CDA.cpp"
using namespace std;

template <typename T, typename T2>
struct Node {
	Node* parent; 
	Node* child; //pointer to left most child
	Node* sibling; //pointer to right sibling of node. if root, points to another root of heap
	T key;
	T2 value;
	int degree;
};


template <typename T, typename T2>
class BHeap {
private:
	Node<T, T2> *head;
	int size;

	void initNode(Node<T, T2> *node, T k, T2 v, int degree) {
		node->key = k;
		node->value = v;
		node->degree = degree;
		node->parent = nullptr;
		node->child = nullptr;
		node->sibling = nullptr;
	}

	static void mergeTrees(Node<T, T2> *first, Node<T, T2> *second) {
		second->parent = first;
		second->sibling = first->child;
		first->child = second;
		first->degree += 1;
	}



public:
	void setHead(Node<T, T2>* head) {
		this->head = head;
	}
	BHeap() {
		head = nullptr;
	}
	BHeap(T *k, T2 *v, int s) {

	}
	~BHeap() {

	}
	T peekKey() { //returns min key
		Node<T, T2> *temp = head;
		T smallest = head->key;
		while (temp != nullptr) {
			if (temp->key < smallest) {
				smallest = temp->key;
			}
			temp = temp->sibling;
		}
		return smallest;
	}
	T2 peekValue() {

	}
	T extractMin() {
		Node<T, T2>* current = head;
		Node<T, T2>* prev_min = nullptr;
		Node<T, T2>* min_ptr = nullptr;
		Node<T, T2>* prev_ptr = nullptr;
		T min = current->key;

		while (current != nullptr) {
			if (current->key <= min) {
				min = current->key;
				prev_min = prev_ptr;
				min_ptr = current;
			}
			prev_ptr = current;
			current = current->sibling;
		}


		//now delete
		if (prev_min != nullptr && min_ptr->sibling != nullptr) {
			prev_min->sibling = min_ptr->sibling;
		}
		else if (prev_min != nullptr && min_ptr->sibling == nullptr) {
			prev_min->sibling = nullptr;
		}

		//remove parent ptr from all children
		Node<T, T2>* child_ptr = min_ptr->child;
		while (child_ptr != nullptr) {
			child_ptr->parent = nullptr;
			child_ptr = child_ptr->sibling;
		}

		//now reverse order
		CDA<Node<T, T2>*> arr;
		child_ptr = min_ptr->child;
		while (child_ptr != nullptr) {
			arr.AddEnd(child_ptr);
			child_ptr = child_ptr->sibling;
		}

		current = arr[arr.Length() - 1];
		Node<T, T2>* temp = current;
		arr.DelEnd();

		while (arr.Length() != 0) {
			current->sibling = arr[arr.Length() - 1];
			arr.DelEnd();
			current = current->sibling;
		}

		current->sibling = nullptr;

		BHeap<T, T2> heap;
		heap.head = temp;
		merge(heap);
		size--;
		return min_ptr->key;
	}
	void insert(T k, T2 v) {
		BHeap new_heap;
		Node<T, T2> *temp = new Node<T, T2>;
		initNode(temp, k, v, 0);

		if (size == 0) {
			head = temp;
			cout << "i should only print once." << endl;
		}

		//head = temp; //could be wrong
		new_heap.head = temp; //could be wrong
		//new_heap.setHead(temp);
		merge(new_heap);
		size++;
	}
	void merge(BHeap<T, T2> &H2) {
		Node<T, T2> *first = this->head;
		Node<T, T2> *second = H2.head;
		Node<T, T2> *third = nullptr;
		Node<T, T2> *temp = nullptr;

		//only 1 heap (occurs on first insertion)
		if (first == second) {
			return;
		}

		//if original first tree <= second original tree, point first to second & third to first
		if (first->degree <= second->degree) {
			third = first;
			first = first->sibling;
		}
		else {
			third = second;
			second = second->sibling;
		}

		temp = third;

		//now merge two heaps
		while (first != nullptr && second != nullptr) {
			if (first->degree <= second->degree) {
				third->sibling = first;
				first = first->sibling;
			}
			else {
				third->sibling = second;
				second = second->sibling;
			}
			third = third->sibling;
		}

		//copy all trees of first heap
		if (first != nullptr) { 
			while (first != nullptr) {
				third->sibling = first;
				first = first->sibling;
				third = third->sibling;
			}
		}

		//copy all trees of second heap
		if (second != nullptr) {
			while (second != nullptr) {
				third->sibling = second;
				second = second->sibling;
				third = third->sibling;
			}
		}

		//search merged list and merge all trees with same degree
		third = temp;
		Node<T, T2> *prev = nullptr;
		Node<T, T2> *next = third->sibling;

		while (next != nullptr) {
			//if two||three adjacent trees have same degree, move to next tree
			if ((third->degree != next->degree) || (next->sibling != nullptr && third->degree == next->sibling->degree)) {
				prev = third;
				third = next;
			}
			//else merge trees with same degree
			else {
				if (third->key <= next->key) {
					third->sibling = next->sibling;
					mergeTrees(third, next);
				}
				else {
					if (prev == nullptr) {
						temp = next;
					}
					else {
						prev->sibling = next;
					}

					mergeTrees(next, third);
					third = next;
				}
			}

			next = third->sibling;
		}

		head = temp;
	}
	void printKey() {
		Node<T, T2> *current = head;
		
		while (current != nullptr) {
			cout << "B" << current->degree << endl; //print tree degree
			CDA<Node<T, T2>*> arr;
			arr.AddEnd(current); //can I change this to .AddEnd?

			while (arr.Length() != 0) {
				Node<T, T2>* temp = arr[0];
				arr.DelEnd(); //TODO: REMOVE ITEM HERE, DelFront or DelBack>?
				cout << temp->key << " ";

				//now traverse tree down
				if (temp->child != nullptr) {
					Node<T, T2> *temp2 = temp->child;
					//now traverse tree down
					while (temp2 != nullptr) {
						arr.AddEnd(temp2); //need to change this to AddFront?
						cout << temp2->key << " ";
						temp2 = temp2->child;
					}
					//now traverse upwards and sideways
					temp2 = arr[arr.Length() - 1];
					//temp2 = temp2->sibling;
					while (temp2->parent != nullptr) {
						if (temp2->sibling != nullptr) {
							temp2 = temp2->sibling;
							cout << temp2->key << " ";
							if (temp2->child != nullptr) {
								temp2 = temp2->child;
								cout << temp2->key << " ";
							}
						}
						else {
							temp2 = temp2->parent;
							arr.DelEnd();
						}
					}
				}
			}

			current = current->sibling;
			cout << endl << endl;
		}
	}
};