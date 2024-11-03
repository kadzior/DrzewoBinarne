#include <iostream>
#include <fstream>
using namespace std;


class BST {
private:
    Node* root; // WskaŸnik do korzenia drzewa

    // Prywatna metoda dodaj¹ca element do drzewa
    Node* addElement(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value); // Tworzenie nowego wêz³a, jeœli aktualny jest pusty
        }
        if (value < node->data) {
            node->left = addElement(node->left, value); // Rekurencyjne dodawanie do lewego poddrzewa
        }
        else {
            node->right = addElement(node->right, value); // Rekurencyjne dodawanie do prawego poddrzewa
        }
        return node;
    }


};
