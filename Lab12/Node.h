#pragma once
struct Node
{
	int data;

	/// <summary>
	/// ��������� �� ��������� �������.
	/// </summary>
	Node* next;

	Node(int data, Node* next);

	~Node();
};