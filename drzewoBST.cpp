#include <iostream>
#include <fstream>

#include "Node.hpp"

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
    // Konstruktor inicjalizuj¹cy puste drzewo
    BST() : root(nullptr) {}

    Node* getRoot() {
        return root;
    }

    void setRoot(Node* _root) {
        root = _root;
    }

    // Metoda publiczna dodaj¹ca element do drzewa
    void addElement(int value) {
        root = addElement(root, value);
    }
    
    // Metoda publiczna usuwaj¹ca element o zadanej wartoœci
    void deleteElement(int value) {
        root = deleteElement(root, value);
    }
    // Metoda publiczna usuwaj¹ca ca³e drzewo
    void deleteTree() {
        while (root != nullptr) {
            deleteElement(root->data); // Usuwanie elementów a¿ drzewo bêdzie puste
        }
    }
    
    // Metoda publiczna znajduj¹ca œcie¿kê do elementu o zadanej wartoœci
    void findPath(int value) {
        Node* current = root;
        while (current != nullptr) {
            cout << current->data << " ";
            if (value == current->data) {
                cout << endl;
                return;
            }
            else if (value < current->data) {
                current = current->left; // Przechodzenie do lewego poddrzewa
            }
            else {
                current = current->right; // Przechodzenie do prawego poddrzewa
            }
        }
        cout << "Value not found" << endl; // Element nie zosta³ znaleziony
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