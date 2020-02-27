#include <iostream>
using namespace std;

struct Node
{
    char key;
    int value;
    int color; //0 = black, 1 = red
    Node* parent;
    Node* left;
    Node* right;
};


class RBTree {
private:
    Node* root;
    Node* pit;

    void leftRotate(Node* x)
    {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != pit)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            this->root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != pit)
        {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NULL)
        {
            this->root = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
    void insertFix(Node* k) {
        Node* u;
        while (k->parent->color == 1)
        {
            if (k->parent == k->parent->parent->right)
            {
                u = k->parent->parent->left;
                if (u->color == 1)
                {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->left)
                    {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            }
            else
            {
                u = k->parent->parent->right;

                if (u->color == 1)
                {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->right)
                    {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root)
            {
                break;
            }
        }
        root->color = 0;
    }

    void printHelper(Node* root, string indent, bool last)
    {
        if (root != pit)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "|  ";
            }

            string sColor = root->color ? "RED" : "BLACK";
            cout << root->value << " " << root->key << "(" << sColor << ")" << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }
public:
    RBTree() {
        pit = new Node;
        pit->color = 0;
        pit->left = NULL;
        pit->right = NULL;
        root = pit;
    }
    void printTree()
    {
        if (root)
        {
            printHelper(this->root, "", true);
        }
    }

    void insert(char k, int v) {
        Node* node = new Node;
        node->parent = NULL;
        node->left = pit;
        node->right = pit;
        node->key = k;
        node->value = v;
        node->color = 1;

        Node* y = NULL;
        Node* x = this->root;

        while (x != pit) {
            y = x;
            if (node->value < x->value) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        }
        else if (node->value < y->value) {
            y->left = node;
        }
        else {
            y->right = node;
        }

        //recoloring stage
        if (node->parent == NULL) {
            node->color = 0; //set to black
            return;
        }
        if (node->parent->parent == NULL) {
            return;
        }

        insertFix(node);
    }

};
