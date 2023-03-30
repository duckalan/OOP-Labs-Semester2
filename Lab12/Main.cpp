#include <iostream>
#include "List.h"

/*
������������ ������ List1 � List2 �� ������ List �� ����������
�������: � List1 ��������� ������ ������������� �������� ������ List, �
List2 � �������� ������������� �������� ������ List. ����������
���������� ����������� � ������� List1 � List2.
*/

int main() 
{
	setlocale(LC_ALL, "Russian");
	size_t elementCount;
	std::cout << "������� ���������� ��������� � ������ List: ";
	std::cin >> elementCount;

	List list(elementCount);
	std::cout << "\n�������������� List: \n";
	list.Print();

	List list1 = list.CreateEvenPositiveList();
	std::cout << "\n��������� List1: \n";
	list1.Print();
	std::cout << "��� �����: " << list1.length << " ���������\n";

	List list2 = list.CreateOddNegativeList();
	std::cout << "\n��������� List2: \n";
	list2.Print();
	std::cout << "��� �����: " << list2.length << " ���������\n";

	system("pause");
}