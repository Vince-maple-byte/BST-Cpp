#pragma once
#include "node.h"

template <typename T>
bool defaultCompare(const T a, const T b) {
    return a <= b;
}

template <typename T>
class BinarySearchTree {
    typedef bool(*CompareFunc)(const T, const T);

    private:
        Node<T>* root;
        int size;
        completeTree();
        CompareFunc compare;
        
    public:
        BinarySearchTree(); //Default comparable 
        BinarySearchTree(CompareFunc c); //Personal comparable 
        BinarySearchTree(Node<T>* root);
        BinarySearchTree(Node<T>* root , CompareFunc c);
        void insert(const T value);
        void remove(const T value);
        int getSize(); //
        Node<T>* getRoot(); //
        void inOrderTraversal(); 
        void preOrderTraversal(); 
        void postOrderTraversal(); 
        bool isEmpty(); //
};

