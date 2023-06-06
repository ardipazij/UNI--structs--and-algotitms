#include"ExtHash.h"

namespace key_wr {
	const int size_of_table = 10;

	std::string keys[key_wr::size_of_table]{
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

int hashFunc(std::string str) {
	int res = 0;

	for (int i = 0; i < str.size(); i++) {
		int a = str[i];
		res += a;
	}
	res %= SIZE;

	return abs(res);
}

int find(HashTable table, std::string str, int* counter) {
	int ret = -1, fl = 1;
	int index = hashFunc(str);
	*counter += 1;
	if (table.arr[index].data == "\0") { fl = 0; }
	else if (table.arr[index].data != str) {
		*counter += 1;
		Node* curr = table.arr[index].head;
		if (curr != nullptr) {
			while (curr != table.arr[index].tail) {
				*counter += 1;
				if (curr->key == str) {
					ret = index;
					std::cout << "������ ���������� �����: " << index << "\n";
					break;
				}
				curr = curr->next;
			}
			*counter += 1;
			if (curr->key == str) {
				ret = index;
				std::cout << "������ ���������� �����: " << index << "\n";
			}
		}
	}
	else ret = index;

	return ret;
}

/*
���� ��������� ����������� ���������� ���������: ������� ��� �������� � ����� � ��� �� ��������� ���-������� �� ��������������� �������� ������.
*/

void addValue(HashTable* table, std::string str, int* counter) {
	if (isFull(*table)) std::cout << "������� ���������. \n";
	else {
		int index = find(*table, str, counter);
		if (index != -1) {
			std::cout << "�������� ��� ���������� ��� ��������: " << index << "\n";
		}
		else {
			index = hashFunc(str);
			*counter += 1;
			if (table->arr[index].data != "\0") {
				Node* n_ew = new Node;
				n_ew->key = str;
				if (table->arr[index].head == nullptr) {
					table->arr[index].head = table->arr[index].tail = n_ew;
				}
				else {
					table->arr[index].tail->next = n_ew;
					table->arr[index].tail = n_ew;
				}
			}
			else table->arr[index].data = str;
		}
	}
}

void remove(HashTable* table, std::string str) {
	int index = find(*table, str, &index);
	if (index == -1) {
		std::cout << "�������� �� �������. " << "\n";
	}
	else {
		if (table->arr[index].data == str) { // ������ ������� � ������ ��������� ��������� ����� �������� str
			if (table->arr[index].head != nullptr) {
				table->arr[index].data = table->arr[index].head->key;
				Node* del = table->arr[index].head;
				table->arr[index].head = del->next;
				free(del);
			}
			else table->arr[index].data = "\0";
		}
		else {
			Node* curr = table->arr[index].head;
			if (table->arr[index].head->key == str) { table->arr[index].head = table->arr[index].head->next; free(curr); }
			else {
				while (curr->next->key != str) curr = curr->next;
				Node* del = curr->next;
				curr->next = del->next;
				if (del == table->arr[index].tail) table->arr[index].tail = curr;
				free(del);
			}
		}
	}
}

void buildTable(HashTable* table) {
	int c = 0;
	for (int i = 0; i < key_wr::size_of_table; i++) {
		std::string key = key_wr::keys[i];
		addValue(table, key, &c);
	}
	std::cout << "���-�� ����������� ��������� ��� ����������: " << c << "\n";
}

void printArray(HashTable table) {
	for (int i = 0; i < SIZE; i++) {
		std::cout << i << ". " << table.arr[i].data << "  ";
		if (table.arr[i].head != nullptr) {
			Node* curr = table.arr[i].head;
			while (curr != table.arr[i].tail) {
				std::cout << curr->key << " ";
				curr = curr->next;
			}
			std::cout << curr->key << "\n";
		}
		else std::cout << "\n";
	}
}

bool isEmpty(HashTable table) {
	bool ret = 0;
	for (int i = 0; i < SIZE; i++) {
		if (table.arr[i].data != "\0") {
			ret = 1;
			break;
		}
	}
	return ret;
}

bool isFull(HashTable table) {
	bool ret = 1;
	for (int i = 0; i < SIZE; i++) {
		if (table.arr[i].data == "\0") {
			ret = 0;
			break;
		}
	}
	return ret;
}