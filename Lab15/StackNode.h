#pragma once
struct StackNode
{
	int data;

	/// <summary>
	/// Указатель на следующий элемент.
	/// </summary>
	StackNode* next;

	StackNode(StackNode* next, int data);
};

