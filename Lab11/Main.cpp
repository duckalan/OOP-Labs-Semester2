#include <iostream>
#include "Marsh.h"
#include "DataBase.h"
using std::cout;
using std::cin;
using std::endl;

/*
В лабораторной №10
Описать структуру с именем MARSH, содержащую следующие поля:
– название начального пункта маршрута;
– название конечного пункта маршрута;
– номер маршрута.
Написать программу, выполняющую следующие действия:
– ввод с клавиатуры данных в массив, состоящий из восьми
элементов типа MARSH;
– вывод таблицы на экран;
– записи упорядочить по номерам маршрутов;
– вывод отсортированной таблицы на экран;
– вывод на экран информации о маршруте, номер которого
введен с клавиатуры;
– если таких маршрутов нет, выдать на дисплей
соответствующее сообщение.
*/

/*
В лабораторной №11
Доработать:
1. вызов запросов оформить в виде меню;
2. добавить пункты: сохранить таблицу в файл и прочитать
таблицу из файла.
Типы файлов:
- текстовый файл;
- двоичный файл, блочный ввод-вывод.
3. запросы оформить в виде подпрограмм.
*/

void FindById(DataBase& db);

int main()
{
	setlocale(LC_ALL, "Russian");
	struct DataBase db;

	bool isTerminated = false;
	while (!isTerminated)
	{
		cout << "\nВыберите действие (введите значение):"
			 << "\n  0 - выход;"
			 << "\n  1 - инициализировать маршруты;"
			 << "\n  2 - вывод таблицы маршрутов;"
			 << "\n  3 - отсортировать маршуруты по номеру;"
			 << "\n  4 - поиск маршрута по номеру;"
			 << "\n  5 - сохранить таблицу в текстовый файл;"
			 << "\n  6 - сохранить таблицу в бинарный файл;"
			 << "\n  7 - прочитать таблицу из текстового файла;"
			 << "\n  8 - прочитать таблицу из бинарного файла.\n";
		int userChoice;
		cin >> userChoice;

		switch (userChoice)
		{
		case 0:
			isTerminated = true;
			break;
		case 1:
			db.Initialize();
			break;
		case 2:
			db.PrintMarshesTable();
			break;
		case 3:
			db.SortMarshesById();
			break;
		case 4:
			FindById(db);
			break;
		case 5:
		{
			char filePath[255]{ "F:\\test.txt" };
			//std::cin >> filePath;
			db.WriteTableIntoTextFile(filePath);
			break;
		}
		case 6:
		{
			char filePath[255]{ "F:\\test.bin" };
			//std::cin >> filePath;
			db.WriteTableIntoBinaryFile(filePath);
			break;
		}
		case 7:
		{
			char filePath[255]{ "F:\\test.txt" };
			//std::cin >> filePath;
			db.ReadTableFromTextFile(filePath);
			break;
		}
		case 8:
		{
			char filePath[255]{ "F:\\test.bin" };
			//std::cin >> filePath;
			db.ReadTableFromBinaryFile(filePath);
			break;
		}
		default:
			isTerminated = true;
		}
	}
	system("pause");
}

void FindById(DataBase& db) {
	cout << "\nВведите номер маршрута для поиска" << endl;
	int toFind;
	cin >> toFind;

	Marsh found = db.SearchById(toFind);

	if (found.id >= 0)
	{
		found.PrintInfo();
	}
	else
	{
		cout << "Маршрут с номером " << toFind << " не найден" << endl;
	}
}