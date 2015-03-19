#ifndef CBINTREE_H
#define CBINTREE_H

#include "Node.h"

class CBinTree
{
private:
	CNode *bTree;
	static int numOfNodes;
	
private:
	void setRootNode(CNode *newRoot);
	
public:
	CBinTree();
	CBinTree(CNode *nodeArray, int len);
	virtual ~CBinTree();
	void output();
	CNode * getRootNode();
	int getNumOfNodes();
	CNode * getNodeParent(CNode *root, CNode &keyNode);
	bool insertNode(CNode &keyNode, bool flag, CNode *newNode);
	bool deleteNode(CNode &keyNode);
	bool nodeIsExist(CNode &keyNode);
	CNode * DFS_node(CNode &keyNode);
	CNode * BFS_node(CNode &keyNode);
	void clear();
};

#endif