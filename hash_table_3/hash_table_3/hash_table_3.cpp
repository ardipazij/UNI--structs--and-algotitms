#include "hash_table.h"

int main() {
	setlocale(LC_ALL, "rus");
	menu();
	return 0;
}

void menu() {
	HashTable table{};
	int choice{}, find_ind{};
	std::string str{};
	init_table(table);
	while (true) {
		std::cout << "Выберите пункт меню:" << std::endl;
		std::cout << "0 - выйти из программы" << std::endl;
		std::cout << "1 - найти ключ в таблице" << std::endl;
		std::cout << "2 - вставить ключ" << std::endl;
		std::cout << "3 - удалить ключ" << std::endl;
		std::cout << "4 - вывести таблицу" << std::endl;
		std::cout << "5 - заполнить таблицу" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 0:
			return;
			break;
		case 1:
			std::cout << "Введите ключ, который хотите найти" << std::endl;
			std::cin >> str;
			find_ind = find(table, str);
			if (find_ind == -1) {
				std::cout << "Ключ не найден в таблице" << std::endl;
			}
			std::cout << "Ключ найден под индексом: " << find_ind << std::endl;
			break;
		case 2:
			std::cout << "Введите ключ, который хотите вставить в таблицу" << std::endl;
			std::cin >> str;
			add_value(table, str);
			break;
		case 3:
			std::cout << "Введите ключ, который хотите удалить из таблицы" << std::endl;
			std::cin >> str;
			remove(table, str);
			break;
		case 4:
			output_hash_table(table);
			break;
		case 5:
			fill_table(table);
			break;
		}
	}
}