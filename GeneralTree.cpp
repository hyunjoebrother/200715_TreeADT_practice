#include "GeneralTree.h"

#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

//depth- ����node ����
int depth(const Tree& T, const Position& p)
{
	if (p.isRoot()) //root node's depth=0 ������ ����
		return 0; 
	else
		return 1+depth(T,p.parent()) //1+�θ��� depth
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
//��ȸ
//-> tree �� ��� node�� ü������ ������� �湮�Ͽ� position ������ ������

//PreOrder Traversal: ���� ��ȸ
//�ļ�node�� �Ѱ����� ���� �ش� node�� ���� process

void preorderPrint(const Tree& T, const Position& p)
{
	cout << *p; //���� ���
	PositionList ch = p.children(); //�ڽ�list
	for (Iterator q = ch.begin(); q != ch.end(); ++q)
	{
		cout << " ";
		preorderPrint(T, *q);
	}
}

//PostOrder Traversal: ���� ��ȸ
//�ڽ�node�� ���� ó�� �Ŀ� �ش� node process

void postorderPrint(const Tree& T, const Position& p)
{
	PositionList ch = p.children(); //�ڽ�list
	for (Iterator q = ch.begin(); q != ch.end(); ++q)
	{
		postorderPrint(T, *q);
		cout << " ";
	}
	cout << *p;
}