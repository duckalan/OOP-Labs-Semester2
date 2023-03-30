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
	// ��������� ���������� ����� � ��������� �� 0 �� 99, �����������
	// �� (-1) � ������� ���������� �����
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
	// ����� ������
	List newList;

	// ������� ������� ������� ������
	Node* mainCurrent = head;

	// ������� ������� ������ ������
	Node* newCurrent = new Node(0, nullptr);
	size_t nodeCounter = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (predicate(mainCurrent->data))
		{
			// �������� ������ ������ �� ����� ������� �
			// ���������� �������. ��� ������� �������� � �����
			// ������ ����� ����� �����
			Node* temp = new Node(mainCurrent->data, nullptr);

			// ������ ���������� ������� ������ ����
			// �������� � ����� ������
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
	// ������-���������
	return CreateList([](int element) {
			return element % 2 == 0 && element > 0; 
		});
}

List List::CreateOddNegativeList()
{
	// ������-���������
	return CreateList([](int element) {
			return element % 2 == -1 && element < 0;
		});
}