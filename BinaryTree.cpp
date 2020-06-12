#include "BinaryTree.h"
#include <iostream>
#include <stack>
using namespace std;
using namespace chuckxue;

template<class DataType>
BiNode<DataType>* BiTree<DataType>::StructureBiTree(BiNode<DataType>* bt)
{
	DataType dt;
	if (dt == '$' || dt == 0)
		bt = NULL;
	else
	{
		bt = new BiNode(DataType);
		bt->data = dt;
		//bt->lvisited = 0;
		//bt->rvisited = 0;
		bt->lchild = StructureBiTree(bt->lchild);
		bt->rchild = StructureBiTree(bt->rchild);
	}
	return bt;
}

template<class DataType>
void BiTree<DataType>::DestructBiTree(BiNode<DataType>* bt)
{
	if (bt != NULL)
	{
		DestructBiTree(bt->rchild);
		DestructBiTree(bt->lchild);
		delete bt;
	}
}

template<class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType>* bt)
{
	if (bt == NULL)
		return;
	cout << bt->data << " ";
	PreOrder(bt->lchild);
	PreOrder(bt->rchild)
}

template<class DataType>
void BiTree<DataType>::InOrder(BiNode<DataType>* bt)
{
	if (bt == NULL)
		return;
	InOrder(bt->lchild);
	cout << bt->data << " ";
	InOrder(bt->rchild);
}

template<class DataType>
void BiTree<DataType>::PostOrder(BiNode<DataType>* bt)
{
	if (bt == NULL)
		return;
	InOrder(bt->lchild);
	InOrder(bt->rchild);
	cout << bt->data << " ";
}

template<class DataType>
void BiTree<DataType>::NonRecursivePreOrder(BiNode<DataType>* bt)
{
	if (bt == NULL)
		return;
	stack<DataType>stk;
	BiNode<DataType>* p = bt;
	while (p || !stk.empty())
	{
		if (p)
		{
			cout << p->data << " ";
			stk.push(p);
			p = p->lchild;
		}
		else
		{
			p = stk.top();
			stk.pop();
			p = p->rchild;
		}
	}
}

template<class DataType>
void BiTree<DataType>::NonRecursiveInOrder(BiNode<DataType>* bt)
{
	if (bt == NULL)
		return;
	stack<DataType>stk;
	BiNode<DataType>* p = bt;
	while (p || !stk.empty())
	{
		if (p)
		{
			stk.push(p);
			p = p->lchild;
		}
		else
		{
			p = stk.top();
			cout << p->data << " ";
			stk.pop();
			p = p->rchild;
		}
	}
}

template<class DataType>
void BiTree<DataType>::NonRecursivePostOrder(BiNode<DataType>* bt)
{
	if (bt == NULL)
		return;
	stack<DataType>stk;
	BiNode<DataType>* r = NULL, p = bt;
	while (p || !stk.empty())
	{
		if (p)
		{
			stk.push(p);
			p = p->lchild;
		}
		else
		{
			p = stk.top();
			if (p->rchild && p->rchild != r)
			{
				p = p->rchild;
				stk.push(p);
				p = p->lchild;
			}
			else
			{
				cout << p->data << " ";
				r = p;
				stk.pop();
				p = NULL;//不重置p为NULL，无法进入第一个else，会进入第一个if则刚从stk中pop的又会push进来
			}
		}
	}
}