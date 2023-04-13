#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "LinkedList.h"

Node* LinkedList::GetNodeAt(size_t index)
{
	if (index == 0)
	{
		return root;
	}
	if (index >= length)
	{
		std::cerr << "������ " << index << " ������� �� ������� ������ [0;" << length - 1 << "]\n";
		return nullptr;
	}

	Node* current = root;
	for (size_t i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}

void LinkedList::SwapNodes(Node* n1, Node* n2, size_t n1Index)
{
	Node* last = GetNodeAt(length - 1);

	// ������ �� 2 ���������
	if (n1 == root && n2 == last)
	{
		n1->next = n2;
		n2->next = n1;
		return;
	}

	// ������������ ��������� � ���������� �� ��� ���������
	if (n1 == root)
	{
		n1->next = n2->next;
		n2->next = n1;
		root = n2;
		return;
	}
	
	// ������������ �������������� � ���������� ���������
	if (n2 == last)
	{
		// ������� ����� �������������
		Node* preN1 = GetNodeAt(n1Index - 1);
		n2->next = n1;
		n1->next = nullptr;
		preN1->next = n2;
		return;
	}

	// ������������ ��������� ����� ��������� � ��������
	// ������� ����� n1
	Node* preN1 = GetNodeAt(n1Index - 1);
	// ������� ����� n2
	Node* afterN2 = n2->next;
	n1->next = afterN2;
	n2->next = n1;
	preN1->next = n2;
}

void LinkedList::SortBy(bool(*comparer)(Student s1, Student s2))
{
	if (length < 2)
	{
		std::cerr << "���������� ������ � ������ " << length << " ����������\n";
		return;
	}

	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - i - 1; j++)
		{
			Node* n1 = GetNodeAt(j);
			Node* n2 = GetNodeAt(j + 1);

			if (comparer(n1->student, n2->student))
			{
				SwapNodes(n1, n2, j);
			}
		}
	}
}

LinkedList LinkedList::FindBy(void* toFind, bool (*equalCondition)(Student student, void* value))
{
	LinkedList list;
	size_t numOfFoundStudents = 0;
	Node* current = root;

	for (size_t i = 0; i < length; i++)
	{
		if (equalCondition(current->student, toFind))
		{
			list.InsertAt(numOfFoundStudents, current->student);
			numOfFoundStudents++;
		}
		current = current->next;
	}

	return list;
}

LinkedList::LinkedList()
{
	root = nullptr;
	length = 0;
}

void LinkedList::InitFromFile(const char* filePath)
{
	root = nullptr;
	FILE* f = fopen(filePath, "r");

	if (!f)
	{
		length = 0;
		perror("������ ��� �������� �����: ");
	}
	else
	{
		size_t studentCounter = 0;
		char fullName[Student::FullNameLength];
		char birthDate[Student::BirthDateLength];
		char surname[Student::FullNameLength - 4];
		char initials[5];
		int performance;

		while (!feof(f))
		{
			fscanf(f, "%s %s %s %d", surname, initials, birthDate, &performance);

			strcpy(fullName, surname);
			strcat(fullName, " ");
			strcat(fullName, initials);

			Student student(fullName, birthDate, (Performance)performance);
			InsertAt(studentCounter, student);
			studentCounter++;
		}
		length = studentCounter;

		fclose(f);
	}
}

void LinkedList::InsertAt(size_t index, Student student)
{
	// ������� � ������ ������.
	if (index == 0)
	{
		if (root == nullptr)
		{
			root = new Node(student, nullptr);
		}
		else
		{
			Node* temp = new Node(student, root);
			root = temp;
		}
		length++;
		return;
	}
	if (index > length)
	{
		std::cerr << "������ " << index << " ������� �� ������� ������ [0;" << length - 1 << "]\n";
		return;
	}

	// ������� �� ���� ����� ����������� ��������
	Node* preInserted = GetNodeAt(index - 1);

	// ������� � ����� ������
	if (index == length)
	{
		Node* temp = new Node(student, nullptr);
		preInserted->next = temp;
	}
	// ������� � ����� ������ �����.
	else
	{
		// ��������� ����� ������� � ����� �� ������ �������,
		// ����� ��������� ������� ����� ����������� �������� 
		// � ����� ���������
		Node* temp = new Node(student, preInserted->next);
		preInserted->next = temp;
	}
	
	length++;
}

