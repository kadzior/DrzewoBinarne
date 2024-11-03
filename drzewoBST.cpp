#include <iostream>
#include <fstream>
using namespace std;

class BST {
private:
    
public:
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
};