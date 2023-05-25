#include <iostream>
#include "Matrix.h"

int main()
{
    setlocale(LC_ALL, "ru-RU");

    size_t rowsCount;
    size_t colsCount;
    std::cout << "Введите количество строк матрицы: ";
    std::cin >> rowsCount;

    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> colsCount;


    Matrix mat(rowsCount, colsCount);
    std::cout << "Исходная матрица\n";
    mat.Print();

    std::cout << "Максимальный элемент на побочной диагонали: "
        << mat.GetMaxElementOnMinorDiagonal() << " \n";

    long long index = mat.GetFirstRowIndexWithPositiveElement();
    if (index >= 0)
    {
        std::cout << "Индекс первой строки, содержащей хотя бы"
            << " один положительный элемент: " << index << '\n';
    }
    else
    {
        std::cout << "Матрица не содержит ни одного положительного "
            << "элемента\n";
    }

    

    mat.DeleteZeroRowsAndCols();
    std::cout << "\nМатрица без нулевых строк и столбцов\n";
    mat.Print();
        
    system("pause");
}