#pragma once
#include <string>
#include <iostream>
#include <vector>

#define MAX_SIZE 12

struct HashTable {
	std::vector<std::string> arr;
	int size{ 0 };
	int count{ 0 };
};

std::pair<int, int> find(const HashTable& table, const std::string str);
int add_value(HashTable& table, const std::string str);
int hash_func(const HashTable table, const std::string str);
void fill_table(HashTable& table);
void output_hash_table(const HashTable& table);
void menu();
// void remove(HashTable& table, const std::string str);
void init_table(HashTable& table);


