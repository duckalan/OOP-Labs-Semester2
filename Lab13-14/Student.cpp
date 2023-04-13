#include <string.h>
#include <iostream>
#include <iomanip>
#include "Student.h"

Student::Student(char* fullName, char* birthDate, Performance performance)
{
	strcpy_s(this->fullName, fullName);
	strcpy_s(this->birthDate, birthDate);
	this->performance = performance;
}

Student Student::CreateFromUserInput()
{
	std::cin.get();
	char fullName[Student::FullNameLength];
	std::cout << "������� ��� �������� � �������: <�������> <��������>. "
		<< "����������� ��������� �����: " << Student::FullNameLength - 1 << "\n";
	std::cin.getline(fullName, Student::FullNameLength);
	
	//std::cin.get();
	char birthDate[Student::BirthDateLength];
	std::cout << "������� ���� �������� �������� � �������: ��.��.����: \n";
	std::cin.getline(birthDate, Student::BirthDateLength);
	//std::cin.get();


	int performance;
	std::cout << "������� ������������ �������� � ������� ������ �� 2 �� 5: \n";
	std::cin >> performance;

	return Student(fullName, birthDate, (Performance)performance);
}

char* Student::GetFullName()
{
	return fullName;
}

char* Student::GetBirthDate()
{
	return birthDate;
}

Performance Student::GetPerformance()
{
	return performance;
}

void Student::PrintInfo()
{
	std::cout << "���: " << fullName
			  << "\n���� ��������: " << birthDate
		      << "\n������������: " << (int)performance << std::endl;
}