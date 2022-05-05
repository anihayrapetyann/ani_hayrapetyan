#include <iostream>
#include <queue>

using namespace std;

class BinaryTreeNode {
public:
    BinaryTreeNode *Left;
    BinaryTreeNode *Right;
    int Value;
    BinaryTreeNode(int value) {
        Value = value;
    }
};

class BinaryTree {
private:
    int _count;
public:
    BinaryTreeNode *_head;
    int CompareTo(int value1, int value2) {
        if (value1 > value2) {
            return 1;
        }
        else if (value1 < value2) {
            return -1;
        }
        else {
            return 0;
        }
    }

    void Add(int value) {
        if (_head == NULL){
            _head = new BinaryTreeNode(value);
        }
        else {
            AddTo(_head, value);
        }
        _count++;
    }

private:
    void AddTo(BinaryTreeNode *node, int value) {
        if (CompareTo(node->Value, value) > 0) {
            if (node->Left == NULL) {
                node->Left = new BinaryTreeNode(value);
            }
            else {
                AddTo(node->Left, value);
            }
        }
        else {
            if (node->Right == NULL) {
                node->Right = new BinaryTreeNode(value);
            }
            else {
                AddTo(node->Right, value);
            }
        }
    }
public:
    void printBinaryTree(BinaryTreeNode *root, int space = 0, int distance = 10) {
        if (root == NULL) {
            return;
        }
        space += distance;
        printBinaryTree(root->Right, space);
        cout << endl;
        for (int i = distance; i < space / 2; i++) {
            cout << '-';
        }
        for (int i = space / 2; i < space; i++) {
            cout << '-';
        }
        cout << "(" << root->Value << ") ";
        cout << endl;
        printBinaryTree(root->Left, space);
    }
};

void Input(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }
}

bool isBinaryTree(int **arr, int size) {
    Input(arr, size);
    bool row = true;
    int temp2 = 0;
    for (int i = 0; i < size; i++) {
        int _temp = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 1) {
                ++_temp;
                if (_temp > 2) {
                    row = false;
                }
            }
            if (arr[i][j] == arr[j][i] && arr[j][i] == 1) {
                row = false;
            }
        }
        int count = 0;
        for (int k = 0; k < size; k++) {
            if (arr[k][i] == 0) {
                ++count;
            }
            if (count == size) {
                ++temp2;
            }
        }
    }
    if (temp2 != 1) {
        row = false;
    }
    if (row == false) 
        cout << "It isn't a binary tree! " << endl;
    else 
        cout << "It is a binary tree!" << endl;
    return row;
}

int getRoot(int **arr, int size) {
    int index = -1;
    bool isbin = isBinaryTree(arr, size);
    if (isbin) {
        for (int i = 0; i < size; i++) {
            int count = 0;
            for (int j = 0; j < size; j++) {
                if (arr[j][i] == 0) {
                    ++count;
                }
            }
            if (count == size) {
                index = i;
            }
        }
    }
    return index;
}

int main()
{
    int size = 5;
    int **arr = new int *[size];
    BinaryTree *tree = new BinaryTree();

    int index = getRoot(arr, size);
    int indexes[size];
    indexes[0] = index;
    int m = 1;

    for (int i = 0; i < size; i++) {
        int k = indexes[i];
        for (int j = 0; j < size; j++) {
            if (arr[k][j] == 1) {
                indexes[m] = j;
                m++;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        tree->Add(indexes[i]);
    }

/*  { 0 0 0 0 0 
      1 0 0 0 0
      0 1 0 1 0
      0 0 0 0 1
      0 0 0 0 0      
     }
           (2)
          // \\
         //   \\
       (1)     (3)
       //        \\
      //          \\
    (0)            (4)   
*/
    tree->printBinaryTree(tree->_head);
    return 0;
}