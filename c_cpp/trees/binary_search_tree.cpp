#include <stddef.h>

#include "binary_search_tree.h"

int BinarySearchTree::insert(int value)
{
	Node* node = new Node(value);
	Node* tmp = _head;

	if (NULL == _head) {
		_head = node;
		return 0;
	}

	while (true) {
		if (value > tmp->val) {
			if (NULL == tmp->rChild) {
				tmp->rChild = node;
				break;
			} else {
				tmp = tmp->rChild;
				continue;
			}
		} else {
			if (NULL == tmp->lChild) {
				tmp->lChild = node;
				break;
			} else {
				tmp = tmp->lChild;
				continue;
			}
		}
	}

	return 0;
}
