#pragma once
#include "Performance.h"
class Student
{
public:
	/// <summary>
	/// Максимальная длина полного имени.
	/// </summary>
	static const size_t FullNameLength = 20;

	/// <summary>
	/// Максимальная длина даты рождения.
	/// </summary>
	static const size_t BirthDateLength = 11;
private:

	/// <summary>
	/// Фамилия и инициалы.
	/// </summary>
	char fullName[FullNameLength];

	/// <summary>
	/// Дата рождения (DD.MM.YYYY).
	/// </summary>
	char birthDate[BirthDateLength];
	
	/// <summary>
	/// Успеваемость.
	/// </summary>
	Performance performance;
public:
	Student(char* fullName, char* birthDate, Performance performance);

	/// <summary>
	/// Создать объект студента с помощью консольного ввода.
	/// </summary>
	static Student CreateFromUserInput();

	/// <summary>
	/// Получить ФИО студента.
	/// </summary>
	char* GetFullName();

	/// <summary>
	/// Получить дату рождения студента.
	/// </summary>
	char* GetBirthDate();

	/// <summary>
	/// Получить успеваемость студента.
	/// </summary>
	Performance GetPerformance();

	/// <summary>
	/// Вывод информации в консоль.
	/// </summary>
	void PrintInfo();
};

