#pragma once

class Matrix
{
private:
	float** _rows = nullptr;
	size_t _rowsCount = 0;
	size_t _colsCount = 0;

	/// <summary>
	/// Создание пустого двухмерного массива float размером
	/// [<paramref name="rowsCount"/>; <paramref name="colsCount"/>].
	/// </summary>
	float** Create2DArray(size_t rowsCount, size_t colsCount);

	/// <summary>
	/// Удаление двухмерного массива float, состоящего 
	/// из <paramref name="rowsCount"/> строк.
	/// </summary>
	void Delete2DArray(float** arr, size_t rowsCount);

public:
	/// <summary>
	/// Создание матрицы из пользовательского ввода.
	/// </summary>
	Matrix();
	 
	/// <summary>
	/// Удаление всех выделенных ресурсов.
	/// </summary>
	~Matrix();

	/// <summary>
	/// Удаление строки с индексом <paramref name="rowIndex"/>.
	/// </summary>
	void DeleteRow(size_t rowIndex);

	/// <summary>
	/// Удаление столбца с индексом <paramref name="colIndex"/>.
	/// </summary>
	void DeleteCol(size_t colIndex);

	/// <summary>
	/// Вывод матрицы в консоль.
	/// </summary>
	void Print();

	/// <summary>
	/// Удалить все нулевые строки и столбцы.
	/// </summary>
	void DeleteZeroRowsAndCols();

	/// <returns>
	/// Индекс строки c хотя бы одним положительным элементом
	/// или -1, если такой строки нет.
	/// </returns>
	long long GetFirstRowIndexWithPositiveElement();
};

