﻿#include <iostream>
#include "Matrix.h"

int main()
{
    setlocale(LC_ALL, "ru-RU");

    Matrix mat;
    std::cout << "Исходная матрица\n";
    mat.Print();

    mat.DeleteZeroRowsAndCols();
    std::cout << "Матрица без нулевых строк и столбцов\n";
    mat.Print();
    
    long long index = mat.GetFirstRowIndexWithPositiveElement();
    if (index >= 0)
    {
        std::cout << "Индекс первой строки, содержащей хотя бы"
                  << " один положительный элемент: " << index;
    }
    else
    {
        std::cout << "Матрица не содержит ни одного положительного"
                  << "элемента";
    }
    std::cout << std::endl;
        
    system("pause");
}