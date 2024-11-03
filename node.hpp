#pragma once

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
    ~Node() {
        delete left;
        delete right;
    }
};