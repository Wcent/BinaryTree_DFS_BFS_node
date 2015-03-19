#include <iostream>
#include "node.h"

using namespace std;

CNode::CNode()
{
	m_nodeValue = 0;
	m_leftSubNode = NULL;
	m_rightSubNode = NULL;
}


CNode::CNode(int nodeValue)
{
	m_nodeValue = nodeValue;
	m_leftSubNode = NULL;
	m_rightSubNode = NULL;
}

CNode::CNode(CNode &node)
{
	m_nodeValue = node.getNodeValue();
	m_leftSubNode = node.getLeftSubNode();
	m_rightSubNode = node.getRightSubNode();
}

CNode::~CNode()
{
	clear();
}

CNode & CNode::operator =(int nodeValue)
{
	m_nodeValue = nodeValue;
	m_leftSubNode = NULL;
	m_rightSubNode = NULL;
	return (*this);
}

CNode & CNode::operator =(CNode &node)
{
	m_nodeValue = node.getNodeValue();
	m_leftSubNode = node.getLeftSubNode();
	m_rightSubNode = node.getRightSubNode();
	return (*this);
}

void CNode::setNodeValue(int nodeValue)
{
	m_nodeValue = nodeValue;
}

int CNode::getNodeValue()
{
	return m_nodeValue;
}

void CNode::setLeftSubNode(CNode *node)
{
	m_leftSubNode = node;
}

void CNode::setRightSubNode(CNode *node)
{
	m_rightSubNode = node;
}

CNode * CNode::getLeftSubNode()
{
	return m_leftSubNode;
}

CNode * CNode::getRightSubNode()
{
	return m_rightSubNode;
}

void CNode::clear()
{
	m_nodeValue = 0;
	m_leftSubNode = NULL;
	m_rightSubNode = NULL;
}
