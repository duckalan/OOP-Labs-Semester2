#pragma once
#include "Node.h"

struct List
{
	/// <summary>
	/// ����� ������.
	/// </summary>
	size_t length;

	/// <summary>
	/// �������� �������.
	/// </summary>
	Node* head;

	/// <summary>
	/// �������� ������� ������.
	/// </summary>
	List();

	/// <summary>
	/// �������� ������ � ����������� <paramref name="nodeCount"/> ���������,
	/// ������� ��������.
	/// </summary>
	List(size_t nodeCount);

	/// <summary>
	/// ����� ���� ��������� ������ � �������.
	/// </summary>
	void Print();

	/// <summary>
	/// �������� �� �������� ������ ������ ������ �� ��������� 
	/// ������� <paramref name="predicate"/> ��� ��� ���������
	/// </summary>
	List CreateList(bool (*predicate)(int element));

	/// <summary>
	/// �������� �� �������� ������ ����� ������, ������� ��������
	/// ������ ������ ������������� �������� ��������.
	/// </summary>
	List CreateEvenPositiveList();

	/// <summary>
	/// �������� �� �������� ������ ����� ������, ������� ��������
	/// ������ �������� ������������� �������� ��������.
	/// </summary>
	List CreateOddNegativeList();
};