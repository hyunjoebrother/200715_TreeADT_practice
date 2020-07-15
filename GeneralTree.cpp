#include "GeneralTree.h"

#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

//depth- 조상node 갯수
int depth(const Tree& T, const Position& p)
{
	if (p.isRoot()) //root node's depth=0 조상이 없음
		return 0; 
	else
		return 1+depth(T,p.parent()) //1+부모의 depth
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
//순회
//-> tree 내 모든 node를 체계적인 방법으로 방문하여 position 정보를 모은다

//PreOrder Traversal: 전위 순회
//후손node가 넘겨지기 전에 해당 node가 먼저 process

void preorderPrint(const Tree& T, const Position& p)
{
	cout << *p; //원소 출력
	PositionList ch = p.children(); //자식list
	for (Iterator q = ch.begin(); q != ch.end(); ++q)
	{
		cout << " ";
		preorderPrint(T, *q);
	}
}

//PostOrder Traversal: 후위 순회
//자식node가 먼저 처리 후에 해당 node process

void postorderPrint(const Tree& T, const Position& p)
{
	PositionList ch = p.children(); //자식list
	for (Iterator q = ch.begin(); q != ch.end(); ++q)
	{
		postorderPrint(T, *q);
		cout << " ";
	}
	cout << *p;
}