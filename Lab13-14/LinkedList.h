#pragma once
#include "Node.h"

/// <summary>
/// ����������� ������, ���������� �������� �������� ������� 
/// ������ Student (��������).
/// </summary>
class LinkedList
{
private:
	/// <summary>
	/// ����� ������.
	/// </summary>
	size_t length;

	/// <summary>
	/// �������� �������.
	/// </summary>
	Node* root;

	/// <summary>
	/// �������� ������� �� ������� <paramref name="index"/>.
	/// </summary>
	/// <returns>����� ���� �� ������� <paramref name="index"/>.</returns>
	Node* GetNodeAt(size_t index);

	/// <summary>
	/// ������������ ������� ���� ���������.
	/// </summary>
	void SwapNodes(Node* n1, Node* n2, size_t n1Index);

	/// <summary>
	/// ���������� ������ � �������������� ����������� 
	/// <paramref name="comparer"/>
	/// </summary>
	/// <param name="comparer">���������� ������� ��������� ��� ����������.</param>
	void SortBy(bool (*comparer)(Student s1, Student s2));

	/// <summary>
	/// ����� ��������� �� ��������� <paramref name="toFind"/> � ��������
	/// �������� <paramref name="equalCondition"/>.
	/// </summary>
	/// <param name="equalCondition"> 
	/// ���������� ������� ��������� ������-���� ���� <paramref name="student"/> 
	/// � ������������� �������� <paramref name="value"/>.
	/// </param>
	/// <returns>������ � ���������� ����������. 
	/// ���� �� ���� ������� �� ������, ������ ������.</returns>
	LinkedList FindBy(void* toFind, bool (*equalCondition) (Student student, void* value));
public:
	/// <summary>
	/// �������� ������� ������.
	/// </summary>
	LinkedList();

	/// <summary>
	/// ������������� ������ ������� �� ���������� �����.
	/// </summary>
	void InitFromFile(const char* filePath);

	/// <summary>
	/// �������� ������� <paramref name="student"/> �� �������
	/// <paramref name="index"/>
	/// </summary>
	void InsertAt(size_t index, Student student);

	/// <summary>
	/// ������� ������� �� ������� <paramref name="index"/>
	/// </summary>
	void DeleteAt(size_t index);

	/// <summary>
	/// ���������� ������� �� ��������.
	/// </summary>
	void SortByFullName();

	/// <summary>
	/// ���������� �� ���� �������� �� �����������.
	/// </summary>
	void SortByBirthDate();

	/// <summary>
	/// ���������� �� ������������ �� ��������.
	/// </summary>
	void SortByPerformance();

	/// <summary>
	/// ����� ���� ��������� � ��������� ���.
	/// </summary>
	/// <param name="toFind">��� ��� ������. ������: ������� ��������</param>
	/// <returns>
	/// ������ � ���������� ����������. 
	/// ���� �� ���� ������� �� ������, ������ ������.
	/// </returns>
	LinkedList FindByFullName(const char* toFind);

	/// <summary>
	/// ����� ���� ��������� � ��������� ����� ��������.
	/// </summary>
	/// <param name="toFind">���� �������� ��� ������. ������: DD.MM.YYYY</param>
	/// <returns>
	/// ������ � ���������� ����������. 
	/// ���� �� ���� ������� �� ������, ������ ������.
	/// </returns>
	LinkedList FindByBirthDate(const char* toFind);

	/// <summary>
	/// ����� ���� ��������� � ��������� �������������.
	/// </summary>
	/// <param name="toFind">������������ ��� ������.</param>
	/// <returns>
	/// ������ � ���������� ����������. 
	/// ���� �� ���� ������� �� ������, ������ ������.
	/// </returns>
	LinkedList FindByPerformance(Performance toFind);

	/// <summary>
	/// ����� ����� ������ � �������.
	/// </summary>
	void Print();

	/// <summary>
	/// �������� ����� ������.
	/// </summary>
	size_t GetLength();
};