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

    // Prywatna metoda usuwaj�ca element z drzewa
    Node* deleteElement(Node* node, int value) {
        if (node == nullptr) {
            return node; // Je�li w�ze� jest pusty, nic nie robimy
        }
        if (value < node->data) {
            node->left = deleteElement(node->left, value); // Szukanie elementu w lewym poddrzewie
        }
        else if (value > node->data) {
            node->right = deleteElement(node->right, value); // Szukanie elementu w prawym poddrzewie
        }
        else {
            // W�ze� do usuni�cia zosta� znaleziony
            if (node->left == nullptr) {
                Node* temp = node->right; // Je�li brak lewego potomka, ustawiamy prawego jako nast�pc�
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left; // Je�li brak prawego potomka, ustawiamy lewego jako nast�pc�
                delete node;
                return temp;
            }
            // W�ze� ma dw�ch potomk�w, znajdujemy najmniejszy element w prawym poddrzewie
            Node* temp = findMin(node->right);
            node->data = temp->data; // Zast�pujemy warto��
            node->right = deleteElement(node->right, temp->data); // Usuwamy najmniejszy element
        }
        return node;
    }
};
