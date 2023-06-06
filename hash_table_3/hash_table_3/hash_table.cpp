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

void init_table(HashTable& table) {
	int m{};
	std::cout << "Введите размер хэш-таблицы:" << std::endl;
	std::cin >> m;
	std::vector<Element> arr(m);
	table.arr = arr;
	table.size = m;
	for (int i{ 0 }; i < m; i++) {
		table.arr[i].data = "EMPTY";
	}
}
int hash_func(const HashTable &table, const std::string str) {
	int res{ 0 };
	for (const int& a : str) {
		res += a;
	}
	return res % table.size;
}

int add_value(HashTable& table, const std::string str) {
	int n_comps{ 0 };
	int index{ hash_func(table, str) };
	n_comps++;
	if (table.arr[index].data == "EMPTY") {
		table.arr[index].data = str;
	}
	else {
		n_comps++;
		if (table.arr[index].head == nullptr) {
			table.arr[index].head = new Node;
			table.arr[index].head->data = str;
			table.arr[index].head->next = table.arr[index].tail;
			table.arr[index].tail = table.arr[index].head;
		}
		else {
			// Node* cur = table.arr[index].tail;
			table.arr[index].tail->next = new Node;
			table.arr[index].tail->next->data = str;
			table.arr[index].tail = table.arr[index].tail->next;
		}
	}
	return n_comps;
}

int find(const HashTable& table, const std::string str) {
	int index{ hash_func(table, str) };
	int n_comps{ 0 };
	n_comps++;
	if (str == table.arr[index].data) {
		// std::cout << "���� ������ ��� �������� " << index << std::endl;
		std::cout << "Число сравнений после поиска: " << 1 << std::endl;
		return index;
	}
	else {
		Node* cur{ table.arr[index].head };
		while (cur) {
			n_comps++;
			if (cur->data == str) {
				std::cout << "Число сравнений после поиска: " << n_comps << std::endl;
				return index;
			}
			cur = cur->next;
		}
	}
	std::cout << "Число сравнений после поиска: " << n_comps << std::endl;
	return -1;
}

void remove(HashTable& table, const std::string str) {
	if (find(table, str) == -1) {
		std::cout << "Ключ не найден в таблице" << std::endl;
		return;
	}
	int n_comps{ 0 };
	int index{ hash_func(table, str) };
	Node* cur{ table.arr[index].head };
	Node* prev{ table.arr[index].head };
	n_comps++;
	if (table.arr[index].data == str) {
		if (cur) {
			table.arr[index].data = cur->data;
			table.arr[index].head = table.arr[index].head->next;
			delete cur;
		}
		else {
			table.arr[index].data = "EMPTY";
		}
	}
	else {
		n_comps++;
		if (cur->data == str) {
			table.arr[index].head = table.arr[index].head->next;
			delete cur;
		}
		else {
			if (cur) cur = cur->next;
			n_comps++;
			while (cur && cur->data != str) {
				n_comps++;
				cur = cur->next;
				prev = prev->next;
			}
			if (!cur) return;
			prev->next = cur->next;
			delete cur;
		}
	}
	std::cout << "Число сравнений после удаления:: " << n_comps << std::endl;
	// table.arr[index].data = "EMPTY";
}

void fill_table(HashTable& table) {
	for (const std::string& key : words::keys)
		add_value(table, key);
}

void output_list(Node *head) {
	Node* cur{ head };
	while (cur) {
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	std::cout << "\n";
}

/*0) volatile template
1) auto union
2) constexpr explicit
3) inline for*/

void output_hash_table(const HashTable& table) {
	for (int i{ 0 }; i < table.size; i++) {
		std::cout << i << ") " << table.arr[i].data << " ";
		output_list(table.arr[i].head);
	}
}