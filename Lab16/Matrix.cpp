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
	std::cout << "������� ���������� ����� �������: ";
	std::cin >> _rowsCount;
	std::cout << "������� ���������� �������� �������: ";
	std::cin >> _colsCount;

	_rows = new float* [_rowsCount];
	for (size_t i = 0; i < _rowsCount; i++)
	{
		_rows[i] = new float[_colsCount];

		std::cout << "������� �������� " << i << " ������.\n";
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
		std::cerr << "��������� ������ ������ " << rowIndex
			<< "��������� �� ��������� ������� ��������"
			<< _rowsCount << "x" << _colsCount;
		std::abort();
	}

	// ������ ����� ������� � ����������� ����� �� 1 ������
	float** newRows = Create2DArray(_rowsCount - 1, _colsCount);

	// ����� ������� ����� ����� �������, �������
	// �� ����� ������� �������� ������
	size_t mi = 0;

	// ��������� ����� ������� ����� ��������, ����� ���������
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
	// ������� ������ �������
	Delete2DArray(_rows, _rowsCount);

	_rows = newRows;
	_rowsCount--;
}

void Matrix::DeleteCol(size_t colIndex)
{
	if (colIndex >= _colsCount)
	{
		std::cerr << "��������� ������ ������� " << colIndex
			<< "��������� �� ��������� ������� ��������"
			<< _rowsCount << "x" << _colsCount;
		std::abort();
	}

	// ������ ����� ������� � ����������� �������� �� 1 ������
	float** newRows = Create2DArray(_rowsCount, _colsCount - 1);

	// ��������� ����� ������� ����� ���������, ����� ����������
	for (size_t i = 0; i < _rowsCount; i++)
	{
		// ����� ������� �������� ����� �������, �������
		// �� ����� ������� �������� �������
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
	// ������� ������ �������
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
	// �������� ������� �����
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

	// �������� ������� ��������
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