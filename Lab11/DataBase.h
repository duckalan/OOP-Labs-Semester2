#pragma once
// Структура, содержащая массив структур Marsh и длину этого массива.
struct DataBase
{
	Marsh* marshes;

	// Длина массива структур
	int size;

	DataBase(int dbSize);
	~DataBase();

	// Инициализация массива структур пользователем
	void Initialize();

	// Сортировка маршрутов по номеру
	void SortMarshesById();
	
	// Вывод таблицы маршрутов
	void PrintMarshesTable();

	// Поиск маршрута по номеру
	Marsh SearchById(int toFind);

	// Запись таблицы в текстовый файл
	void WriteTableIntoTextFile(const char* fileName);

	// Запись таблицы в бинарный файл
	void WriteTableIntoBinaryFile(const char* fileName);

	// Чтение таблицы из текстового файла
	void ReadTableFromTextFile(const char* fileName);

	// Чтение таблицы из бинарного файла
	void ReadTableFromBinaryFile(const char* fileName);
};

