#include "ExtHash.h"

int main() {
	setlocale(LC_ALL, "rus");
	menu();
	return 0;
}

void menu() {
	HashTable table;
	int ch = 0;
	std::string str;
	while (true) {
		std::cout << "Хеш-таблица с использованием метода внешнего хеширования создана\n";
		std::cout << "Выберите пункт меню: \n";
		std::cout << "1. Заполнить таблицу. \n";
		std::cout << "2. Вывести таблицу. \n";
		std::cout << "3. Добавить ключ. \n";
		std::cout << "4. Удалить ключ. \n";
		std::cout << "5. Найти заданный ключ в таблице. \n";
		std::cout << "0. Завершить работу программы. \n";

		ch = input_for_menu(1);

		if (ch == 1) {
			buildTable(&table);
		}
		if (ch == 2) {
			if (isEmpty(table)) {
				printArray(table);
			}
			else {
				std::cout << "Таблица пустая. \n";
			}
		}
		if (ch == 3) {
			int c = 0;
			if (!isFull(table)) {
				std::cout << "Введите ключ, который хотите добавить: \n";
				std::cin >> str;
				addValue(&table, str, &c);
				std::cout << "Кол-во выполненных сравнений при добавлении: " << c << "\n";
			}
			else std::cout << "Таблица заполнена. \n";
		}
		if (ch == 4) {
			std::cout << "Введите ключ, который хотите удалить из таблицы: \n";
			std::cin >> str;
			remove(&table, str);
		}
		if (ch == 5) {
			int c = 0;
			std::cout << "Введите ключ, который хотите найти: \n";
			std::cin >> str;
			if (find(table, str, &c) == -1) {
				std::cout << "Ключ не найден. \n";
			}
			std::cout << "Кол-во выполненных сравнений при поиске: " << c << "\n";
		}
		if (ch == 0) {
			break;
		}
	}
}

int input_for_menu(int stat) {
	int choise;
	while (!(std::cin >> choise))
	{
		std::cin.clear();
		while (std::cin.get() != '\n') {
			std::cout << "Повторите ввод : \n";
		}
	}
	if (stat == 1 && (choise > 5 || choise < 0)) {
		std::cout << "Повторите ввод : \n";
		choise = input_for_menu(1);
	}
	if (stat == 2 && choise != 1 && choise != 0) {
		std::cout << "Повторите ввод : \n";
		choise = input_for_menu(2);
	}
	if (stat == 3 && (choise <= 0 || choise > 10000)) {
		std::cout << "Повторите ввод : \n";
		choise = input_for_menu(3);
	}
	return choise;
}