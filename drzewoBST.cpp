#include <iostream>
#include <fstream>
using namespace std;

class BST {
private:
    
public:
    // Metoda publiczna usuwaj�ca ca�e drzewo
    void deleteTree() {
        while (root != nullptr) {
            deleteElement(root->data); // Usuwanie element�w a� drzewo b�dzie puste
        }
    }
    
    // Metoda publiczna znajduj�ca �cie�k� do elementu o zadanej warto�ci
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
        cout << "Value not found" << endl; // Element nie zosta� znaleziony
    }
};