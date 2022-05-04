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
    Node* getRightMin(Node* root);
    Node* FindValue(Node *root, int value);
    Node* removeNode (Node* root, int val);
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
   
Node* Tree::getRightMin(Node *root) {
    Node *temp = root;
    while(temp->_left != NULL){ temp = temp->_left;}
    return temp;
}

Node* Tree::FindValue(Node *root, int value) {
    if (root == NULL) 
        return root;
	while(root != NULL) {
		if(root->_data == value) {
			return root;
		}
		else if(root->_data > value)
			root = root->_left;
		else
			root = root->_right;
	}
	return root;
}

Node* Tree::removeNode (Node* root, int val) {
    if(root == NULL)
        return NULL;
    if(root->_data < val)
        root->_right = removeNode(root->_right,val);
    else if(root->_data > val)
        root->_left = removeNode(root->_left,val);
    else {
        if(root->_left == NULL && root->_right == NULL) {
            root = NULL;
        }
        else if(root->_left == NULL) {
                root = root->_right;
        }
        else if(root->_right == NULL) {
                root = root->_left;
        }
        else { 
            Node* temp = getRightMin(root->_right);
            temp = root->_right;  
            root->_data = temp->_data;
            root->_right= removeNode(root->_right, temp->_data);
        }
    }
    return root;
}

#endif // __BSTREE_H__