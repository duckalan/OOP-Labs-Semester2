#include <iostream>
#include <iomanip>
#include "Marsh.h"
#include "DataBase.h"
using std::cout;
using std::cin;
using std::endl;
using std::setw;

DataBase::DataBase(int dbSize)
{
	marshes = new Marsh[dbSize];
	size = dbSize;
}
DataBase::~DataBase() {
	delete[] marshes;
}

void DataBase::Initialize()
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nМаршрут " << i << endl;
		cout << "Введите название начального пункта маршрута:\n";
		cin >> marshes[i].startName;

		cout << "Введите название конечного пункта маршрута:\n";
		cin >> marshes[i].endName;

		cout << "Введите номер маршрута: ";
		cin >> marshes[i].id;
	}
}

void DataBase::SortMarshesById()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (marshes[j].id > marshes[j + 1].id)
			{
				struct Marsh temp = marshes[j];
				marshes[j] = marshes[j + 1];
				marshes[j + 1] = temp;
			}
		}
	}
}

void DataBase::PrintMarshesTable()
{
	const int width = 15;
	// 3 основных столбца + 4 символа '|' + '\0' 
	char horizontalLine[width * 3 + 5] =
	{
		"-------------------------------------------------"
	};
	// Выравнивание по левой границе
	cout.setf(std::ios::left);

	// Шапка
	cout << horizontalLine << endl;
	cout << "|"
		<< setw(width) << "Номер маршрута" << "|"
		<< setw(width) << "Начальный пункт" << "|"
		<< setw(width) << "Конечный пункт" << "|"
		<< endl;
	cout << horizontalLine << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "|"
			 << setw(width) << marshes[i].id << "|"
			 << setw(width) << marshes[i].startName << "|"
			 << setw(width) << marshes[i].endName << "|"
			 << endl;

		cout << horizontalLine << endl;
	}
}

Marsh DataBase::SearchById(int toFind)
{

	for (size_t i = 0; i < size; i++)
	{
		if (marshes[i].id == toFind)
		{
			return marshes[i];
		}
	}

	// Маршрут не найден. Предполагается, что
	// маршрутов с отрицательным номером не будет
	return Marsh { "Не найден", "Не найден", -1 };
}

void DataBase::WriteTableIntoTextFile(const char* fileName)
{
	FILE* f = fopen(fileName, "w");
	if (!f)
	{
		perror("Ошибка при открытии файла: ");
	}
	else
	{
		char horizontalLine[15 * 3 + 6] =
		{
			"-------------------------------------------------\n"
		};

		// Шапка
		fputs(horizontalLine, f);
		fprintf(f, "%s%-15s%s%-15s%s%-15s%s\n",
				"|", "Номер маршрута", 
				"|", "Начальный пункт",
				"|", "Конечный пункт", "|");
		fputs(horizontalLine, f);

		for (int i = 0; i < size; i++)
		{
			fprintf(f, "%s%-15d%s%-15s%s%-15s%s\n", 
					"|", marshes[i].id,
					"|", marshes[i].startName,
					"|", marshes[i].endName, "|");
			fputs(horizontalLine, f);
		}

		fclose(f);
	}
}

void DataBase::WriteTableIntoBinaryFile(const char* fileName)
{
	FILE* f = fopen(fileName, "wb");
	if (!f)
	{
		perror("Ошибка при открытии файла: ");
	}
	else 
	{
		// В файл будут записываться только данные маршрутов
		fwrite(marshes, sizeof(Marsh), size, f);
		fclose(f);
	}
}

void DataBase::ReadTableFromTextFile(const char* fileName)
{
	FILE* f = fopen(fileName, "r");
	if (!f)
	{
		perror("Ошибка при открытии файла: ");
	}
	else
	{
		while (!feof(f))
		{
			char buffer[255]{};
			fgets(buffer, 255, f);
			std::cout << buffer;
		}
		fclose(f);
	}
}

void DataBase::ReadTableFromBinaryFile(const char* fileName)
{
	FILE* f = fopen(fileName, "r");
	if (!f)
	{
		perror("Ошибка при открытии файла: ");
	}
	else
	{
		Marsh* readedMarshes = new Marsh[size];
		fread(readedMarshes, sizeof(Marsh), size, f);

		const int width = 15;

		char horizontalLine[width * 3 + 5] =
		{
			"-------------------------------------------------"
		};

		// Шапка
		cout << horizontalLine << endl;
		cout << "|"
			<< setw(width) << "Номер маршрута" << "|"
			<< setw(width) << "Начальный пункт" << "|"
			<< setw(width) << "Конечный пункт" << "|"
			<< endl;
		cout << horizontalLine << endl;

		for (int i = 0; i < size; i++)
		{
			cout << "|"
				 << setw(width) << readedMarshes[i].id << "|"
				 << setw(width) << readedMarshes[i].startName << "|"
				 << setw(width) << readedMarshes[i].endName << "|"
				 << endl;

			cout << horizontalLine << endl;
		}

		delete[] readedMarshes;
		fclose(f);
	}
}
