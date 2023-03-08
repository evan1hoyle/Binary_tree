#include <iostream>

struct Node {
int data;
Node* left;
Node* right;

Node(int data) {
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}
};

class BinaryTree {
public:
Node* root;

BinaryTree();
void addNode(int );
void preOrderTraversal(Node*);
void deletion(Node*& , int );
void search(Node*& , int, Node*& );  
void display( Node* ,int);

};


