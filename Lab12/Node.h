#pragma once
struct Node
{
	int data;

	/// <summary>
	/// ”казатель на следующий элемент.
	/// </summary>
	Node* next;

	Node(int data, Node* next);

	~Node();
};