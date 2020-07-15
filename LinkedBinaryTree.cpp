#include "LinkedBinaryTree.h"

#include <iostream>
using namespace std;
#include <algorithm>

/*
//depth- 조상node 갯수
int depth(const Tree& T, const Position& p)
{
	if (p.isRoot()) //root node's depth=0 조상이 없음
		return 0;
	else
		return 1 + depth(T, p.parent()) //1+부모의 depth
}

//height- Tree 내 임의의 node 중 depth의 최댓값
int height(const Tree& T, const Position& p)
{
	if (p.isExternal())
		return 0; //External 노드일 때 depth=0

	int h = 0;
	PositionList ch = p.children(); //자식의 리스트

	for (Iterator q = ch.begin(); q != ch.end(); ++q)
		h = max(h, height(T, *q)); //max-> 헤더파일 ㄱㄱ

	return 1 + h; //1+자식들 height 최댓값
}
*/

//생성자
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

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const //모든 node의 리스트
{
	PositionList pl;
	preorder(_root, pl); //전위 순회, _: 멤버함수 root()와 구분하기 위해 ㅇㅇ 얘는 포인터.
	return PositionList(pl); //결과 리스트를 반환
}

void LinkedBinaryTree::addRoot()
{
	_root = new Node;
	n = 1; //빈 tree에 root 추가
}

void LinkedBinaryTree::expandExternal(const Position& p) //External Node 확장
{
	Node* v = p.v; //p의 node
	v->left = new Node; //새 left 자식 추가
	v->left->par = v; //v는 부모
	v->right = new Node; //새 right 자식 추가
	v->right->par = v; //v는 부모
	n = n + 2; //node 갯수 2개 추가
}

LinkedBinaryTree::Position
LinkedBinaryTree::removeAboveExternal(const Position& p) //p와 부모 node 삭제
{
	Node* w = p.v;
	Node* v = w->par; //p의 node와 부모를 구한다

	Node* sib = (w == v->left ? v->right : v->left);
	// (조건) ? A : B; -> 조건이 맞으면 True -> A 출력

	if (v == _root) //root의 자식인가?
	{
		_root = sib; //형제를 root로 만든다
		sib->par = NULL;
	}
	else
	{
		Node* gpar = v->par; //w의 조부모
		if (v == gpar->left)
			gpar->left = sib; //부모를 형제로 대체
		else
			gpar->right = sib;
		sib->par = gpar;
	}
	delete w;
	delete v; //제거된 node의 메모리를 반환
	n = n - 2; //node 2개 감소
	
	return Position(sib);
}

//순회
//-> tree 내 모든 node를 체계적인 방법으로 방문하여 position 정보를 모은다

//PreOrder Traversal: 전위 순회
//후손node가 넘겨지기 전에 해당 node가 먼저 process

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const //전위 퍈의함수
{
	pl.push_back(Position(v)); //이 node를 추가한다

	if (v->left != NULL) //왼쪽 서브tree를 순회
		preorder(v->left, pl);

	if (v->right != NULL) //오른쪽 서브tree를 순회
		preorder(v->right, pl);
}