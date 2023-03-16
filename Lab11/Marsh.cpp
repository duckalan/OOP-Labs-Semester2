#include <iostream>
#include "Marsh.h"

void Marsh::PrintInfo()
{
	std::cout << "Номер маршрута: " << id << std::endl;
	std::cout << "Начальный пункт: " << startName << std::endl;
	std::cout << "Конечный пункт: " << endName << std::endl;
}