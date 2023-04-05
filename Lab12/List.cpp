#include <iostream>
#include <ctime>
#include "List.h"

List::List() 
{
	length = 0;
	head = nullptr;
}

List::List(size_t nodeCount)
{
	srand(time(0));
	length = nodeCount;
	// Генерация случайного числа в диапазоне от 0 до 99, умноженного
	// на (-1) в степени случайного числа
	head = new Node((rand() % 100) * pow((-1), rand()), nullptr);
	Node* current = head;

	for (size_t i = 1; i < nodeCount; i++)
	{
		Node* temp = new Node((rand() % 100) * pow((-1), rand()), nullptr);
		current->next = temp;
		current = temp;
	}
}

void List::Print()
{
	Node* current = head;
	for (size_t i = 0; i < length; i++)
	{
		std::cout << current->data << " ";
		current = current->next;
	}

	std::cout << std::endl;
}

void List::InsertToEnd(Node* newNode)
{
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node* current = head;
		// Доход до последнего элемента
		while (current->next != nullptr)
		{
			current = current->next;
		}

		// Делаем новый узел последним
		newNode->next = nullptr;
		current->next = newNode;
	}

	length++;
}

List List::CreateList(bool (*predicate)(int element))
{
	// Новый список
	List newList;

	// Текущий элемент старого списка
	Node* mainCurrent = head;

	for (size_t i = 0; i < length; i++)
	{
		if (predicate(mainCurrent->data))
		{
			// Элементы нового списка не будут связаны с
			// элементами старого. Для каждого элемента в новом
			// списке будет новый адрес
			Node* temp = new Node(mainCurrent->data, nullptr);

			newList.InsertToEnd(temp);
		}
		mainCurrent = mainCurrent->next;
	}
	return newList;
}

List List::CreateEvenPositiveList()
{
	// Лямбда-выражение
	return CreateList([](int element) {
			return element % 2 == 0 && element > 0; 
		});
}

List List::CreateOddNegativeList()
{
	// Лямбда-выражение
	return CreateList([](int element) {
			return element % 2 == -1 && element < 0;
		});
}