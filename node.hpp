#pragma once;
#include "student.hpp"

class Node : public Student
{
private:
	Node* link; // 다음 노드를 가리키는 포인터 변수
public:
	Node(int id = 0, const char* name = "", const char* dept="")
		: Student(id, name, dept) 
	{
		link = nullptr;
	}
	~Node(void)
	{}
	
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};