#pragma once
#include "Node.h"

struct List
{
	/// <summary>
	/// Длина списка.
	/// </summary>
	size_t length;

	/// <summary>
	/// Головной элемент.
	/// </summary>
	Node* head;

	/// <summary>
	/// Создание пустого списка.
	/// </summary>
	List();

	/// <summary>
	/// Создание списка с количеством <paramref name="nodeCount"/> элементов,
	/// включая головной.
	/// </summary>
	List(size_t nodeCount);

	/// <summary>
	/// Вывод всех элементов списка в консоль.
	/// </summary>
	void Print();

	/// <summary>
	/// Вставка узла <paramref name="newNode"/> в конец списка.
	/// </summary>
	void InsertToEnd(Node* newNode);

	/// <summary>
	/// Создание из текущего списка нового списка на основании 
	/// условия <paramref name="predicate"/> для его элементов
	/// </summary>
	List CreateList(bool (*predicate)(int element));

	/// <summary>
	/// Создание из текущего списка новый список, который содержит
	/// только чётные положительные элементы текущего.
	/// </summary>
	List CreateEvenPositiveList();

	/// <summary>
	/// Создание из текущего списка новый список, который содержит
	/// только нечётные отрицательные элементы текущего.
	/// </summary>
	List CreateOddNegativeList();
};