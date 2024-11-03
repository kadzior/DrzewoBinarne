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
    void saveToFile(Node* node, ofstream& file) {
        if (node != nullptr) {
            file << node->data << " ";
            saveToFile(node->left, file);
            saveToFile(node->right, file);
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
        else if (order == "preorder") {
            preOrder(root);
        }
        else if (order == "postorder") {
            postOrder(root);
        }
        else {
            cout << "Invalid order" << endl;
        }
        cout << endl;
    }
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            saveToFile(root, file);
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
};
