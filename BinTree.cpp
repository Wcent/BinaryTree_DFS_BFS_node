#include "BinTree.h"
#include <iostream>

using namespace std;

int CBinTree::numOfNodes = 0;

CBinTree::CBinTree()
{
	bTree = NULL;
}

CBinTree::CBinTree(CNode *nodeArray, int len)
{
	int root;
	int left, right;
	CNode *node;
	
	for (int i=len-1; i>0; i--)
	{
		node = new CNode(nodeArray[i]);
		root = (i - 1) / 2;
		left = 2 * root + 1;
		right = 2 * root + 2;
		if (i == left)
			nodeArray[root].setLeftSubNode(node);
		else if (i == right)
			nodeArray[root].setRightSubNode(node);
		else
			delete [] node;
	}
	bTree = new CNode(nodeArray[0]);
	numOfNodes = len;
}

void CBinTree::output()
{
	int head, tail;
	CNode **queue;
	CNode *node;
	
	if (bTree == NULL)
		return ;
		
	queue = new CNode *[numOfNodes];
	head = tail = 0;
	queue[tail++] = bTree;
	while (head < tail)
	{
		node = queue[head++];
		cout<<node->getNodeValue()<<' ';
		if (node->getLeftSubNode() != NULL)
			queue[tail++] = node->getLeftSubNode();
		if (node->getRightSubNode() != NULL)
			queue[tail++] = node->getRightSubNode();
	}
	cout<<endl;
	delete [] queue;
}

CNode * CBinTree::getRootNode()
{
	return bTree;
}

void CBinTree::setRootNode(CNode *newRoot)
{
	bTree = newRoot;
}

int CBinTree::getNumOfNodes()
{
	return numOfNodes;
}

/*
CNode * CBinTree::getNodeParent(CBinTree &binTree, const CNode &keyNode) const
{
	CNode *root = binTree.getRootNode();
	if (root == NULL)
		return NULL;
		
	if (root == &keyNode)
		return NULL;
		
	CNode *left = root->getLeftSubNode();
	CNode *right = root->getRightSubNode();
	if (left == &keyNode || right == &keyNode)
		return root;
	
	if (left != NULL)
	{
		setRootNode(left);
		CNode *parent = getNodeParent(binTree, keyNode);
		setRootNode(root);
		if (parent != NULL)
			return parent;
	}
	if (right != NULL)
	{
		setRootNode(right);
		CNode *parent = getNodeParent(binTree, keyNode);
		setRootNode(root);
		return parent;
	}
	return NULL;
}
*/

CNode * CBinTree::getNodeParent(CNode *root, CNode &keyNode)
{
	CNode *left = root->getLeftSubNode();
	CNode *right = root->getRightSubNode();
	
	if (root->getNodeValue() == keyNode.getNodeValue())
		return NULL;
	else if (left->getNodeValue() == keyNode.getNodeValue() || 
		right->getNodeValue() == keyNode.getNodeValue())
		return root;
	if (left != NULL)
	{
		root = getNodeParent(left, keyNode);
		if (root != NULL)
			return root;
	}
	if (right != NULL)
	{
		root = getNodeParent(right, keyNode);
		if (root != NULL)
			return root;
	}
	return NULL;	
}

bool CBinTree::insertNode(CNode &keyNode, bool flag, CNode *newNode)
{
	CNode *node = BFS_node(keyNode);
	if (node == NULL)
		return false;
	
	CNode *nNode = new CNode(*newNode);
	if (flag == true)
	{
		CNode *left = node->getLeftSubNode();
		node->setLeftSubNode(nNode);
		nNode->setLeftSubNode(left);
	}
	else
	{
		CNode *right = node->getRightSubNode();
		node->setRightSubNode(nNode);
		nNode->setRightSubNode(right);
	}
	numOfNodes++;
	return true;
}

