//Tree ADT
//���� data node�� ����Ǿ��ִ� position ���, ��������

#include <iostream>
using namespace std;
#include <string>

//����ó��

//Array�� LinkedList�� �ٸ� Ŭ���� ����
template <typename E>
class Position<E> //�⺻ ���� Ÿ��
{
private:

public:
	
public:
	E& operator*(); //���Ҹ� ���ض�
	Position parent() const; //�θ� ���϶�
	PositionList children() const; //����� �ڽ��� ���϶�

	bool isRoot() const; //root node�ΰ�?
	bool isExternal const; //�ܺ� node�ΰ�?
};

class PositionList //Iterator �ݺ���
{
private:

public:
	
};



//����
template <typename E>
class Tree<E>
{
private:

public:
	class Position;
	class PositionList;

public:
	//������
	Tree();
	
	int size() const;
	bool empty() const;

	Position root() const;
	PositionList positions() const;

	position p.parent();
	list<position> p.children();

	bool p.isRoot();
	bool p.isExternal();


};