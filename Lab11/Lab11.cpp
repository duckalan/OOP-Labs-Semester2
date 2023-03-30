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

// Прочитать - вывести в консоль из файла
void ReadTableFromFile(DataBase& db);

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите требуемое количество маршрутов: ";
	int dbSize;
	cin >> dbSize;
	struct DataBase db(dbSize);
	db.Initialize();

	bool isTerminated = false;
	while (!isTerminated)
	{
		cout << "\nВыберите действие (введите значение):"
			 << "\n 0 - выход;"
			 << "\n 1 - вывод таблицы маршрутов;"
			 << "\n 2 - отсортировать маршуруты по номеру;"
			 << "\n 3 - поиск маршрута по номеру;"
			 << "\n 4 - сохранить таблицу в файл;"
			 << "\n 5 - прочитать таблицу из файла;\n";
		int userChoice;
		cin >> userChoice;

		switch (userChoice)
		{
		case 0:
			isTerminated = true;
			break;
		case 1:
			db.PrintMarshesTable();
			break;
		case 2:
			db.SortMarshesById();
			break;
		case 3:
			FindById(db);
			break;
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

	// Так как список отсортирован, можно применить 
	// бинарный поиск
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

void ReadTableFromFile(DataBase& db)
{
}
