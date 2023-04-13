#pragma once
#include "Node.h"

/// <summary>
/// Односвязный список, элементами которого являются объекты 
/// класса Student (студенты).
/// </summary>
class LinkedList
{
private:
	/// <summary>
	/// Длина списка.
	/// </summary>
	size_t length;

	/// <summary>
	/// Головной элемент.
	/// </summary>
	Node* root;

	/// <summary>
	/// Получить элемент на позиции <paramref name="index"/>.
	/// </summary>
	/// <returns>Адрес узла на позиции <paramref name="index"/>.</returns>
	Node* GetNodeAt(size_t index);

	/// <summary>
	/// Перестановка местами двух элементов.
	/// </summary>
	void SwapNodes(Node* n1, Node* n2, size_t n1Index);

	/// <summary>
	/// Сортировка списка с использованием компаратора 
	/// <paramref name="comparer"/>
	/// </summary>
	/// <param name="comparer">Определяет условие сравнения для сортировки.</param>
	void SortBy(bool (*comparer)(Student s1, Student s2));

	/// <summary>
	/// Найти студентов по параметру <paramref name="toFind"/> с условием
	/// равенста <paramref name="equalCondition"/>.
	/// </summary>
	/// <param name="equalCondition"> 
	/// Определяет условие равенства какого-либо поля <paramref name="student"/> 
	/// и передаваемого значения <paramref name="value"/>.
	/// </param>
	/// <returns>Список с найденными студентами. 
	/// Если ни один студент не найден, пустой список.</returns>
	LinkedList FindBy(void* toFind, bool (*equalCondition) (Student student, void* value));
public:
	/// <summary>
	/// Создание пустого списка.
	/// </summary>
	LinkedList();

	/// <summary>
	/// Инициализация списка данными из текстового файла.
	/// </summary>
	void InitFromFile(const char* filePath);

	/// <summary>
	/// Вставить элемент <paramref name="student"/> на позицию
	/// <paramref name="index"/>
	/// </summary>
	void InsertAt(size_t index, Student student);

	/// <summary>
	/// Удалить элемент на позиции <paramref name="index"/>
	/// </summary>
	void DeleteAt(size_t index);

	/// <summary>
	/// Сортировка фамилий по алфавиту.
	/// </summary>
	void SortByFullName();

	/// <summary>
	/// Сортировка по дате рождения по возрастанию.
	/// </summary>
	void SortByBirthDate();

	/// <summary>
	/// Сортировка по успеваемости по убыванию.
	/// </summary>
	void SortByPerformance();

	/// <summary>
	/// Найти всех студентов с указанным ФИО.
	/// </summary>
	/// <param name="toFind">ФИО для поиска. Формат: Фамилия Инициалы</param>
	/// <returns>
	/// Список с найденными студентами. 
	/// Если ни один студент не найден, пустой список.
	/// </returns>
	LinkedList FindByFullName(const char* toFind);

	/// <summary>
	/// Найти всех студентов с указанной датой рождения.
	/// </summary>
	/// <param name="toFind">Дата рождения для поиска. Формат: DD.MM.YYYY</param>
	/// <returns>
	/// Список с найденными студентами. 
	/// Если ни один студент не найден, пустой список.
	/// </returns>
	LinkedList FindByBirthDate(const char* toFind);

	/// <summary>
	/// Найти всех студентов с указанной успеваемостью.
	/// </summary>
	/// <param name="toFind">Успеваемость для поиска.</param>
	/// <returns>
	/// Список с найденными студентами. 
	/// Если ни один студент не найден, пустой список.
	/// </returns>
	LinkedList FindByPerformance(Performance toFind);

	/// <summary>
	/// Вывод всего списка в консоль.
	/// </summary>
	void Print();

	/// <summary>
	/// Получить длину списка.
	/// </summary>
	size_t GetLength();
};