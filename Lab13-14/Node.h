#pragma once
#include "Student.h"

struct Node
{
	 Student student;

	/// <summary>
	/// ��������� �� ��������� �������.
	/// </summary>
	Node* next;

	Node(Student student, Node* next);

	~Node();
};