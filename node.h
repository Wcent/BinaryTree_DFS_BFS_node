#ifndef CNODE_H
#define CNODE_H

class CNode
{
private:
	int m_nodeValue;
	CNode *m_leftSubNode;
	CNode *m_rightSubNode;
	
public:
	CNode();
	CNode(int nodeValue);
	CNode(CNode &node);
	virtual ~CNode();
	CNode & operator =(int nodeValue);
	CNode & operator =(CNode &node);
	void setNodeValue(int value);
	int getNodeValue();
	void setLeftSubNode(CNode *node);
	void setRightSubNode(CNode *node);
	CNode * getLeftSubNode();
	CNode * getRightSubNode();
	void clear();
};

#endif