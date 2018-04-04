#ifndef _NPES87184_TREE_H_
#define _NPES87184_TREE_H_

#include <stddef.h>

class Node
{
	public:
		Node(int value);
		int val;
		Node* lChild;
		Node* rChild;
};

enum METHOD {
	METHOD_RECURSIVE = 0,
	METHOD_ITERATION = 1
};

class Tree
{
	public:
		Tree();
		~Tree();
		unsigned int getHeight(METHOD method = METHOD_RECURSIVE);
		void free(METHOD method = METHOD_RECURSIVE);
		void preOrder(METHOD method = METHOD_RECURSIVE);
		void inOrder(METHOD method = METHOD_RECURSIVE);
		virtual int insert(int val) = 0;
	protected:
		Node* _head = NULL;
};

#endif
