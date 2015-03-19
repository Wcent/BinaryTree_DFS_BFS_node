#include <iostream>
#include "Node.h"
#include "BinTree.h"

using namespace std;

int main()
{
	CNode nodeArray[10] = {3, 2, 4, 6, 1, 9, 5, 8, 0, 7};
	CBinTree binTree(nodeArray, 10);

	cout<<"nodes array: ";
	for (int i=0; i<10; i++)
		cout<<nodeArray[i].getNodeValue()<<' ';
	cout<<endl;

	cout<<"binary tree: ";
	binTree.output();
	cout<<endl;

	
	bool flag = binTree.nodeIsExist(CNode(1));
	cout<<"is node(1) exist?"<<endl<<(flag?"Yes,":"No");
	if (flag)
		cout<<" with value: "<<binTree.BFS_node(CNode(1))->getNodeValue()<<endl;
	cout<<endl;

	flag = binTree.deleteNode(CNode(1));
	cout<<(flag?"after delete node(1): ":"delete faile")<<endl;
	binTree.output();
	cout<<endl;

	flag = binTree.insertNode(CNode(2), false, &CNode(1));
	cout<<(flag?"after insert node(1): ":"insert faile")<<endl;
	binTree.output();
	cout<<endl;

	flag = binTree.nodeIsExist(CNode(1));
	cout<<"is node(1) exist?"<<endl<<(flag?"Yes,":"No");
	if (flag)
		cout<<" with value: "<<binTree.BFS_node(CNode(1))->getNodeValue()<<endl	;
	cout<<endl;

	flag = binTree.insertNode(CNode(4), false, &CNode(11));
	cout<<(flag?"after insert node(11): ":"insert faile")<<endl;
	binTree.output();
	cout<<endl;

	flag = binTree.insertNode(CNode(4), true, &CNode(10));
	cout<<(flag?"after insert node(10): ":"insert faile")<<endl;
	binTree.output();
	cout<<endl;

	flag = binTree.nodeIsExist(CNode(10));
	cout<<"is node(10) exist?"<<endl<<(flag?"Yes,":"No");
	if (flag)
		cout<<" with value: "<<binTree.DFS_node(CNode(10))->getNodeValue();
	cout<<endl;

	return 0;
}

