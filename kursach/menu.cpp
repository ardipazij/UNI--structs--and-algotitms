#include "menu.h"
#include <limits>
void Menu::print_info(){
	std::cout << "1 - добавить новое депо." << std::endl;
	std::cout << "2 - добавить новый поезд." << std::endl;
	std::cout << "3 - удалить депо." << std::endl;
	std::cout << "4 - удалить поезд." << std::endl;
	std::cout << "5 - Поиск депо" << std::endl;
	std::cout << "6 - Поиск поезда" << std::endl;
    std::cout << "7 - Вывод информации о состоянии железной дороги на экарн" << std::endl;
    std::cout << "8 - изменить имя железной дороги." << std::endl;
	std::cout << "9 - выгрузить содержимое железной дороги в файл." << std::endl;  ///
	std::cout << "10 - загрузить содержимое железной дороги из файл." << std::endl;  ///
    std::cout << "0 - выйти из программы." << std::endl;
}

int Menu::getNumber()
{
	int number{};
	std::cin >> number;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return number;
}

std::string Menu::getString()
{
	std::string string{};
	std::getline(std::cin, string);
	return string;
}

void Menu::Railway_add(Railway& railway)
{
	std::cout << "\nВведите номер нового депо: ";
	int depot{ getNumber() };
	railway.pushDepot(depot);
}

void Menu::Depot_search( Railway railway)
{
	if (railway.IsRailwayEmpty())
	{
		std::cout << "\nВ железной дороге отсутствуют депо для поиска\n";
		return;
	}

	std::cout << "\nВведите номер депо\n: ";
	int depot{ getNumber() };
	bool found{ railway.findDepot(depot)};
	if (found)
		std::cout << "\nДепо " << depot << " было найдено\n";
	else
		std::cout << "\nДепо " << depot << " не было найдено\n";
}

void Menu::Console_output( Railway railway)
{
	std::cout << '\n';
	railway.printDepots();
}

void Menu::Delete_Depot(Railway& railway)
{
	if (railway.IsRailwayEmpty())
	{
		std::cout << "\nУ железной дороге нет депо для удаления\n";
		return;
	}
	railway.popDepot();
}

void Menu::Train_add(Railway& railway)
{
	if (railway.IsRailwayEmpty())
	{
		std::cout << "\nУ железной дороги нет депо для добавлени поездов\n";
		return;
	}

	std::cout << "\nВведите номер депо, в которое хотите добавить поезд\n ";
	int depot_number{ getNumber() };

	Railway_depot* currentDepot{ railway.GetRoot() };
	while (currentDepot != nullptr && currentDepot->GetDepot_number() != depot_number)
		currentDepot = currentDepot->GetPrev();

	if (currentDepot == nullptr)
	{
		std::cout << "\nЗаданное депо не было найдено" << '\n';
		return;
	}
    std::cout << "Введите регистрационный номер поезда " << '\n';
	int id{ getNumber() };
	std::cout << "Введите модель поезда "<< '\n';
	std::string model { getString() };


	currentDepot->AddTrain(model, id);
}
// /////////////////////////////////////////////////////////////////
// void Menu::handleAirplaneSearch(const Airline& airline)
// {
// 	if (airline.isAirportListEmpty())
// 	{
// 		std::cout << "\nthe airport list is empty\n";
// 		return;
// 	}

// 	std::cout << "enter the model of the airplane: ";
// 	std::string model{ getString() };
// 	Airport* current{ airline.getHead() };
// 	int numberOfFoundAirplanes{ 0 };
// 	while (current != nullptr)
// 	{
// 		if (current->findAirplane(model))
// 		{
// 			std::cout << "airplane " << model << " found in airport " << current->getName() << '\n';
// 			++numberOfFoundAirplanes;
// 		}

// 		current = current->getNext();
// 	}

// 	if (numberOfFoundAirplanes == 0)
// 		std::cout << "airplane " << model << " was not found\n";
// }

// void Menu::handleAirplaneRemoval(Airline& airline)
// {
// 	if (airline.isAirportListEmpty())
// 	{
// 		std::cout << "\nthe airport list is empty\n";
// 		return;
// 	}

// 	std::cout << "\nenter airplane name to remove: ";
// 	std::string model{ getString() };
// 	Airport* current{ airline.getHead() };
// 	while (current != nullptr)
// 	{
// 		if (current->removeAirplane(model))
// 			std::cout << "removed airplane " << model << " from airport "
// 				<< current->getName() << '\n';
// 		current = current->getNext();
// 	}
// }

// void Menu::handleAirlineClearing(Airline& airline)
// {
// 	airline.~Airline();
// 	std::cout << "\nenter the name for the new airline: ";
// 	std::string airlineName{ getString() };
// 	airline = Airline{ airlineName };
// }

// void Menu::handleAirlineNameChange(Airline& airline)
// {
// 	std::cout << "\nenter the name for the new airline: ";
// 	std::string airlineName{ getString() };
// 	airline.setName(airlineName);
// }
// void Menu::handleCommand(Railway& railway, int command)
// {
// 	switch (command)
// 	{
// 		case 1:
// 			Railway_add(railway);
// 			break;
// 		case 2:
// 			handleAirportSearch(airline);
// 			break;
// 		case 3:
// 			handleAirlinePrinting(airline);
// 			break;
// 		case 4:
// 			handleAirportRemoval(airline);
// 			break;
// 		case 5:
// 			handleAirplaneAddition(airline);
// 			break;
// 		case 6:
// 			handleAirplaneSearch(airline);
// 			break;
// 		case 7:
// 			handleAirplaneRemoval(airline);
// 			break;
// 		case 8:
// 			handleAirlineClearing(airline);
// 			break;
// 		case 9:
// 			handleAirlineNameChange(airline);
// 			break;
// 	}
// }