
#include "BinaryTree.h"

int main() {
BinaryTree tree;

tree.addNode(50);
tree.addNode(25);
tree.addNode(75);
tree.addNode(12);
tree.addNode(37);
tree.addNode(43);
tree.addNode(30);

tree.preOrderTraversal(tree.root);
tree.display(tree.root,6);

return 0;
}