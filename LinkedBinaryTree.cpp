#include "LinkedBinaryTree.h"

#include <iostream>
using namespace std;
#include <algorithm>

/*
//depth- ����node ����
int depth(const Tree& T, const Position& p)
{
	if (p.isRoot()) //root node's depth=0 ������ ����
		return 0;
	else
		return 1 + depth(T, p.parent()) //1+�θ��� depth
}

//height- Tree �� ������ node �� depth�� �ִ�
int height(const Tree& T, const Position& p)
{
	if (p.isExternal())
		return 0; //External ����� �� depth=0

	int h = 0;
	PositionList ch = p.children(); //�ڽ��� ����Ʈ

	for (Iterator q = ch.begin(); q != ch.end(); ++q)
		h = max(h, height(T, *q)); //max-> ������� ����

	return 1 + h; //1+�ڽĵ� height �ִ�
}
*/

//������
LinkedBinaryTree::LinkedBinaryTree()
	: _root(NULL),n(0) { }


int LinkedBinaryTree::size() const
{
	return n;
}

bool LinkedBinaryTree::empty() const
{
	return size() == 0;
}

LinkedBinaryTree::Position LinkedBinaryTree::root() const
{
	return Position(_root);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const //��� node�� ����Ʈ
{
	PositionList pl;
	preorder(_root, pl); //���� ��ȸ, _: ����Լ� root()�� �����ϱ� ���� ���� ��� ������.
	return PositionList(pl); //��� ����Ʈ�� ��ȯ
}

void LinkedBinaryTree::addRoot()
{
	_root = new Node;
	n = 1; //�� tree�� root �߰�
}

void LinkedBinaryTree::expandExternal(const Position& p) //External Node Ȯ��
{
	Node* v = p.v; //p�� node
	v->left = new Node; //�� left �ڽ� �߰�
	v->left->par = v; //v�� �θ�
	v->right = new Node; //�� right �ڽ� �߰�
	v->right->par = v; //v�� �θ�
	n = n + 2; //node ���� 2�� �߰�
}

LinkedBinaryTree::Position
LinkedBinaryTree::removeAboveExternal(const Position& p) //p�� �θ� node ����
{
	Node* w = p.v;
	Node* v = w->par; //p�� node�� �θ� ���Ѵ�

	Node* sib = (w == v->left ? v->right : v->left);
	// (����) ? A : B; -> ������ ������ True -> A ���

	if (v == _root) //root�� �ڽ��ΰ�?
	{
		_root = sib; //������ root�� �����
		sib->par = NULL;
	}
	else
	{
		Node* gpar = v->par; //w�� ���θ�
		if (v == gpar->left)
			gpar->left = sib; //�θ� ������ ��ü
		else
			gpar->right = sib;
		sib->par = gpar;
	}
	delete w;
	delete v; //���ŵ� node�� �޸𸮸� ��ȯ
	n = n - 2; //node 2�� ����
	
	return Position(sib);
}

//��ȸ
//-> tree �� ��� node�� ü������ ������� �湮�Ͽ� position ������ ������

//PreOrder Traversal: ���� ��ȸ
//�ļ�node�� �Ѱ����� ���� �ش� node�� ���� process

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const //���� �y���Լ�
{
	pl.push_back(Position(v)); //�� node�� �߰��Ѵ�

	if (v->left != NULL) //���� ����tree�� ��ȸ
		preorder(v->left, pl);

	if (v->right != NULL) //������ ����tree�� ��ȸ
		preorder(v->right, pl);
}