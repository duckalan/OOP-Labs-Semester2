#include <iostream>
#include <iomanip>
#include "Marsh.h"
using std::cout;
using std::cin;
using std::endl;
using std::setw;

/*
������� ��������� � ������ MARSH, ���������� ��������� ����:
    � �������� ���������� ������ ��������;
    � �������� ��������� ������ ��������;
    � ����� ��������.
�������� ���������, ����������� ��������� ��������:
    � ���� � ���������� ������ � ������, ��������� �� ������
    ��������� ���� MARSH;
    � ����� ������� �� �����;
    � ������ ����������� �� ������� ���������;
    � ����� ��������������� ������� �� �����;
    � ����� �� ����� ���������� � ��������, ����� ��������
������ � ����������;
    � ���� ����� ��������� ���, ������ �� �������
��������������� ���������.
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
        cout << "\n������� " << i << endl;
        cout << "������� �������� ���������� ������ ��������:\n";
        cin >> marshes[i].startName;

        cout << "������� �������� ��������� ������ ��������:\n";
        cin >> marshes[i].endName;

        cout << "������� ����� ��������: ";
        cin >> marshes[i].id;
    }

    cout << "\n�� ����������" << endl;
    PrintMarshesTable(marshes, dbSize);

    // ���������� �� ������ ��������
    SortMarshesById(marshes, dbSize);

    cout << "\n����� ����������" << endl;
    PrintMarshesTable(marshes, dbSize);

    cout << "\n������� ����� �������� ��� ������" << endl;
    int toFind;
    cin >> toFind;

    // ��� ��� ������ ������������, ����� ��������� 
    // �������� �����
    int found = BinaryIdSearch(toFind, marshes, dbSize);

    if (found >= 0)
    {
        PrintMarshInfo(marshes[found]);
    }
    else
    {
        cout << "������� � ������� " << toFind << " �� ������" << endl;
    }
    
    system("pause");
}

void PrintMarshesTable(Marsh* marshes, int dbSize)
{
    const int width = 15;
    // 3 �������� ������� + 4 ������� '|' + '\0' 
    char horizontalLine[width * 3 + 5] =
    {
        "-------------------------------------------------"
    };
    // ������������ �� ����� �������
    cout.setf(std::ios::left);

    // �����
    cout << horizontalLine << endl;
    cout << "|"
        << setw(width) << "����� ��������" << "|"
        << setw(width) << "��������� �����" << "|"
        << setw(width) << "�������� �����" << "|"
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
    cout << "��������� �����: " << marsh.startName << endl;
    cout << "�������� �����: " << marsh.endName << endl;
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

    // ������� �� ������. ��������������, ���
    // ��������� � ������������� ������� �� �����
    return -1;
}