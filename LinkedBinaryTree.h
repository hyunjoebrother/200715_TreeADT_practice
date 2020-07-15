//Tree ADT
//각각 data node가 저장되어있는 position 기반, 계층구조

//Binary Tree: 각 Internal node 최대 2개 children

#include <iostream>
using namespace std;
#include <algorithm>
#include <list> //위치 리스트

//예외처리

//Array나 LinkedList나 다른 클래스 구현


//메인
typedef int Elem;
class LinkedBinaryTree
{
private:

protected:
	//Node 선언
	struct Node { //Tree의 node
		Elem elt; //원소의 값
		Node* par; //부모
		Node* left; //자식
		Node* right;
		//생성자
		Node()
			:elt(),par(NULL),left(NULL),right(NULL){ }
	};
public:
	//Position 선언
	class Position
	{
	private:
		Node* v; //node를 가리키는 포인터

	public:
		//생성자
		Position(Node* _v=NULL)
			:v(_v){ }

		Elem& operator*() //원소 반환
		{
			return v->elt; 
		}

		Position left() const //왼쪽 자식 반환
		{
			return Position(v->left);
		}

		Position right() const
		{
			return Position(v->right);
		}

		Position parent() const //부모 반환
		{
			return Position(v->par);
		}

		bool isRoot() const //root node?
		{
			return v->par == NULL;
		}

		bool isExternal() const //External node = left&right 자식 node 모두 없을 때
		{
			return v->left == NULL && v->right == NULL;
		}

		friend class LinkedBinaryTree; //Tree를 접근할 수 있도록 함
	};
	typedef std::list<Position> PositionList; //위치의 리스트 <list>

public:
	//생성자
	LinkedBinaryTree();

	int size() const;
	bool empty() const;

	Position root() const; //root node 구한다
	PositionList positions() const; //node의 리스트

	void addRoot(); //빈 tree에 node 추가
	void expandExternal(const Position& p); //External Node 확장
	Position removeAboveExternal(const Position& p); //p와 부모 node 삭제

protected:
	void preorder(Node* v, PositionList& pl) const; //전위 퍈의함수
	
private:
	Node* _root; //root로의 포인터
	int n; //node 갯수
};