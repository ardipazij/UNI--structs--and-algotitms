ы#include "hash_table.h"

int main() {
	setlocale(LC_ALL, "rus");
	menu();
	return 0;
}

void menu() {
	HashTable table{};
	int choice{}, n_comps{};
	std::pair<int, int> find_ind{};
	std::string str{};
	init_table(table);
	while (true) {
		// std::cout << table.arr[0] << std::endl;
		std::cout << "Выберите пункт меню:" << std::endl;
		std::cout << "0 - выйти из программы" << std::endl;
		std::cout << "1 - найти ключ в таблице" << std::endl;
		std::cout << "2 - вставить ключ" << std::endl;
		// std::cout << "3 - удалить ключ" << std::endl;
		std::cout << "3 - вывести таблицу" << std::endl;
		std::cout << "4 - заполнить таблицу" << std::endl;
		// std::cout << "6 - изменить размер текущей таблицы" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 0:
			return;
			break;
		case 1:
			std::cout << "Введите ключ, который хотите найти" << std::endl;
			std::cin >> str;
			find_ind = find(table, str);
			if (find_ind.first == -1) {
				std::cout << "Ключ не найден в таблице" << std::endl;
			}
			else {
				std::cout << "Ключ найден под индексом: " << find_ind.first <<  std::endl;
			}
			std::cout << "Число сравнений после поиска: " << find_ind.second << std::endl;
			break;
		case 2:
			std::cout << "Введите ключ, который хотите вставить в таблицу" << std::endl;
			std::cin >> str;
			n_comps = add_value(table, str);
			if (n_comps != -1)
				std::cout << "Количество произведенных сравнений: " << n_comps << std::endl;
			break;
		case 6:
			std::cout << "Введите ключ, который хотите удалить из таблицы" << std::endl;
			std::cin >> str;
			// remove(table, str);
			break;
		case 3:
			output_hash_table(table);
			break;
		case 4:
			fill_table(table);
			break;
		}
	}
}