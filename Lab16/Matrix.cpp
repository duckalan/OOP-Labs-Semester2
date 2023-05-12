#include "Matrix.h"
#include <iostream>
#include <cassert>

float** Matrix::Create2DArray(size_t rowsCount, size_t colsCount)
{
	float** rows = new float*[_rowsCount];
	for (size_t i = 0; i < _rowsCount; i++)
	{
		rows[i] = new float[_colsCount];
	}
	return rows;
}

void Matrix::Delete2DArray(float** arr, size_t rowsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

Matrix::Matrix()
{
	std::cout << "Введите количество строк матрицы: ";
	std::cin >> _rowsCount;
	std::cout << "Введите количество столбцов матрицы: ";
	std::cin >> _colsCount;

	_rows = new float* [_rowsCount];
	for (size_t i = 0; i < _rowsCount; i++)
	{
		_rows[i] = new float[_colsCount];

		std::cout << "Введите элементы " << i << " строки.\n";
		for (size_t j = 0; j < _colsCount; j++)
		{
			std::cin >> _rows[i][j];
		}
		std::cout << '\n';
	}
}

Matrix::~Matrix()
{
	Delete2DArray(_rows, _rowsCount);
}

void Matrix::DeleteRow(size_t rowIndex)
{
	if (rowIndex >= _rowsCount)
	{
		std::cerr << "Указанный индекс строки " << rowIndex
			<< "находится за пределами матрицы размером"
			<< _rowsCount << "x" << _colsCount;
		std::abort();
	}

	// Создаём новую матрицу с количеством строк на 1 меньше
	float** newRows = Create2DArray(_rowsCount - 1, _colsCount);

	// Нужен счётчик строк новой матрицы, который
	// не будет считать удалённую строку
	size_t mi = 0;

	// Заполняем новую матрицу всеми строками, кроме удаляемой
	for (size_t i = 0; i < _rowsCount; i++)
	{
		if (i != rowIndex)
		{
			for (size_t j = 0; j < _colsCount; j++)
			{
				newRows[mi][j] = _rows[i][j];
			}
			mi++;
		}
	}
	// Удаляем старую матрицу
	Delete2DArray(_rows, _rowsCount);

	_rows = newRows;
	_rowsCount--;
}

void Matrix::DeleteCol(size_t colIndex)
{
	if (colIndex >= _colsCount)
	{
		std::cerr << "Указанный индекс столбца " << colIndex
			<< "находится за пределами матрицы размером"
			<< _rowsCount << "x" << _colsCount;
		std::abort();
	}

	// Создаём новую матрицу с количеством столбцов на 1 меньше
	float** newRows = Create2DArray(_rowsCount, _colsCount - 1);

	// Заполняем новую матрицу всеми столбцами, кроме удаляемого
	for (size_t i = 0; i < _rowsCount; i++)
	{
		// Нужен счётчик столбцов новой матрицы, который
		// не будет считать удалённый столбец
		size_t mj = 0;
		for (size_t j = 0; j < _colsCount; j++)
		{
			if (j != colIndex)
			{
				newRows[i][mj] = _rows[i][j];
				mj++;
			}
		}
	}
	// Удаляем старую матрицу
	Delete2DArray(_rows, _rowsCount);

	_rows = newRows;
	_colsCount--;
}

void Matrix::Print()
{
	for (size_t i = 0; i < _rowsCount; i++)
	{
		for (size_t j = 0; j < _colsCount; j++)
		{
			std::cout << _rows[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void Matrix::DeleteZeroRowsAndCols()
{
	// Удаление нулевых строк
	for (size_t i = 0; i < _rowsCount; i++)
	{
		bool isZeroRow = true;

		for (size_t j = 0; j < _colsCount; j++)
		{
			if (_rows[i][j] != 0)
			{
				isZeroRow = false;
				break;
			}
		}
		if (isZeroRow)
		{
			DeleteRow(i);
		}
	}

	// Удаление нулевых столбцов
	for (size_t i = 0; i < _colsCount; i++)
	{
		bool isZeroCol = true;
		for (size_t j = 0; j < _rowsCount; j++)
		{
			if (_rows[j][i] != 0)
			{
				isZeroCol = false;
			}
		}
		if (isZeroCol)
		{
			DeleteCol(i);
		}
	}
}

long long Matrix::GetFirstRowIndexWithPositiveElement()
{
	for (size_t i = 0; i < _rowsCount; i++)
	{
		for (size_t j = 0; j < _colsCount; j++)
		{
			if (_rows[i][j] > 0)
			{
				return i;
			}
		}
	}

	return -1;
}