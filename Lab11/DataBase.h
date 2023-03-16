#pragma once
// ���������, ���������� ������ �������� Marsh � ����� ����� �������.
// ��� ��� ������� ��������� ������ � ��������� (marshes* marshes, int size)
struct DataBase
{
	Marsh* marshes;
	int size;

	DataBase(int dbSize);
	~DataBase();

	// ������������� ������� �������� �������������
	void Initialize();

	// ���������� ��������� �� ������
	void SortMarshesById();
	
	// ����� ������� ���������
	void PrintMarshesTable();

	// ����� �������� �� ������
	Marsh SearchById(int toFind);

	// ������ ������� � ��������� ����
	void WriteTableIntoTextFile(const char* fileName);

	// ������ ������� � �������� ����
	void WriteTableIntoBinaryFile(const char* fileName);

	// ������ ������� �� ���������� �����
	void ReadTableFromTextFile(const char* fileName);

	// ������ ������� �� ��������� �����
	void ReadTableFromBinaryFile(const char* fileName);
};

