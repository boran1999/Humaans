#pragma once
#undef UNICODE
#include<iostream>
#include<string>
#include<fstream>
#include "sort.h"
#include<vector>
#include<windows.h>
#include<map>
#include"HumanData.h"
#include"Human.h"

using namespace std;

string convert(string str) {
	char* buf = new char[strlen(str.c_str()) + 1];
	OemToChar(str.c_str(), buf);
	string res(buf);
	delete[] buf;
	return res;
}

bool readHumans(const char* filename, vector<Human>& humans) {
	ifstream in(filename);
	if (!in.is_open())
		return false;
	Human human;
	in >> human;
	while (!in.fail()) {
		humans.push_back(human);
		in >> human;
	}
	return true;
}

void write_hum(const char* filename, SortableVector<Human>& humans) {
	setlocale(LC_ALL, "Russian");
	ofstream out(filename);
	string name;
	string addr;
	string ph;
	cout << "Добавьте нового человека в тел.книгу, для остановки записи оставьте ввод пустым" << endl;
	while (1) {
		cout << "Введите имя" << endl;
		getline(cin, name);
		name = convert(name);
		cout << "Введите адрес" << endl;
		getline(cin, addr);
		addr = convert(addr);
		cout << "Введите телефон" << endl;
		getline(cin, ph);
		ph = convert(ph);
		if (name == "" && addr == "" && ph == "") {
			break;
		}
		Human h = Human(name, addr, ph);
		humans.push_back(h);
	}
	humans.sort();
	for (int i = 0; i < humans.size(); i++) {
		out << humans[i] << endl;
	}
}

Human findByName(const vector<Human>& humans, const string& name1) {
	setlocale(LC_ALL, "Russian");
	cout << "Ищем: " << name1 << endl;
	for (vector<Human>::const_iterator it = humans.begin(); it != humans.end(); it++) {
		if (it->name == name1)
			return (*it);
	}
	Human empty;
	cout << "Заданное имя отсутствует в списке";
	return(empty);
}

Human findByNameBT(const vector<Human>& humans, const string& name, int min, int max) {
	int index = (min + max) / 2;
	if (min > max) {
		Human empty;
		cout << "Заданное имя отсутствует в списке";
		return(empty);
	}
	else if (humans[index].name == name)
		return humans[index];
	else if (humans[index].name > name)
		return findByNameBT(humans, name, min, index - 1);
	else
		return findByNameBT(humans, name, index + 1, max);
}
Human findByNameBT(const vector<Human>& humans, const string& name) {
	cout << "Ищем: " << name << endl;
	return findByNameBT(humans, name, 0, (int)humans.size() - 1);
}

bool read_for_map(const char* filename, map<string, HumanData>& humans) {
	ifstream in(filename);
	if (!in.is_open())
		return false;
	string name;
	HumanData data;
	getline(in, name, '-') >> data;
	while (!in.fail()) {
		humans[name] = data;
		getline(in, name, '-') >> data;
	}
	return true;
}
