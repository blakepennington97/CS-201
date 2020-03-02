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

    void rbTransplant(Node* u, Node* v)
    {
        if (u->parent == nullptr)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteFix(Node* x)
    {
        Node* s;
        while (x != root && x->color == 0)
        {
            if (x == x->parent->left)
            {
                s = x->parent->right;
                if (s->color == 1)
                {
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == 0 && s->right->color == 0)
                {
                    s->color = 1;
                    x = x->parent;
                }
                else
                {
                    if (s->right->color == 0)
                    {
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else
            {
                s = x->parent->left;
                if (s->color == 1)
                {
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == 0 && s->right->color == 0)
                {
                    s->color = 1;
                    x = x->parent;
                }
                else
                {
                    if (s->left->color == 0)
                    {
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 0;
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

    void preorder() {
        Node* temp_root = this->root;
        Node* current;
        Node* pre;

        if (root == pit)
            return;

        current = root;
        while (current != pit) {

            if (current->left == pit) {
                cout << current->key << " ";
                current = current->right;
            }
            else {

                pre = current->left;
                while (pre->right != pit && pre->right != current)
                    pre = pre->right;

                if (pre->right == pit) {
                    pre->right = current;
                    current = current->left;
                }

                else {
                    pre->right = pit;
                    printf("%d ", current->key);
                    current = current->right;
                }
            }
        }
    }
    void printTree()
    {
        if (root)
        {
            printHelper(this->root, "", true);
        }
    }

    Node* minimum(Node* node)
    {
        while (node->left != pit)
        {
            node = node->left;
        }
        return node;
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

    int remove(char k) {
        Node* z = pit;
        Node* node = this->root;
        Node* x;
        Node* y;
        while (node != pit)
        {
            if (node->key == k)
            {
                z = node;
            }

            if (node->key <= k)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }

        if (z == pit)
        {
            cout << "Key not found in the tree" << endl;
            return 0;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == pit)
        {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == pit)
        {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else
        {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0)
        {
            deleteFix(x);
        }
        return 1;
    }

};
