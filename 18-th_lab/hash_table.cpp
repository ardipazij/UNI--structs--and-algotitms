#include "hash_table.h"

namespace words {
	std::string keys[MAX_SIZE]{
		"auto",
		"union",
		"constexpr",
		"volatile",
		"explicit",
		"friend",
		"inline",
		"virtual",
		"for",
		"template"
	};
}

int hash_func(const HashTable table, const std::string str) {
	int res{ 0 };
	for (const int& a : str) {
		res += a;
	}
	return res % table.size;
}

void init_table(HashTable &table) {
	int m{};
	std::cout << "Введите размер хэш-таблицы:" << std::endl;
	std::cin >> m;
	std::vector<std::string> arr(m);
	table.arr = arr;
	table.size = m;
	for (int i{ 0 }; i < m; i++) {
		table.arr[i] = "EMPTY";
	}
}

bool is_full(const HashTable &table) {
	for (int i{ 0 }; i < table.size; i++) {
		if (table.arr[i] == "EMPTY") return false;
	}
	return true;
}

int add_value(HashTable &table, const std::string str) {
	std::pair<int, int> find_p = find(table, str);
	int find_index = find_p.first;
	if (find_index != -1) {
		std::cout << "Ключ уже в таблице и найден под индексом:: " << find_index << std::endl;
		return -1;
	}
	if (is_full(table)) {
		std::cout << "Таблица переполнена, вставить новое значение невозможно" << std::endl;
		return -1;
	}
	int index{ hash_func(table, str) };
	int cur_index{ index };
	int i{ 1 };
	while (table.arr[cur_index] != "EMPTY") {
		cur_index = (index + i) % table.size;
		i++;
	}
	table.arr[cur_index] = str;
	table.count++;

	return i - 1 + find_p.second;
}

std::pair<int, int> find(const HashTable &table, const std::string str) {
	// int n_comps{ 0 };
	bool is_find = false;
	int index{ hash_func(table, str) };
	if (table.arr[index] == "EMPTY") {
		return { -1, 1 };
	}
	int n_comps{ 1 };
	int i{ 1 };
	int cur_index{ index };
	while (cur_index < table.size && i < table.size) {
		n_comps++;
		if (table.arr[cur_index] == str) {
			is_find = true;
			break;
		}
		else {
			n_comps++;
			if (table.arr[cur_index] == "EMPTY")
				return { -1, i };
		}
		cur_index = (index + i) % table.size;
		i++;
	}
	// std::cout << "����� ��������� ����� ������: " << i << std::endl;
	return {is_find ? cur_index : -1, n_comps};
}

/*
void remove(HashTable& table, const std::string str) {
	std::pair<int, int> find_p = find(table, str);
	int find_index = find_p.first;
	if (find_index != -1) {
		std::cout << "�������� ������� ��� ��������: " << find_index << std::endl;
		table.arr[find_index] = "EMPTY";
		table.count--;
		return;
	}
	else {
		std::cout << "�������� �� ������� � �������" << std::endl;
	}
	table.count--;
	// int index{ hash_func(table, str) };
}
*/

void fill_table(HashTable& table) {
	int n_comps{ 0 };
	for (int i{ 0 }; i < 10; i++) {
		int add_comps{ add_value(table, words::keys[i]) };
		if (add_comps != -1)
			n_comps += add_comps;
	}

	std::cout << "Число сравнений после заполнения таблицы: " << n_comps << std::endl;
}

void resize_table(HashTable &table) {
	int m{};
	std::cout << "Введите новую размерность таблицы: " << std::endl;
	std::cin >> m;
	table.arr.resize(m);
}

void output_hash_table(const HashTable &table) {
	for (int i{ 0 }; i < table.size; i++) {
		std::cout << i << ") " << table.arr[i] << std::endl;
	}
}