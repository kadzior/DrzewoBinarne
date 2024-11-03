#include <iostream>
#include <fstream>
using namespace std;


class BST {
private:
    Node* root; // Wska�nik do korzenia drzewa

    // Prywatna metoda dodaj�ca element do drzewa
    Node* addElement(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value); // Tworzenie nowego w�z�a, je�li aktualny jest pusty
        }
        if (value < node->data) {
            node->left = addElement(node->left, value); // Rekurencyjne dodawanie do lewego poddrzewa
        }
        else {
            node->right = addElement(node->right, value); // Rekurencyjne dodawanie do prawego poddrzewa
        }
        return node;
    }

    // Prywatna metoda znajduj�ca w�ze� o najmniejszej warto�ci
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left; // Przechodzenie do najbardziej lewego w�z�a
        }
        return node;
    }
};
