#pragma once
struct Marsh
{
	// Название начального пункта маршрута
	char startName[15];

	// Название конечного пункта маршрута
	char endName[15];

	// Номер маршрута
	int id;

	void PrintInfo();
};