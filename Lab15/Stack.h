#pragma once
#include <iostream>
#include "StackNode.h"

class Stack
{
private: 
	/// <summary>
	/// Головной элемент.
	/// </summary>
	StackNode* _root = nullptr;

	size_t length;
public:
	/// <summary>
	/// Удалить из стека последний элемент, получив при этом его данные.
	/// </summary>
	int Pop();

	/// <summary>
	/// Добавить в стек элемент с данными <paramref name="data"/>.
	/// </summary>
	void Push(int data);

	/// <summary>
	/// Вывести весь стек в консоль.
	/// </summary>
	void Print();

	size_t GetLength();
};

