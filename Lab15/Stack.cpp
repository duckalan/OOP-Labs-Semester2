#include "Stack.h"

int Stack::Pop()
{
	// Удаляем старый головной элемент из памяти, возвращая 
	// при этом его данные
	StackNode* oldRoot = _root;
	int returnData = _root->data;
	_root = _root->next;
	delete oldRoot;
	length--;
	return returnData;
}

void Stack::Push(int data)
{
	if (_root == nullptr)
	{
		_root = new StackNode(nullptr, data);
	}
	else
	{
		StackNode* oldRoot = _root;
		StackNode* newRoot = new StackNode(oldRoot, data);
		_root = newRoot;
	}
	length++;
}

void Stack::Print()
{
	StackNode* current = _root;

	while (current != nullptr)
	{
		std::cout << current->data << '\n';
		current = current->next;
	}
	std::cout << std::endl;
}

size_t Stack::GetLength() {
	return length;
}
