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

    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
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
        } else if (order == "preorder") {
            preOrder(root);
        } else if (order == "postorder") {
            postOrder(root);
        } else {
            cout << "Invalid order" << endl;
        }
        cout << endl;
    }

};
