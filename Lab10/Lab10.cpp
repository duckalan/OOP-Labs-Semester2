#include <iostream>
#include <iomanip>
#include "Marsh.h"
using std::cout;
using std::cin;
using std::endl;
using std::setw;

/*
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

void PrintMarshesTable(Marsh* marshes, int dbSize);

void PrintMarshInfo(Marsh marsh);

void SortMarshesById(Marsh* marshes, int dbSize);

int BinaryIdSearch(int toFind, Marsh* marshes, int dbSize);

int main()
{
    setlocale(LC_ALL, "Russian");

    const int dbSize = 8;
    struct Marsh marshes[dbSize]{};

    for (int i = 0; i < dbSize; i++)
    {
        cout << "\nМаршрут " << i << endl;
        cout << "Введите название начального пункта маршрута:\n";
        cin >> marshes[i].startName;

        cout << "Введите название конечного пункта маршрута:\n";
        cin >> marshes[i].endName;

        cout << "Введите номер маршрута: ";
        cin >> marshes[i].id;
    }

    cout << "\nДо сортировки" << endl;
    PrintMarshesTable(marshes, dbSize);

    // Сортировка по номеру маршрута
    SortMarshesById(marshes, dbSize);

    cout << "\nПосле сортировки" << endl;
    PrintMarshesTable(marshes, dbSize);

    cout << "\nВведите номер маршрута для поиска" << endl;
    int toFind;
    cin >> toFind;

    // Так как список отсортирован, можно применить 
    // бинарный поиск
    int found = BinaryIdSearch(toFind, marshes, dbSize);

    if (found >= 0)
    {
        PrintMarshInfo(marshes[found]);
    }
    else
    {
        cout << "Маршрут с номером " << toFind << " не найден" << endl;
    }
    
    system("pause");
}

void PrintMarshesTable(Marsh* marshes, int dbSize)
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

    for (int i = 0; i < dbSize; i++)
    {
        cout << "|"
            << setw(width) << marshes[i].id << "|"
            << setw(width) << marshes[i].startName << "|"
            << setw(width) << marshes[i].endName << "|"
            << endl;

        cout << horizontalLine << endl;
    }
}

void PrintMarshInfo(Marsh marsh)
{
    cout << "Начальный пункт: " << marsh.startName << endl;
    cout << "Конечный пункт: " << marsh.endName << endl;
}

void SortMarshesById(Marsh* marshes, int dbSize) 
{
    for (int i = 0; i < dbSize - 1; i++)
    {
        for (int j = 0; j < dbSize - i - 1; j++)
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

int BinaryIdSearch(int toFind, Marsh* marshes, int dbSize) 
{
    int leftIndex = 0;
    int rightIndex = dbSize;
    int midIndex = 0;

    while (leftIndex <= rightIndex)
    {
        midIndex = (leftIndex + rightIndex) / 2;

        if (toFind < marshes[midIndex].id)
        {
            rightIndex = midIndex - 1;
        }
        else if (toFind > marshes[midIndex].id)
        {
            leftIndex = midIndex + 1;
        }
        else return midIndex;
    }

    // Маршрут не найден. Предполагается, что
    // маршрутов с отрицательным номером не будет
    return -1;
}