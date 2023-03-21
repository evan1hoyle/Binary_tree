#include "BinaryTree.h"
#include <iostream>
#include <iomanip>
using namespace std;

BinaryTree::BinaryTree() {
	root = nullptr;
}

void BinaryTree::addNode(int data) {
	Node* newNode = new Node(data);

	if (root == nullptr) {
	root = newNode;
	} else {
	Node* focusNode = root;
	Node* parent;

	while (true) {
		parent = focusNode;

		if (data < focusNode->data) {
		focusNode = focusNode->left;
		if (focusNode == nullptr) {
			parent->left = newNode;
			return;
		}
		} else {
		focusNode = focusNode->right;
		if (focusNode == nullptr) {
			parent->right = newNode;
			return;
		}
		}
	}
	}
}

void BinaryTree::preOrderTraversal(Node* focusNode) {
	if (focusNode != nullptr) {
		std::cout << focusNode->data << " "<< endl;
		preOrderTraversal(focusNode->left);
		preOrderTraversal(focusNode->right);
	}
}

void BinaryTree::InClassPrint(Node* focusNode) {
	if (focusNode != nullptr) {
		std::cout << focusNode->data << " "<< endl;
	}
	cout << focusNode ->data << "(";
	if(focusNode->left){
		cout << focusNode->left->data;
	}
	cout << ",";
	if(focusNode->right){
		cout << focusNode->right->data;
	}
	cout << ")";
	InClassPrint(focusNode->left);
	InClassPrint(focusNode->right);


}




void BinaryTree::search(Node* &cur, int item, Node* &parent)  {  
    while (cur != NULL && cur->data != item)  
    {  
        parent = cur;  
        if (item < cur->data)  
            cur = cur->left;  
        else  
            cur = cur->right;  
    }  
}  

Node* findMinimum(Node* cur)  
{  
    while(cur->left != NULL) {  
        cur = cur->left;  
    }  
    return cur;  
}  

void BinaryTree::deletion(Node*& root, int item)  {  
    Node* parent = NULL;  
    Node* cur = root;  
  
    search(cur, item, parent);  
    if (cur == NULL)  
        return;  
  
    if (cur->left == NULL && cur->right == NULL)  
    {  
        if (cur != root)  
        {  
            if (parent->left == cur)  
                parent->left = NULL;  
            else  
                parent->right = NULL;  
        }  
        else  
            root = NULL;  
  
        free(cur);       
    }  
    else if (cur->left && cur->right)  
    {  
        Node* succ  = findMinimum(cur->right);  
  
        int val = succ->data;  
  
        deletion(root, succ->data);  
  
        cur->data = val;  
    }  
  
    else  
    {  
        Node* child = (cur->left)? cur->left: cur->right;  
  
        if (cur != root)  
        {  
            if (cur == parent->left)  
                parent->left = child;  
            else  
                parent->right = child;  
        }  
  
        else  
            root = child;  
        free(cur);  
    }  
}  
  


// void BinaryTree::display(int level, Node *ptr )
// {

// 	Node* root = ptr;
// 	int i;
// 	if (ptr != NULL)
// 	{
// 		BinaryTree::display(level + 1, ptr->right);
// 		cout << endl;
// 		if (ptr == root)
// 			cout << "Root -> ";
// 		for (i = 0; i < level && ptr != root; i++)
// 			cout << "\t\n";
// 		cout << ptr->data;
// 		BinaryTree::display(level + 1, ptr->left);
// 	}
// }

// void BinaryTree::display(Node* p, int indent=0)
// {
//     if(p != NULL) {
//         if(p->left) BinaryTree::display(p->left, indent+4);
//         if(p->right) BinaryTree::display(p->right, indent+4);
//         if (indent) {
//             cout << "\t" << ' ';
//         }
//         cout<< p->data << "\n ";
//     }
// }



void BinaryTree::display(Node* p, int indent)
{

    if(p != NULL) {
        if(p->right) {
            BinaryTree::display(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right){
			std::cout<<" /\n" << std::setw(indent) << ' ';
        	
		}
		std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            BinaryTree::display(p->left, indent+4);
        }
    }
}

int BinaryTree::height(Node* current, int* right){

	if(current->left && current->right){
		return 1;
	}





}