#pragma once
#include "Performance.h"
class Student
{
public:
	/// <summary>
	/// ������������ ����� ������� �����.
	/// </summary>
	static const size_t FullNameLength = 20;

	/// <summary>
	/// ������������ ����� ���� ��������.
	/// </summary>
	static const size_t BirthDateLength = 11;
private:

	/// <summary>
	/// ������� � ��������.
	/// </summary>
	char fullName[FullNameLength];

	/// <summary>
	/// ���� �������� (DD.MM.YYYY).
	/// </summary>
	char birthDate[BirthDateLength];
	
	/// <summary>
	/// ������������.
	/// </summary>
	Performance performance;
public:
	Student(char* fullName, char* birthDate, Performance performance);

	/// <summary>
	/// ������� ������ �������� � ������� ����������� �����.
	/// </summary>
	static Student CreateFromUserInput();

	/// <summary>
	/// �������� ��� ��������.
	/// </summary>
	char* GetFullName();

	/// <summary>
	/// �������� ���� �������� ��������.
	/// </summary>
	char* GetBirthDate();

	/// <summary>
	/// �������� ������������ ��������.
	/// </summary>
	Performance GetPerformance();

	/// <summary>
	/// ����� ���������� � �������.
	/// </summary>
	void PrintInfo();
};

