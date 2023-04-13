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
		std::cerr << "Индекс " << index << " выходит за границы списка [0;" << length - 1 << "]\n";
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

	// Список из 2 элементов
	if (n1 == root && n2 == last)
	{
		n1->next = n2;
		n2->next = n1;
		return;
	}

	// Перестановка корневого и следующего за ним элементов
	if (n1 == root)
	{
		n1->next = n2->next;
		n2->next = n1;
		root = n2;
		return;
	}
	
	// Перестановка предпоследнего и последнего элементов
	if (n2 == last)
	{
		// Элемент перед предпоследним
		Node* preN1 = GetNodeAt(n1Index - 1);
		n2->next = n1;
		n1->next = nullptr;
		preN1->next = n2;
		return;
	}

	// Перестановка элементов между начальным и конечным
	// Элемент перед n1
	Node* preN1 = GetNodeAt(n1Index - 1);
	// Элемент после n2
	Node* afterN2 = n2->next;
	n1->next = afterN2;
	n2->next = n1;
	preN1->next = n2;
}

void LinkedList::SortBy(bool(*comparer)(Student s1, Student s2))
{
	if (length < 2)
	{
		std::cerr << "Сортировка списка с длиной " << length << " невозможна\n";
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
		perror("Ошибка при открытии файла: ");
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
	// Вставка в начало списка.
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
		std::cerr << "Индекс " << index << " выходит за границы списка [0;" << length - 1 << "]\n";
		return;
	}

	// Доходим до узла перед вставляемым индексом
	Node* preInserted = GetNodeAt(index - 1);

	// Вставка в конец списка
	if (index == length)
	{
		Node* temp = new Node(student, nullptr);
		preInserted->next = temp;
	}
	// Вставка в любое другое место.
	else
	{
		// Связываем новый элемент с узлом на нужном индексе,
		// затем связываем элемент перед вставляемым индексом 
		// с новым элементом
		Node* temp = new Node(student, preInserted->next);
		preInserted->next = temp;
	}
	
	length++;
}

void LinkedList::DeleteAt(size_t index)
{
	// Удаление головного элемента
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
		std::cerr << "Индекс " << index << " выходит за границы списка [0;" << length - 1 << "]\n";
		return;
	}

	// Доходим до узла перед удаляемым индексом
	Node* current = GetNodeAt(index - 1);

	// Удаление в конце списка
	if (index == length - 1)
	{
		Node* temp = current->next;
		current->next = nullptr;
		delete temp;
	}
	// Удаление в любом другом месте
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
		// Сортировка первых букв фамилий по алфавиту
		return s1.GetFullName()[0] > s2.GetFullName()[0];
		});
}

void LinkedList::SortByBirthDate()
{

	SortBy([](Student s1, Student s2) 
		{
			// Student::BirthDateLength - 2 - длина даты рождения без 
			// разделительных точек
			char birthDate1[Student::BirthDateLength - 2]{};
			char birthDate2[Student::BirthDateLength - 2]{};
			size_t digitCounter = 0;

			// Преобразовываем строчную дату DD.MM.YYYY в строку YYYYMMDD.
			// Порядок выбран по важности каждого значения в сортировке.
			
			// Сначала записываем год
			for (int i = Student::BirthDateLength - 5 ; i < Student::BirthDateLength - 1; i++)
			{
				birthDate1[digitCounter] = s1.GetBirthDate()[i];
				birthDate2[digitCounter] = s2.GetBirthDate()[i];
				digitCounter++;
			}
			// Затем месяц
			for (int i = Student::BirthDateLength - 8; i < Student::BirthDateLength - 6; i++)
			{
				birthDate1[digitCounter] = s1.GetBirthDate()[i];
				birthDate2[digitCounter] = s2.GetBirthDate()[i];
				digitCounter++;
			}
			// Затем день
			for (int i = 0; i < Student::BirthDateLength - 9; i++)
			{
				birthDate1[digitCounter] = s1.GetBirthDate()[i];
				birthDate2[digitCounter] = s2.GetBirthDate()[i];
				digitCounter++;
			}

			// Конвертируем строки YYYYMMDD в числа YYYYMMDD и сравниваем
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