void LinkedList::DeleteAt(size_t index)
{
	// �������� ��������� ��������
	if (index == 0)
	{
		if (root != nullptr)
		{
			root = root->next;
			length--;
		}
		return;
	}
	if (index >= length)
	{
		std::cerr << "������ " << index << " ������� �� ������� ������ [0;" << length - 1 << "]\n";
		return;
	}

	// ������� �� ���� ����� ��������� ��������
	Node* current = GetNodeAt(index - 1);

	// �������� � ����� ������
	if (index == length - 1)
	{
		Node* temp = current->next;
		current->next = nullptr;
		delete temp;
	}
	// �������� � ����� ������ �����
	else
	{
		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}
	length--;
}

void LinkedList::SortByFullName()
{
	SortBy([](Student s1, Student s2) {
		// ���������� ������ ���� ������� �� ��������
		return s1.GetFullName()[0] > s2.GetFullName()[0];
		});
}

void LinkedList::SortByBirthDate()
{

	SortBy([](Student s1, Student s2) 
		{
			// Student::BirthDateLength - 2 - ����� ���� �������� ��� 
			// �������������� �����
			char birthDate1[Student::BirthDateLength - 2]{};
			char birthDate2[Student::BirthDateLength - 2]{};
			size_t digitCounter = 0;

			// ��������������� �������� ���� DD.MM.YYYY � ������ YYYYMMDD.
			// ������� ������ �� �������� ������� �������� � ����������.
			
			// ������� ���������� ���
			for (int i = Student::BirthDateLength - 5 ; i < Student::BirthDateLength - 1; i++)
			{
				birthDate1[digitCounter] = s1.GetBirthDate()[i];
				birthDate2[digitCounter] = s2.GetBirthDate()[i];
				digitCounter++;
			}
			// ����� �����
			for (int i = Student::BirthDateLength - 8; i < Student::BirthDateLength - 6; i++)
			{
				birthDate1[digitCounter] = s1.GetBirthDate()[i];
				birthDate2[digitCounter] = s2.GetBirthDate()[i];
				digitCounter++;
			}
			// ����� ����
			for (int i = 0; i < Student::BirthDateLength - 9; i++)
			{
				birthDate1[digitCounter] = s1.GetBirthDate()[i];
				birthDate2[digitCounter] = s2.GetBirthDate()[i];
				digitCounter++;
			}

			// ������������ ������ YYYYMMDD � ����� YYYYMMDD � ����������
			return atoll(birthDate1) > atoll(birthDate2);
		});
}

void LinkedList::SortByPerformance()
{
	SortBy([](Student s1, Student s2) {
		return s1.GetPerformance() < s2.GetPerformance() ;
		});
}

LinkedList LinkedList::FindByFullName(const char* toFind)
{
	return FindBy(
		(void*) toFind,
		[](Student student, void* value)
		{
			return strcmp(student.GetFullName(), (char*)value) == 0;
		});
}

LinkedList LinkedList::FindByBirthDate(const char* toFind)
{
	return FindBy(
		(void*) toFind,
		[](Student student, void* value)
		{
			return strcmp(student.GetBirthDate(), (char*)value) == 0;
		});
}

LinkedList LinkedList::FindByPerformance(Performance toFind)
{
	return FindBy(
		(void*) &toFind,
		[](Student student, void* value)
		{
			return student.GetPerformance() == (*(Performance*) value);
		});
}

void LinkedList::Print()
{
	Node* current = root;
	for (size_t i = 0; i < length; i++)
	{
		current->student.PrintInfo();
		std::cout << '\n';
		current = current->next;
	}
	std::cout << std::endl;
}

size_t LinkedList::GetLength()
{
	return length;
}