bool CBinTree::deleteNode(CNode &keyNode)
{
	CNode *node = BFS_node(keyNode);
	if (node != NULL)
	{
		CNode *parent = getNodeParent(bTree, keyNode);
		if (parent != NULL)
		{
			CNode *left = parent->getLeftSubNode();
			CNode *right = parent->getRightSubNode();
			
			if (left == node && node->getLeftSubNode() == NULL)
				parent->setLeftSubNode(node->getRightSubNode());
			else if (left == node && node->getRightSubNode() == NULL)
				parent->setLeftSubNode(node->getLeftSubNode());
			else if (right == node && node->getLeftSubNode() == NULL)
				parent->setRightSubNode(node->getRightSubNode());
			else if (right == node && node->getRightSubNode() == NULL)
				parent->setRightSubNode(node->getLeftSubNode());
			else
			{
				if (left == node)
					parent->setLeftSubNode(node->getLeftSubNode());
				else if (right == node)
					parent->setRightSubNode(node->getLeftSubNode());
			
				parent = node->getLeftSubNode();
				right = parent->getRightSubNode();
				while (right != NULL)
				{
					parent = right;
					right = parent->getRightSubNode();
				}
				parent->setRightSubNode(node->getRightSubNode());
			}
			delete [] node;
		}
		else
		{
			delete [] node;
			bTree = NULL;
		}
		numOfNodes--;
		return true;
	}
	else
		return false;
}

bool CBinTree::nodeIsExist(CNode &keyNode)
{
	return (DFS_node(keyNode) != NULL);
//	return (BFS_node(keyNode) != NULL;
}

// DFS - binary tree
CNode * CBinTree::DFS_node(CNode &keyNode)
{
	int top, bottom;
	CNode **stack;
	CNode *node;
	CNode *preNode;
	CNode *left, *right;

	if (bTree == NULL)
		return NULL;
		
	stack = new CNode *[numOfNodes];
	top = bottom = 0;
	if (bTree->getNodeValue() == keyNode.getNodeValue())
	{
		delete [] stack;
		return bTree;
	}
	stack[top++] = bTree;
	preNode = NULL;
	
	while (top > bottom)
	{
		node = stack[top-1];
		left = node->getLeftSubNode();
		right = node->getRightSubNode();
		
		if (left != NULL && right != NULL)
		{
			if (left != preNode && right != preNode)
			{
				if (left->getNodeValue() == keyNode.getNodeValue())
				{
					delete [] stack;
					return left;
				}
				stack[top++] = left;
			}
			else if (left == preNode && right != preNode)
			{
				if (right->getNodeValue() == keyNode.getNodeValue())
				{
					delete [] stack;
					return right;
				}
				stack[top++] = right;
			}
			else if (right == preNode)
				preNode = stack[--top];
		}
		else if (left != NULL && right == NULL)
		{
			if (left != preNode)
			{
				if (left->getNodeValue() == keyNode.getNodeValue())
				{
					delete [] stack;
					return left;
				}
				stack[top++] = left;
			}
			else
				preNode = stack[--top];
		}
		else if (left == NULL && right != NULL)
		{
			if (right != preNode)
			{
				if (right->getNodeValue() == keyNode.getNodeValue())
				{
					delete [] stack;
					return right;
				}
				stack[top++] = right;
			}
			else
				preNode = stack[--top];
		}
		else
			preNode = stack[--top];
	}
	delete [] stack;
	return NULL;
}

// BFS - binary tree
CNode * CBinTree::BFS_node(CNode &keyNode)
{
	int head, tail;
	CNode **queue;
	CNode *node;
	
	if (bTree == NULL)
		return NULL;
		
	queue = new CNode *[numOfNodes];
	head = tail = 0;
	queue[tail++] = bTree;
	while (head < tail)
	{
		node = queue[head++];
		if (node->getNodeValue() == keyNode.getNodeValue())
		{
			delete [] queue;
			return node;
		}
		if (node->getLeftSubNode() != NULL)
			queue[tail++] = node->getLeftSubNode();
		if (node->getRightSubNode() != NULL)
			queue[tail++] = node->getRightSubNode();
	}
	delete [] queue;
	return NULL;
}

CBinTree::~CBinTree()
{
	clear();
}

void CBinTree::clear()
{
	if (bTree->getLeftSubNode() != NULL)
		bTree->getLeftSubNode()->clear();
	if (bTree->getRightSubNode() != NULL)
		bTree->getRightSubNode()->clear();
	delete [] bTree;
	bTree = NULL;
	numOfNodes = 0;
}
