#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    char key;
    int value;
    int color; //0 = black, 1 = red
    int node_size;
    Node* parent;
    Node* left;
    Node* right;
};


class RBTree {
private:
    Node* root;
    Node* pit;
    int tree_size;

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

                if (s->right->color == 0)
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

    int subtree_size(Node* node) {
        if (node == NULL) {
            return 0;
        }
        else {
            node->node_size = 1;
        }
        if (node->left != pit) {
            node->node_size += subtree_size(node->left);
        }
        if (node->right != pit) {
            node->node_size += subtree_size(node->right);
        }
        return node->node_size;
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
            cout << root->value << " " << root->key << "(" << sColor << ")" << "(" << root->node_size << ")" << endl;
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
        tree_size = 0;
    }

    void preorder() {
        if (root == pit) {
            cout << "";
        }
        else {
            preorder(root);
        }
    }

    void preorder(Node* tree)const {
        if (tree != pit) {
            cout << tree->key << " ";
            preorder(tree->left);
            preorder(tree->right);
        }
    }
    
    void inorder() {
        if (root == pit) {
            cout << "";
        }
        else {
            inorder(root);
        }
    }
    
    void inorder(Node* tree)const {
        if (tree != pit) {
            inorder(tree->left);
            cout << tree->key << " ";
            inorder(tree->right);
        }
    }
    
    void postorder() {
        if (root == pit) {
            cout << "";
        }
        else {
            postorder(root);
        }
    }
    
    void postorder(Node* tree)const {
        if (tree != pit) {
            postorder(tree->left);
            postorder(tree->right);
            cout << tree->key << " ";
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
        cout << "inserting " << k << endl;
        tree_size++;
        Node* node = new Node;
        node->parent = NULL;
        node->left = pit;
        node->right = pit;
        node->key = k;
        node->value = v;
        node->color = 1;

        Node* y = NULL;
        Node* x = this->root;
        int size = 0;

        while (x != pit) {
            y = x;
            if (node->key < x->key) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == NULL) {
            root = node;
        }
        else if (node->key < y->key) {
            y->left = node;
        }
        else {
            y->right = node;
        }

        subtree_size(this->root);
        cout << "node_size = " << root->node_size << endl;

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
        tree_size--;
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

    int* search(char k) {
        Node* current = this->root;

        while (current->key != k) {

            if (current != pit) {
                //go to left tree
                if (current->key > k) {
                    current = current->left;
                }  
                //else go to right tree
                else {
                    current = current->right;
                }

                //not found
                if (current == pit) {
                    return NULL;
                }
            }
        }

        return &current->value;
    }

    int rank(char k) {
        Node* temp = root;
        int r;
        if (temp->left != pit) {
            r = temp->left->node_size + 1;
        }
        else {
            r = 1;
        }

        while (temp->key != k) {
            if (temp != pit) {
                //go to left tree
                if (temp->key > k) {
                    temp = temp->left;
                    if (temp->right != pit) {
                        r -= temp->right->node_size + 1;
                    }
                    else {
                        r -= 1;
                    }
                }
                //else go to right tree
                else {
                    temp = temp->right;
                    if (temp->left != pit) {
                        r += temp->left->node_size + 1;
                    }
                    else {
                        r += 1;
                    }
                }

                //not found
                if (temp == pit) {
                    return 0;
                }
            }
        }

        return r;
    }

    char select(int pos) {
        Node* temp = root;

        while (temp != pit) {
            int r;
            if (temp->left != pit) {
                r = temp->left->node_size + 1;
            }
            else {
                r = 1;
            }
            if (pos == r) {
                return temp->key;
            }
            else if (pos < r) {
                temp = temp->left;
            }
            else if (pos > r) {
                temp = temp->right;
                pos -= r;
            }
        }
        return 0;
    }

    int size() {
        return tree_size;
    }  

};
