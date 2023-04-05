#include <iostream>
#include "List.h"

/*
Сформировать списки List1 и List2 из списка List по следующему
правилу: в List1 поместить четные положительные элементы списка List, в
List2 – нечетные отрицательные элементы списка List. Подсчитать
количество компонентов в списках List1 и List2.
*/

int main() 
{
	setlocale(LC_ALL, "Russian");
	size_t elementCount;
	std::cout << "Введите количество элементов в списке List: ";
	std::cin >> elementCount;

	List list(elementCount);
	std::cout << "\nСформированный List: \n";
	list.Print();

	List list1 = list.CreateEvenPositiveList();
	std::cout << "\nСозданный List1: \n";
	list1.Print();
	std::cout << "Его длина: " << list1.length << " элементов\n";

	List list2 = list.CreateOddNegativeList();
	std::cout << "\nСозданный List2: \n";
	list2.Print();
	std::cout << "Его длина: " << list2.length << " элементов\n";

	system("pause");
}