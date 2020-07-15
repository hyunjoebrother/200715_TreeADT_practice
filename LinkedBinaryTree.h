//Tree ADT
//���� data node�� ����Ǿ��ִ� position ���, ��������

//Binary Tree: �� Internal node �ִ� 2�� children

#include <iostream>
using namespace std;
#include <algorithm>
#include <list> //��ġ ����Ʈ

//����ó��

//Array�� LinkedList�� �ٸ� Ŭ���� ����


//����
typedef int Elem;
class LinkedBinaryTree
{
private:

protected:
	//Node ����
	struct Node { //Tree�� node
		Elem elt; //������ ��
		Node* par; //�θ�
		Node* left; //�ڽ�
		Node* right;
		//������
		Node()
			:elt(),par(NULL),left(NULL),right(NULL){ }
	};
public:
	//Position ����
	class Position
	{
	private:
		Node* v; //node�� ����Ű�� ������

	public:
		//������
		Position(Node* _v=NULL)
			:v(_v){ }

		Elem& operator*() //���� ��ȯ
		{
			return v->elt; 
		}

		Position left() const //���� �ڽ� ��ȯ
		{
			return Position(v->left);
		}

		Position right() const
		{
			return Position(v->right);
		}

		Position parent() const //�θ� ��ȯ
		{
			return Position(v->par);
		}

		bool isRoot() const //root node?
		{
			return v->par == NULL;
		}

		bool isExternal() const //External node = left&right �ڽ� node ��� ���� ��
		{
			return v->left == NULL && v->right == NULL;
		}

		friend class LinkedBinaryTree; //Tree�� ������ �� �ֵ��� ��
	};
	typedef std::list<Position> PositionList; //��ġ�� ����Ʈ <list>

public:
	//������
	LinkedBinaryTree();

	int size() const;
	bool empty() const;

	Position root() const; //root node ���Ѵ�
	PositionList positions() const; //node�� ����Ʈ

	void addRoot(); //�� tree�� node �߰�
	void expandExternal(const Position& p); //External Node Ȯ��
	Position removeAboveExternal(const Position& p); //p�� �θ� node ����

protected:
	void preorder(Node* v, PositionList& pl) const; //���� �y���Լ�
	
private:
	Node* _root; //root���� ������
	int n; //node ����
};