#include "RBTree.cpp"
#include <iostream>
#include <stdio.h>

int main() {
    //RBTree tree;

    //tree.insert('A', 10);
    ////tree.printTree();
    //tree.insert('B', 9);
    ////tree.printTree();
    //tree.insert('C', 8);
    ////tree.printTree();
    //tree.insert('D', 7);
    ////tree.printTree();
    //tree.insert('E', 6);
    //tree.insert('F', 5);
    //tree.insert('G', 4);
    //tree.insert('H', 3);
    //tree.insert('I', 2);
    //tree.insert('K', 1);

    //tree.printTree();
    //tree.inorder();
    //cout << endl;
    //cout << *tree.successor('A') << endl;
    //cout << *tree.successor('B') << endl;
    //cout << *tree.successor('C') << endl;
    //cout << *tree.successor('D') << endl;
    //cout << *tree.successor('E') << endl;
    //cout << *tree.successor('F') << endl;
    //cout << *tree.successor('G') << endl;
    //cout << *tree.successor('H') << endl;
    //cout << *tree.successor('I') << endl;
    //cout << *tree.successor('K') << endl;

    ///*cout << endl;
    //tree.remove('D');
    //tree.preorder();
    //cout << endl;
    //tree.inorder();*/
	char K[10] = { 'A','B','C','D','E','F','G','H','I','K' };
	int V[10] = { 10,9,8,7,6,5,4,3,2,1 };

	RBTree T1, T2(K, V, 10);

	for (int i = 0; i < 10; i++) T1.insert(K[i], V[i]);
	// T1 and T2 should be identical trees

	cout << *(T2.search('C')) << endl;
	// Should output 8

	cout << T1.rank('C') << endl;
	//Should output 3

	cout << T1.select(3) << endl;
	//Should output C 

	T2.preorder();
	//Should output D B A C F E H G I K

	T2.inorder();
	//Should output	A B C D E F G H I K

	cout << T2.remove('D') << endl;
	//Should output 1

	T2.preorder();
	//Should output E B A C H F G I K

	T2.inorder();
	//Should output	A B C E F G H I K

    cout << endl;

    //T2.printTree();

	cout << T2.remove('J') << endl;
	//Should output 0

    //T2.printTree();

	cout << T2.rank('G') << endl;
	//Should output 6

	cout << *(T1.successor('C')) << endl;
	//Should output D

	cout << *(T1.predecessor('C')) << endl;
	//Should output B		
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
