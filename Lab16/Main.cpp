#include <iostream>
#include "Matrix.h"

int main()
{
    setlocale(LC_ALL, "ru-RU");

    Matrix mat;
    std::cout << "�������� �������\n";
    mat.Print();

    mat.DeleteZeroRowsAndCols();
    std::cout << "������� ��� ������� ����� � ��������\n";
    mat.Print();
    
    long long index = mat.GetFirstRowIndexWithPositiveElement();
    if (index >= 0)
    {
        std::cout << "������ ������ ������, ���������� ���� ��"
                  << " ���� ������������� �������: " << index;
    }
    else
    {
        std::cout << "������� �� �������� �� ������ ��������������"
                  << "��������";
    }
    std::cout << std::endl;
        
    system("pause");
}