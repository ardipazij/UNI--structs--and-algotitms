#pragma once
#include <string>
#include <iostream>
#include <vector>

#define MAX_SIZE 10

struct Node {
	Node* next{ nullptr };
	std::string data{};
};

struct Element {
	Node* head{ nullptr };
	Node* tail{ nullptr };
	std::string data{};
};

struct HashTable {
	std::vector<Element> arr;
	int size{};
};

void init_table(HashTable& table);
int find(const HashTable& table, const std::string str);
int add_value(HashTable& table, const std::string str);
int hash_func(const HashTable &table, const std::string str);
void fill_table(HashTable& table);
void output_hash_table(const HashTable& table);
void menu();
void remove(HashTable& table, const std::string str);



