#pragma once
#include <string>
#include <iostream>
#include<math.h>

#define SIZE 12

struct Node {
	Node* next = nullptr;
	std::string key{ "\0" };
};

struct List {
	Node* head = nullptr;
	Node* tail = nullptr;
	std::string data{ "\0" };
};

struct HashTable {
	List arr[SIZE];
};

int hashFunc(std::string str);
int find(HashTable table, std::string str, int* counter);
void addValue(HashTable* table, std::string str, int* counter);
void remove(HashTable* table, std::string str);
void buildTable(HashTable* table);
void printArray(HashTable table);
bool isEmpty(HashTable table);
bool isFull(HashTable table);
void menu();
int input_for_menu(int stat);