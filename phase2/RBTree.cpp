#include <iostream>
#include <stack>
using namespace std;

template <typename T, typename T2>
struct Node {
    T key;
    T2 value;
    int color; //0 = black, 1 = red
    int node_size;
    Node* parent;
    Node* left;
    Node* right;
};


template <typename T, typename T2>
class RBTree {
private:
    Node<T, T2>* root;
    Node<T, T2>* pit;
    int tree_size;

    void leftRotate(Node<T, T2>* x)
    {
        Node<T, T2>* y = x->right;
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
        subtree_size(y);
    }

    void rightRotate(Node<T, T2>* x) {
        Node<T, T2>* y = x->left;
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
        subtree_size(y);
    }
    void insertFix(Node<T, T2>* k) {
        Node<T, T2>* u;
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
                subtree_size(root);
                break;
            }
        }
        root->color = 0;
    }

    void rbTransplant(Node<T, T2>* u, Node<T, T2>* v)
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

    void deleteFix(Node<T, T2>* x)
    {
        Node<T, T2>* s;
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

    int subtree_size(Node<T, T2>* node) {
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

    void printHelper(Node<T, T2>* root, string indent, bool last)
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

    //Node<T,T2>* copyHelper(Node<T, T2>* new_root, Node<T, T2>* old_root, bool direction) {
    //    //copy all the way down past pit, stopping at NULL
    //    if (old_root != NULL) {
    //        //TODO: create some kind of new node here
    //        //if left
    //        if (direction) {
    //            Node<T, T2>* node = new Node <T, T2>;
    //            node->color = old_root->color;
    //            node->key = old_root->key;
    //            node->value = old_root->value;
    //            node->node_size = old_root->node_size;
    //            new_root = node;
    //            new_root->
    //        }
    //        /*if (old_root->right != NULL) {
    //            Node<T, T2>* node = new Node <T, T2>;
    //            node->color = old_root->right->color;
    //            node->key = old_root->right->key;
    //            node->value = old_root->right->value;
    //            node->node_size = old_root->right->node_size;
    //            new_root->right = node;
    //        }*/
    //        copyHelper(new_root->left, old_root->left);
    //        copyHelper(new_root->right, old_root->right);
    //    }
    //    else {
    //        return new_root;
    //    }
    //    return new_root;
    //}
    
public:
    RBTree() {
        pit = new Node <T, T2>;
        pit->color = 0;
        pit->left = NULL;
        pit->right = NULL;
        root = pit;
        tree_size = 0;
    }

    RBTree<T,T2> (T k[], T2 v[], int s) {
        pit = new Node <T, T2>;
        pit->color = 0;
        pit->left = NULL;
        pit->right = NULL;
        root = pit;
        tree_size = 0;

        for (int i = 0; s != 0; s--, i++) {
            insert(k[i], v[i]);
        }
    }

    //copy constructor
    //RBTree(RBTree<T, T2>& t) {
    //    pit = new Node <T, T2>;
    //    pit->color = 0;
    //    pit->left = NULL;
    //    pit->right = NULL;
    //    tree_size = 0;

    //    root = new Node <T, T2>;
    //    //now assign root to recursion
    //    root = copyHelper(root, t.root);
    //}

    ////copy assignment operator
    //RBTree& operator = (const RBTree& t) {
    //    return *this;
    //}



    ~RBTree() {
        delete(root);
        //need to delete all nodes connected to root as well
    }

    void preorder() {
        if (root == pit) {
            cout << endl;
        }
        else {
            preorder(root);
            cout << endl;
        }
    }

    void preorder(Node<T, T2>* tree)const {
        if (tree != pit) {
            cout << tree->key << " ";
            preorder(tree->left);
            preorder(tree->right);
        }
    }
    
    void inorder() {
        if (root == pit) {
            cout << endl;
        }
        else {
            inorder(root);
            cout << endl;
        }
    }
    
    void inorder(Node<T, T2>* tree)const {
        if (tree != pit) {
            inorder(tree->left);
            cout << tree->key << " ";
            inorder(tree->right);
        }
    }
    
    void postorder() {
        if (root == pit) {
            cout << endl;
        }
        else {
            postorder(root);
            cout << endl;
        }
    }
    
    void postorder(Node<T, T2>* tree)const {
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

    Node<T, T2>* minimum(Node<T, T2>* node)
    {
        while (node->left != pit)
        {
            node = node->left;
        }
        return node;
    }

    void insert(T k, T2 v) {
        //cout << "inserting " << k << endl;
        tree_size++;
        Node<T, T2>* node = new Node <T, T2>;
        node->parent = NULL;
        node->left = pit;
        node->right = pit;
        node->key = k;
        node->value = v;
        node->color = 1;

        Node<T, T2>* y = NULL;
        Node<T, T2>* x = this->root;
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

        //cout << "node_size = " << root->node_size << endl;

        //recoloring stage
        if (node->parent == NULL) {
            node->color = 0; //set to black
            subtree_size(node);
            return;
        }
        if (node->parent->parent == NULL) {
            subtree_size(node);
            return;
        }

        insertFix(node);
    }

    int remove(T k) {
        tree_size--;
        Node<T, T2>* z = pit;
        Node<T, T2>* node = this->root;
        Node<T, T2>* x;
        Node<T, T2>* y;
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
            //cout << "Key not found in the tree" << endl;
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
        subtree_size(this->root);
        return 1;
    }

    T2* search(T k) {
        Node<T, T2>* current = this->root;

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

    int rank(T k) {
        Node<T, T2>* temp = root;
        int r;
        //subtree_size(temp);
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

    T select(int pos) {
        Node<T, T2>* temp = root;

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

    T* predecessor(T k) {
        Node<T, T2>* current = root;
        bool go_right = false;
        bool go_left = false;

        while (current->key != k) {

            if (current != pit) {
                //go to left tree
                if (current->key > k) {
                    current = current->left;
                    go_left = true;
                }
                //else go to right tree
                else {
                    current = current->right;
                    go_right = true;
                }

                //not found
                if (current == pit) {
                    return NULL;
                }
            }
        }
        //now we're at the key we want, now go left once, then right right right
        if (current->left != pit) {
            current = current->left;
        }
        //if leaf
        else if (current->left == pit && current->right == pit) {
            //if right child
            if (current->parent->key < current->key) {
                return &current->parent->key;
            }
            //if left child
            else if (current->parent->key > current->key) {
                if (go_right == false) {
                    T x = NULL;
                    return &x;
                }
                else {
                    return &current->parent->parent->key;
                }
            }
        }
        else if (current->left == pit && current->right != pit) {
            return &current->parent->key;
        }
        while (current->right != pit) {
            current = current->right;
            go_right = true;
        }
        return &current->key;
    }

    T* successor(T k) {
        Node<T, T2>* current = root;
        bool go_right = false;
        bool go_left = false;

        while (current->key != k) {

            if (current != pit) {
                //go to left tree
                if (current->key > k) {
                    current = current->left;
                    go_left = true;
                }
                //else go to right tree
                else {
                    current = current->right;
                    go_right = true;
                }

                //not found
                if (current == pit) {
                    return NULL;
                }
            }
        }
        //now we're at the key we want, now go right once, then left left left
        if (current->right != pit) {
            current = current->right;
        }
        //if leaf
        else if (current->left == pit && current->right == pit) {
            //if right child
            if (current->parent->key < current->key) {
                if (go_left == false) {
                    T x = NULL;
                    return &x;
                }
                else {
                    return &current->parent->parent->key;
                }
            }
            //if left child
            else if (current->parent->key > current->key) {
                    return &current->parent->key;
            }
        }
        else if (current->right == pit && current->left != pit) {
            return &current->parent->key;
        }
        while (current->left != pit) {
            current = current->left;
        }
        return &current->key;
    }

    int size() {
        return tree_size;
    }  

};
