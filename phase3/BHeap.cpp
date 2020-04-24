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

	void addChild(Node<T, T2>* childNode)
	{
		if (childNode)
		{
			childNode->sibling = nullptr;
			if (child)
			{
				Node<T, T2>* temp = child;
				while (temp->sibling)
				{
					temp = temp->sibling;
				}
				temp->sibling = childNode;
			}
			else
			{
				child = childNode;
			}
			//
			++degree;
			childNode->parent = this;
		}
	}
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
	
	int order(Node<T, T2>* heap)
	{
		if (!heap)
			return -1;
		int i = 0;
		Node<T, T2>* child = heap->child;
		while (child)
		{
			++i;
			child = child->sibling;
		}
		return i;
	}



public:
	void setHead(Node<T, T2>* head) {
		this->head = head;
	}

	Node<T, T2>* getHead() {
		return head;
	}

	BHeap() {
		head = nullptr;
	}
	BHeap(T *k, T2 *v, int s) {
		for (int i = 0; i < s; i++) {
			insert(k[i], v[i]);
		}
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
		Node<T, T2>* temp = head;
		Node<T, T2>* match = head;
		T smallest = head->key;
		while (temp != nullptr) {
			if (temp->key < smallest) {
				smallest = temp->key;
				match = temp;
			}
			temp = temp->sibling;
		}
		return match->value;
	}
	T extractMin() {
		Node<T, T2>* prev = nullptr,
			* min = nullptr,
			* temp = nullptr,
			* next = nullptr;
		T minValue;
		if (head) {
			Node<T, T2>* minPrev = nullptr; //previous node of min node
			min = head;
			temp = head->sibling;
			prev = head;

			//Find min and minPrev of heaps
			while (temp) {
				if (temp->key < min->key) {
					min = temp;
					minPrev = prev;
				}
				prev = prev->sibling;
				temp = temp->sibling;
			}
			/*
			 *  If prev, assign prev sibling to min sibling.
			 *  Else if no prev min->sibling is new head
			 */
			if (minPrev) {
				minPrev->sibling = min->sibling;
			}
			else {
				head = min->sibling;
			}
			/*
			 * Update all children nodes parent pointers to null
			*/
			next = min->child;
			temp = next;
			while (temp) {
				temp->parent = min->parent;
				temp = temp->sibling;
			}
			/*
			 * Detach and delete min
			 */
			min->sibling = nullptr;
			min->child = nullptr;
			min->parent = nullptr;
			minValue = min->key;
			delete min;
			/*
			 * Union the two detached heaps
			 */
			head = unionHeap(head, next);
			temp = min = minPrev = next = nullptr;
		}
		else {
			cout << "empty heap" << endl;
		}

		return minValue;
	}
	void insert(T k, T2 v) {
		Node<T, T2>* new_node = new Node<T, T2>;
		Node<T, T2>* old;
		if (head) {
			old = head->parent;
		}
		else {
			head = nullptr;
		}
		initNode(new_node, k, v, 0);
		head = unionHeap(new_node, head);
		size++;
	}
	void merge(BHeap<T, T2> &H2) {
		Node<T, T2>* first = getHead();
		Node<T, T2>* second = H2.getHead();
		Node<T, T2>* third = nullptr;
		Node<T, T2>* temp = nullptr;

		//only 1 heap (occurs on first insertion)
		//if (first == second) {
		////	return;
		//}

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
		Node<T, T2>* prev = nullptr;
		Node<T, T2>* next = third->sibling;

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

	Node<T,T2>* mergeHeap(Node<T, T2>* heapA, Node<T, T2>* heapB) {
		//heapA = head, heapB = next
		//modify to insert
		Node<T, T2>* heapM = nullptr;//merged heap

		if (heapA || heapB) {
			if (heapA && !heapB) {
				heapM = heapA;
			}
			else if (!heapA && heapB) {
				heapM = heapB;
			}
			else {
				Node<T, T2>* temp = nullptr,
					* next = nullptr,
					* prev = nullptr,
					* cur = nullptr;
				//pick minimum heap root to be merged heap root
				if (heapA->degree >= heapB->degree) {
					heapM = heapB;
					next = heapA;
				}
				else {
					heapM = heapA;
					next = heapB;
				}
				cur = heapM;
				//Merges heap by reassigning sibling pointers

				//PROBLEM (doesnt disonnect E tree from C)
				while (cur && next && cur != next) {
					if (cur->degree <= next->degree) {
						if (cur->sibling) {
							temp = cur->sibling;
							cur->sibling = next;
							prev = cur;
							cur = next;
							next = temp;
						}
						else {
							cur->sibling = next;
							cur = next; // break loop
						}
					}
					else {
						if (prev)
							prev->sibling = next;
						else
							heapM = next;
						temp = next->sibling;
						next->sibling = cur;
						prev = next;
						next = temp;

					}
				}
			}

			//	//copy trees
			//	if (cur != nullptr) {
			//		// copy all the remaining trees of heap1
			//		while (cur != nullptr) {
			//			curr3->sibling = curr1;
			//			cur = cur->sibling;
			//			curr3 = curr3->sibling;
			//		}
			//	}

			//	if (next != nullptr) {
			//		// copy all the remaining trees of heap2
			//		while (curr2 != nullptr) {
			//			curr3->sibling = curr2;
			//			curr2 = curr2->sibling;
			//			curr3 = curr3->sibling;
			//		}
			//	}

			//	// scan the merged list and repeatedly merge binomial trees with same degree
			//	cur = temp;
			//	prev = nullptr;
			//	next = cur->sibling;

			//	while (next != nullptr) {
			//		// if two adjacent tree roots have different degree or 3 consecutive roots have same degree
			//		// move to the next tree
			//		if ((cur->degree != next->degree) || (next->sibling != nullptr && cur->degree == next->sibling->degree)) {
			//			prev = cur;
			//			cur = next;
			//		}
			//		else {
			//			// otherwise repeatdly merge binomial trees with same degree
			//			if (cur->key <= next->key) {
			//				cur->sibling = next->sibling;
			//				mergeTrees(cur, next);
			//			}
			//			else {
			//				if (prev == nullptr) {
			//					temp = next;
			//				}
			//				else {
			//					prev->sibling = next;
			//				}

			//				mergeTrees(next, cur);
			//				cur = next;
			//			}
			//		}

			//		next = cur->sibling;
			//	}
			//	heapM = temp;
			//}
			//heapM = temp;
		}

		return heapM;
	}

	void printKey() {
		Node<T, T2>* current = head;
		Node<T, T2>* temp = head;
		CDA<Node<T, T2>*> arr;
		
		while (current != nullptr) {
			cout << "B" << current->degree << endl << current->key << " ";
			temp = current;

			while (temp != nullptr && temp->degree != 0) {
				//go down as much as possible
				temp = temp->child;
				//if reached bottom addEnd
				if (temp->child == nullptr) {
					arr.AddEnd(temp);
					//if (no sibling) go up & addEnd & go right
					if (temp->sibling == nullptr) {
						//added for 2 node tree
						if (temp->parent == current) {
							break;
						}
						temp = temp->parent;
						arr.AddEnd(temp);
						//we hit the bottom right end, now finish and traverse up
						if (temp->sibling == nullptr) {
							while (temp->parent != current) {
								temp = temp->parent;
								arr.AddEnd(temp);
							}
							break;
						}
						else {
							temp = temp->sibling;
						}
					}
					else {
						temp = temp->sibling;
					}
				}
			}
			for (int i = arr.Length() - 1; i >= 0; i--) {
				cout << arr[i]->key << " ";
				arr.DelEnd();
			}
			cout << endl << endl;
			current = current->sibling;
		}	
	}
		

	Node<T, T2>* unionHeap(Node<T, T2>* heapA, Node<T, T2>* heapB) {
		/*
	 * Merges heapA (head) and heapB (next) assuming both are sorted by heap order
	 * concatenates heaps of same order so that at most one tree of each order
	*/

	/*
	 * get merged heap of heapA and heapB
	 */
		Node<T, T2 >* heapU = mergeHeap(heapA, heapB);
		bool done_merging = false;
		if (heapU) {
			while (!done_merging) {
				Node<T, T2>
					* cur = heapU,  // current node to append before or after
					* prev = nullptr, // node with sibling equal to current
					* next = nullptr; // the next potential
				int orderA, orderB;

				//now we have cur (root list) of all the promoted nodes, now merge them all!
				while (cur && cur->sibling) {
					next = cur->sibling;
					orderA = cur->degree;
					orderB = next->degree;
					//if matching degrees, merge
					if (orderA == orderB && orderA != order(next->sibling)) {
						//Next becomes Current's Child
						if (cur->key < next->key) {
							cur->sibling = next->sibling;
							cur->addChild(next);
							//tempNext->parent = cur;
							prev = cur;
							cur = cur->sibling;
						}
						//Current becomes Next's Child
						else {
							if (prev)
								prev->sibling = next;
							else
								heapU = next;
							next->addChild(cur);
							prev = next;
							cur = next->sibling;
						}
					}
					else {
						// got to Next's Child
						if (!prev)
							heapU = cur;
						prev = cur;
						cur = next;
					}
				}

				//now check to see if done merging
				cur = heapU;
				int next_degree = 0;
				if (cur->sibling) {
					while (cur->sibling) {
						next_degree = cur->sibling->degree;
						if (cur->degree == next_degree) {
							done_merging = false;
							break;
						}
						else {
							done_merging = true;
							cur = cur->sibling;
						}
					}
				}
				else {
					done_merging = true;
				}
			}
		}
		return heapU;
	}
};