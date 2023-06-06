#include "menu.h"
#include <limits>
#include <fstream>
#include <filesystem>
#include "file.h"
using namespace std;

void Menu::print_info(){
	std::cout << "1 - добавить новое депо." << std::endl;
	std::cout << "2 - добавить новый поезд." << std::endl;
	std::cout << "3 - удалить депо." << std::endl;
	std::cout << "4 - удалить поезд." << std::endl;
	std::cout << "5 - Поиск депо" << std::endl;
	std::cout << "6 - Поиск поезда" << std::endl;
    std::cout << "7 - Вывод информации о состоянии железной дороги на экарн" << std::endl;
    std::cout << "8 - изменить имя железной дороги." << std::endl;
	std::cout << "9 - выгрузить содержимое железной дороги в файл." << std::endl; 
	std::cout << "10 - загрузить содержимое железной дороги из файл." << std::endl; 
    std::cout << "11 - Удалить железную дорогу и создать новую" << std::endl; 
    std::cout << "-1 - выйти из программы." << std::endl;
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

void Menu::Console_output(const Railway& railway)
{   
    std::cout << railway.GetName();
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

void Menu::Train_search(Railway& railway)
{
	if (railway.IsRailwayEmpty())
	{
		std::cout << "\nУ железнодорожной дороги отстутствуют депо для поиска\n";
		return;
	}

	std::cout << "Введите регистрационный номер поезда";
	int train_id{ getNumber()};
	Railway_depot* current{ railway.GetRoot() };
	int numberOfFoundTrains{ 0 };
	while (current != nullptr)
	{
		if (current->FindTrain(train_id))
		{
			std::cout << "Поезд с регистрационным номером " << train_id << " найден в депо номер " << current->GetDepot_number() << '\n';
			++numberOfFoundTrains;
		}

		current = current->GetPrev();
	}

	if (numberOfFoundTrains == 0)
		std::cout << "Поезд с регистрационным номером " << train_id << " не найден\n";
}

void Menu::Train_delete(Railway& railway)
{
	if (railway.IsRailwayEmpty())
	{
		std::cout << "\nУ железной дороги отсутствуют депо для удаления\n";
		return;
	}

	std::cout << "\n Введите регистрационный номер поезда для удаления " << '\n';
	int id{ getNumber() };
	Railway_depot * current{ railway.GetRoot() };
	while (current != nullptr)
	{
		if (current->FindTrain(id) != -1){
            current->RemoveTrain(id);
			std::cout << "поезд с регистрационным номером" << id << "удален из депо номер "
				<< current->GetDepot_number() << '\n';
        }
		current = current->GetPrev();
        std::cout << "следущий курент"<< std::endl;
	}
}

void Menu::Railway_removing(Railway& railway)
{
	railway.~Railway();
	std::cout << "\nВведите название новой железной дороги\n ";
	std::string name{ getString() };
	railway = Railway{name};
}

void Menu::Railway_NameChange(Railway& railway)
{
	std::cout << "\n Введите новое название железной дороги " << '\n';
	std::string new_name{ getString() };
	railway.SetName(new_name);
}

void Menu::handleCommand(Railway& railway, int command)
{
    File file{};
	switch (command)
	{
		case 1:
			Railway_add(railway);
			break;
		case 2:
			Train_add(railway);
			break;
		case 3:
			Delete_Depot(railway);
			break;
		case 4:
			Train_delete(railway);
			break;
		case 5:
			Depot_search(railway);
			break;
		case 6:
			Train_search(railway);
			break;
		case 7:
			Console_output(railway);
			break;
		case 8:
			Railway_NameChange(railway);
			break;
        case 9:
            file.writeToFile(railway, "railway.txt");
            break;
		case 11:
			Railway_removing(railway);
			break;
	}
}

void Menu::runMenuLoop(){
    Railway railway{};
   int command{};
	while (command != -1)
	{
		print_info();
		command = getNumber();
		handleCommand(railway, command);
	}
}