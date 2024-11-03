#include <iostream>
#include <fstream>
using namespace std;

class BST {
private:
    Node* root;

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void addElement(int value) {
        root = addElement(root, value);
    }

    void displayTree(const string& order) {
        if (order == "inorder") {
            inOrder(root);
        } 
        cout << endl;
    }

};
