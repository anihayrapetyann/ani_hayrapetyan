#include <iostream>
#include <stack>
using namespace std;

class Tree {
public:
    int _data;
    struct Tree *left;
    struct Tree *right;
    Tree (int data) {
        _data = data;
        left = nullptr;
        right = nullptr;
    }
};

void print(Tree *root) {
    if (root == NULL)
        return;
    stack <Tree *> s;
    s.push(root);
    while (!s.empty()) {
        Tree *tree = s.top();
        cout << tree->_data << " ";
        s.pop();
        if (tree->left != NULL)
            s.push(tree->left);
        if (tree->right != NULL)
            s.push(tree->right);
    }
}

void insert (Tree *root, int value) {
    Tree *newtree = new Tree(value);
    stack <Tree *> s;
    s.push(root);
    while (!s.empty()) {
        Tree *temp = s.top();
        s.pop();
        if (temp->left == NULL){
            temp->left = newtree;
            return;
        }
        if (temp->right == NULL) {
            temp->right = newtree;
            return;
        }
        else {
            s.push(temp->left);
            s.push(temp->right);
        }
    }
}

int maxValue(Tree *root) {
    int _max = root->_data;
    if (root == NULL)
        return 0;
    stack <Tree *> s;
    s.push(root);
    while (!s.empty()) {
        Tree *tree = s.top();
        if (_max <= tree->_data) {
            _max = tree->_data;
        }
        s.pop();
        if (tree->left != NULL)
            s.push(tree->left);

        if (tree->right != NULL)
            s.push(tree->right);
    }
    return _max;
}

int minValue(Tree *root) {
    int min = root->_data;
    if (root == NULL) {
        return 0;
    }
    stack<Tree *> s;
    s.push(root);
    while (!s.empty()) {
        Tree *tree = s.top();
        if (min >= tree->_data) {
            min = tree->_data;
        }
        s.pop();
        if (tree->left != NULL)
            s.push(tree->left);
        if (tree->right != NULL)
            s.push(tree->right);
    }
    return min;
}
int sumOfValues(Tree *root) {
    int _sum = 0;
    if (root == NULL) 
        return 0;
    stack<Tree *> s;
    s.push(root);
    while (!s.empty()) {
        Tree *tree = s.top();
        _sum += tree->_data;
        s.pop();
        if (tree->left != NULL)
            s.push(tree->left);
        if (tree->right != NULL)
            s.push(tree->right);
    }
    return _sum;
}

int main() {
    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    insert(root, 20);
    insert(root, 15);
    insert(root, 21);
    insert(root, 22);

    print(root);
    cout << "\n\nThe min value is: " << minValue(root) << endl;
    cout << "The max value is: " << maxValue(root) << endl;
    cout << "The sum of values is: " << sumOfValues(root) << endl;
    
    return 0;
}