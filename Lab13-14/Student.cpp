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
	std::cout << "Введите ФИО студента в формате: <Фамилия> <Инициалы>. "
		<< "Максимально возможная длина: " << Student::FullNameLength - 1 << "\n";
	std::cin.getline(fullName, Student::FullNameLength);
	
	char birthDate[Student::BirthDateLength];
	std::cout << "Введите дату рождения студента в формате: ДД.ММ.ГГГГ: \n";
	std::cin.getline(birthDate, Student::BirthDateLength);

	int performance;
	std::cout << "Введите успеваемость студента в формате оценки от 2 до 5: \n";
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
	std::cout << "ФИО: " << fullName
			  << "\nДата рождения: " << birthDate
		      << "\nУспеваемость: " << (int)performance << std::endl;
}