#pragma once
#include <string>
#include <iostream>

#define MAX_SIZE 10

struct HashTable {
	std::string arr[MAX_SIZE]{};
};

int find(const HashTable& table, const std::string str);
void add_value(HashTable& table, const std::string str);
bool is_key_valid(const std::string& value);
int hash_func(const std::string str);
void fill_table(HashTable& table);
void output_hash_table(const HashTable& table);
void menu();
void remove(HashTable& table, const std::string str);


