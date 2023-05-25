#pragma once
#include "Student.h"

struct Node
{
	 Student student;

	/// <summary>
	/// Указатель на следующий элемент.
	/// </summary>
	Node* next;

	Node(Student student, Node* next);

	~Node();
};