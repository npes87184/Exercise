#include <cstdio>
#include <stack>
#include <queue>

#include "tree.h"

Node::Node(int value)
{
	val = value;
	lChild = NULL;
	rChild = NULL;
}

Tree::Tree()
{}

Tree::~Tree()
{
	free();
}

static unsigned int _getHeightRecursive(Node* node)
{
	return (NULL == node) ? 0 :
		std::max(_getHeightRecursive(node->lChild), _getHeightRecursive(node->rChild)) + 1;
}

unsigned int Tree::getHeight()
{
	if (METHOD_RECURSIVE == _method) {
		return _getHeightRecursive(_head);
	}
	return 0;
}

static void _freeRecursive(Node* node)
{
	if (NULL == node) {
		return;
	}

	_freeRecursive(node->lChild);
	_freeRecursive(node->rChild);

	delete(node);
	return;
}

void Tree::free()
{
	if (METHOD_RECURSIVE == _method) {
		_freeRecursive(_head);
	}
}

static void _preRecursive(Node* node)
{
	if (NULL == node) {
		return;
	}

	printf("%d ", node->val);
	_preRecursive(node->lChild);
	_preRecursive(node->rChild);

	return;
}

void Tree::preOrder()
{
	if (METHOD_RECURSIVE == _method) {
		_preRecursive(_head);
		printf("\n");
	}
}

static void _inRecursive(Node* node)
{
	if (NULL == node) {
		return;
	}

	_inRecursive(node->lChild);
	printf("%d ", node->val);
	_inRecursive(node->rChild);

	return;
}

void Tree::inOrder()
{
	if (METHOD_RECURSIVE == _method) {
		_inRecursive(_head);
		printf("\n");
	}
}

static void _postRecursive(Node* node)
{
	if (NULL == node) {
		return;
	}

	_postRecursive(node->lChild);
	_postRecursive(node->rChild);
	printf("%d ", node->val);

	return;
}

void Tree::postOrder()
{
	if (METHOD_RECURSIVE == _method) {
		_postRecursive(_head);
		printf("\n");
	}
}

static void _levelIteration(Node* node)
{
	std::queue<Node*> q;

	q.push(node);

	while (!q.empty()) {
		Node* tmp = q.front();
		q.pop();

		if (NULL == tmp) {
			continue;
		}

		q.push(tmp->lChild);
		q.push(tmp->rChild);

		printf("%d ", tmp->val);
	}

	return;
}

void Tree::levelOrder()
{
	if (METHOD_RECURSIVE == _method) {
	} else if (METHOD_ITERATION == _method) {
		_levelIteration(_head);
		printf("\n");
	}
}
