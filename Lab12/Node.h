#pragma once
struct Node
{
	int data;

	/// <summary>
	/// Указатель на следующий элемент.
	/// </summary>
	Node* next;

	Node(int data, Node* next);

	~Node();
};