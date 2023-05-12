#pragma once

class Matrix
{
private:
	float** _rows = nullptr;
	size_t _rowsCount = 0;
	size_t _colsCount = 0;

	/// <summary>
	/// �������� ������� ����������� ������� float ��������
	/// [<paramref name="rowsCount"/>; <paramref name="colsCount"/>].
	/// </summary>
	float** Create2DArray(size_t rowsCount, size_t colsCount);

	/// <summary>
	/// �������� ����������� ������� float, ���������� 
	/// �� <paramref name="rowsCount"/> �����.
	/// </summary>
	void Delete2DArray(float** arr, size_t rowsCount);

public:
	/// <summary>
	/// �������� ������� �� ����������������� �����.
	/// </summary>
	Matrix();
	 
	/// <summary>
	/// �������� ���� ���������� ��������.
	/// </summary>
	~Matrix();

	/// <summary>
	/// �������� ������ � �������� <paramref name="rowIndex"/>.
	/// </summary>
	void DeleteRow(size_t rowIndex);

	/// <summary>
	/// �������� ������� � �������� <paramref name="colIndex"/>.
	/// </summary>
	void DeleteCol(size_t colIndex);

	/// <summary>
	/// ����� ������� � �������.
	/// </summary>
	void Print();

	/// <summary>
	/// ������� ��� ������� ������ � �������.
	/// </summary>
	void DeleteZeroRowsAndCols();

	/// <returns>
	/// ������ ������ c ���� �� ����� ������������� ���������
	/// ��� -1, ���� ����� ������ ���.
	/// </returns>
	long long GetFirstRowIndexWithPositiveElement();
};

