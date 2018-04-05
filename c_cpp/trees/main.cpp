#include <iostream>

#include "binary_search_tree.h"

int main()
{
	BinarySearchTree tree;
	tree.insert(5);
	tree.insert(1);
	tree.insert(2);
	tree.insert(8);

	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	printf("height = %d\n", tree.getHeight());

	tree.setMethod(METHOD_ITERATION);
	tree.levelOrder();

	return 0;
}
