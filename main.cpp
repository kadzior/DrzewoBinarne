#include <iostream>
#include <string>

#include "./node.hpp"

#include "./drzewoBST.cpp"
#include "./DodanieKlasy.cpp"

int main() {
    BST tree;
    int option, value;
    string order, filename;

    do {
        // Menu g³ówne programu
        cout << "\nMenu:\n";
        cout << "1. Add element\n";
        cout << "2. Delete element\n";
        cout << "3. Delete entire tree\n";
        cout << "4. Find path to element\n";
        cout << "5. Display tree\n";
        cout << "6. Save tree to binary file\n";
        cout << "7. Load tree from binary file\n";
        cout << "8. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            tree.addElement(value); // Dodawanie elementu do drzewa
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.deleteElement(value); // Usuwanie elementu z drzewa
            break;
        case 3:
            tree.deleteTree(); // Usuwanie ca³ego drzewa
            break;
        case 4:
            cout << "Enter value to find path: ";
            cin >> value;
            tree.findPath(value); // Znajdowanie œcie¿ki do elementu
            break;
        case 5:
            cout << "Enter display order (inorder, preorder, postorder): ";
            cin >> order;
            tree.displayTree(order); // Wyœwietlanie drzewa w wybranym porz¹dku
            break;
        case 6:
            cout << "Enter filename to save tree: ";
            cin >> filename;
            BSTFileHandler::saveToBinaryFile(tree.getRoot(), filename); // Zapisywanie drzewa do pliku binarnego
            break;
        case 7:
            cout << "Enter filename to load tree: ";
            cin >> filename;
            tree.setRoot(BSTFileHandler::loadFromBinaryFile(filename)); // Wczytywanie drzewa z pliku binarnego
            break;
        case 8:
            cout << "Exiting program." << endl; // Wyjœcie z programu
            break;
        default:
            cout << "Invalid option. Try again." << endl; // Obs³uga niepoprawnego wyboru
        }
    } while (option != 8);

    return 0;
}