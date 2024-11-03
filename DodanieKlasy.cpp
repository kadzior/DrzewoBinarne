#include <iostream>
#include <fstream>

#include "./node.hpp"

using namespace std;

// Klasa reprezentuj¹ca operacje zwi¹zane z plikami dla drzewa BST
class BSTFileHandler {
public:
    // Metoda zapisuj¹ca drzewo do pliku binarnego
    static void saveToBinaryFile(Node* node, const string& filename) {
        ofstream file(filename, ios::binary);
        if (file.is_open()) {
            saveToFile(node, file); // Rekurencyjny zapis drzewa do pliku binarnego
            file.close();
        }
        else {
            cout << "Unable to open file" << endl; // Obs³uga b³êdu przy otwieraniu pliku
        }
    }

    // Prywatna metoda zapisuj¹ca drzewo do pliku w porz¹dku preorder
private:
    static void saveToFile(Node* node, ofstream& file) {
        if (node != nullptr) {
            file.write(reinterpret_cast<char*>(&node->data), sizeof(node->data));
            saveToFile(node->left, file);
            saveToFile(node->right, file);
        }
    }

public:
    // Metoda wczytuj¹ca drzewo z pliku binarnego
    static Node* loadFromBinaryFile(const string& filename) {
        ifstream file(filename, ios::binary);
        if (file.is_open()) {
            Node* root = loadFromFile(file); // Rekurencyjne wczytanie drzewa z pliku binarnego
            file.close();
            return root;
        }
        else {
            cout << "Unable to open file" << endl; // Obs³uga b³êdu przy otwieraniu pliku
            return nullptr;
        }
    }

    // Prywatna metoda wczytuj¹ca drzewo z pliku binarnego
private:
    static Node* loadFromFile(ifstream& file) {
        int value;
        if (file.read(reinterpret_cast<char*>(&value), sizeof(value))) {
            Node* newNode = new Node(value);
            newNode->left = loadFromFile(file);
            newNode->right = loadFromFile(file);
            return newNode;
        }
        return nullptr;
    }
};