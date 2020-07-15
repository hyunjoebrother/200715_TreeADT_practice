//Tree ADT
//각각 data node가 저장되어있는 position 기반, 계층구조

#include <iostream>
using namespace std;
#include <string>

//예외처리

//Array나 LinkedList나 다른 클래스 구현
template <typename E>
class Position<E> //기본 원소 타입
{
private:

public:
	
public:
	E& operator*(); //원소를 구해라
	Position parent() const; //부모 구하라
	PositionList children() const; //노드의 자식을 구하라

	bool isRoot() const; //root node인가?
	bool isExternal const; //외부 node인가?
};

class PositionList //Iterator 반복자
{
private:

public:
	
};



//메인
template <typename E>
class Tree<E>
{
private:

public:
	class Position;
	class PositionList;

public:
	//생성자
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