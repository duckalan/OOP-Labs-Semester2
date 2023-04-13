#include "Node.h"

Node::Node(Student student, Node* next) : student(student)
{
	this->next = next;
}

Node::~Node()
{
	delete next;
}
