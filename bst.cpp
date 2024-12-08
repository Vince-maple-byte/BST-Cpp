#include <iostream>
#include "bst.hpp"

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    this->root = nullptr;
    this->size = 0;
    this->compare = defaultCompare;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(CompareFunc c) {
    this->root = nullptr;
    this->size = 1;
    this->compare = c;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* node) {
    this->root = node;
    this->size = 1;
    this->compare = defaultCompare;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(Node<T>* node, CompareFunc c) {
    this->root = node;
    this->size = 1;
    this->compare = c;
};

template <typename T>
int BinarySearchTree<T>::getSize() {
    return this->size;
};

template <typename T>
bool BinarySearchTree<T>::isEmpty() {
    return this->size == 0;
};

template <typename T>
Node<T>* BinarySearchTree<T>::getRoot() {
    return this->root;
};

//You don't need a stack to go through a binary search tree (This is not dfs/bfs)
template <typename T>
void BinarySearchTree<T>::insert(const T value){
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if(this->root == nullptr) {
        this->root = newNode;
    }
    else {
        Node<T>* curr = root;
        Node<T>* parent = nullptr;
        while(curr != nullptr){
            //Keeps track of which parent node is the new node going to be added to 
            parent = curr;

            if(curr->value == newNode->value){
                return;
            }

            //compare(curr->value, newNode->value) root.value <= value 
            if(compare(curr->value, newNode->value)){
                curr = curr->right;
            }
            //compare(curr->value, newNode->value) value <= root.value
            else if(compare(newNode->value, curr->value)) {
                curr = curr->left;
            }
        }
        if(compare(newNode->value, parent->value)) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }
    this->size++;
    


}

template <typename T>
void BinarySearchTree<T>::remove(const T value){
    
}

template <typename T>
void BinarySearchTree<T>::inOrderTraversal(){
    
}

template <typename T>
void BinarySearchTree<T>::preOrderTraversal(){
    
}

template <typename T>
void BinarySearchTree<T>::postOrderTraversal(){
    
}

//You don't need a stack to go through a binary search tree (This is not dfs/bfs)
 
int main() {
    std::cout << "Welcome To The Binary Search Tree Library\n" ;

    int i = 2;
    BinarySearchTree<int> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    Node<int>* root = bst.getRoot();
    std::cout << bst.getSize() << '\n';
    if(root -> right != nullptr) {
        std::cout << root->right->value << '\n';
    }

    std::cout << "End of program\n";

    

    
    return 0;
}