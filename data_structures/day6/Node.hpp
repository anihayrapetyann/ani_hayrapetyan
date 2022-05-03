#ifndef __NODE_H__
#define __NODE_H__

class Node {
public:
    int _data;
    Node *_left;
    Node *_right;
    Node(int data);
    Node();
};

Node::Node(int data) {
    _data = data;
    _left = nullptr;
    _right = nullptr;
}

Node::Node() {
    _data = 0;
    _left = nullptr;
    _right = nullptr;
}

#endif // __NODE_H__