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

    // Prywatna metoda znajduj¹ca wêze³ o najmniejszej wartoœci
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left; // Przechodzenie do najbardziej lewego wêz³a
        }
        return node;
    }

    // Prywatna metoda usuwaj¹ca element z drzewa
    Node* deleteElement(Node* node, int value) {
        if (node == nullptr) {
            return node; // Jeœli wêze³ jest pusty, nic nie robimy
        }
        if (value < node->data) {
            node->left = deleteElement(node->left, value); // Szukanie elementu w lewym poddrzewie
        }
        else if (value > node->data) {
            node->right = deleteElement(node->right, value); // Szukanie elementu w prawym poddrzewie
        }
        else {
            // Wêze³ do usuniêcia zosta³ znaleziony
            if (node->left == nullptr) {
                Node* temp = node->right; // Jeœli brak lewego potomka, ustawiamy prawego jako nastêpcê
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left; // Jeœli brak prawego potomka, ustawiamy lewego jako nastêpcê
                delete node;
                return temp;
            }
            // Wêze³ ma dwóch potomków, znajdujemy najmniejszy element w prawym poddrzewie
            Node* temp = findMin(node->right);
            node->data = temp->data; // Zastêpujemy wartoœæ
            node->right = deleteElement(node->right, temp->data); // Usuwamy najmniejszy element
        }
        return node;
    }
};
