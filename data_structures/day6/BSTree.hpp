#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.hpp"
#include <queue>
#include <iostream>

using std::ostream;

class Tree {
public:
    Node *_root;
    Tree(int value);
    Tree();
    Node *insert (int data);
    void PrintByAscendingOrder();
private:
    void PrintByAscendingOrder(Node* root);
    Node *insert (Node *& root, int data);
};

Tree::Tree(int value) {
    _root = new Node(value);
}

Tree::Tree() {
    _root = NULL;
}
    
void Tree::PrintByAscendingOrder() {
    PrintByAscendingOrder(_root);
}

void Tree::PrintByAscendingOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    PrintByAscendingOrder(root->_left);
    std::cout << root->_data << " ";
    PrintByAscendingOrder(root->_right);
}

Node* Tree::insert (int data) {
    return insert (_root,  data);
}

Node* Tree::insert (Node *& root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    else {
        if (data <= root->_data) {
            root->_left = insert(root->_left, data);
        }
        else {
            root->_right = insert(root->_right, data);
        }
        return root;
    }
}
   
#endif // __BSTREE_H__