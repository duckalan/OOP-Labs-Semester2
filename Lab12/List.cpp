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

List List::CreateList(bool (*predicate)(int element))
{
	// Новый список
	List newList;

	// Текущий элемент старого списка
	Node* mainCurrent = head;

	// Текущий элемент нового списка
	Node* newCurrent = new Node(0, nullptr);
	size_t nodeCounter = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (predicate(mainCurrent->data))
		{
			// Элементы нового списка не будут связаны с
			// элементами старого. Для каждого элемента в новом
			// списке будет новый адрес
			Node* temp = new Node(mainCurrent->data, nullptr);

			// Первый подходящий элемент должен быть
			// головным в новом списке
			if (newList.head == nullptr)
			{
				newList.head = temp;
				newCurrent = newList.head;
			}
			else
			{
				newCurrent->next = temp;
				newCurrent = temp;
			}
			nodeCounter++;
		}
		mainCurrent = mainCurrent->next;
	}
	newList.length = nodeCounter;
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