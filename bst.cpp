#include <iostream>
#include <stack>
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
        std::stack<Node<T>*> treeNodeStack;
        treeNodeStack.push(this->root);
        while(treeNodeStack.size() > 0){
            Node<T>* curr = treeNodeStack.top();
            treeNodeStack.pop();

            if(curr->left != nullptr && compare(curr->value, newNode->value)){
                
                treeNodeStack.push(curr->left);
            }
            if(curr->right != nullptr && compare(newNode->value, curr->value)) {
                
                treeNodeStack.push(curr->right);
            }
            if(curr->left == nullptr && curr->right == nullptr && compare(curr->value, newNode->value)) {
                
                curr->left = newNode;
            }
            if(curr->left == nullptr && curr->right == nullptr && compare(newNode->value, curr->value)) {
                
                curr->right = newNode;
            }
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
    if(root -> right -> right  != nullptr) {
        std::cout << root->right->right->value << '\n';
    }

    std::stack<Node<int>*> st;
    st.push(root);
    while(!st.empty()) {
        Node<int>* curr = st.top();
        st.pop();
        std::cout << "Value: " << curr->value <<'\n';
        if(curr->left != nullptr) {
            st.push(curr->left);
        }
        if(curr->right != nullptr) {
            st.push(curr->right);
        }
    }

    
    return 0;
}