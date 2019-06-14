#include<iostream>
#include "sort.h"
#include "Human.h"
#include <ctime>
#include<vector>
#include <stdlib.h>
#include"HumanFunc.h"
#include<map>

using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");
	SortableVector<Human> vec;
	map<string, HumanData> Humans;
	if (readHumans("phone_book.txt", vec) == 0) {
		cout << "не получается открыть входной файл";
	}
	write_hum("phone_book.txt", vec);
	string vib;
	string name;
	while (1) {
		cout << "Выберите способ поиска по телефонной книге: usual, bt, map, или оставьте пустую строку для выхода" << endl;
		getline(cin, vib);
		if (vib == "")
			break;
		if (vib == "usual") {
			while (1) {
				cout << "Введите имя" << endl;
				getline(cin, name);
				if (name == "") {
					break;
				}
				else {
					name = convert(name);
					cout << findByName(vec, name) << endl;
				}
			}
		}
		if (vib == "bt") {
			while (1) {
				cout << "Введите имя" << endl;
				getline(cin, name);
				if (name == "") {
					break;
				}
				else {
					name = convert(name);
					cout << findByNameBT(vec, name) << endl;
				}
			}
		}
		if (vib == "map") {
			if (read_for_map("phone_book.txt", Humans) == 0) {
				cout << "не получается окрыть входной файл";
			}
			while (1) {
				cout << "Введите имя" << endl;
				getline(cin, name);
				if (name == "") {
					break;
				}
				else {
					name = convert(name);
					if (Humans.count(name) == 0)
						cout << "Заданное имя отсутствует в списке" << endl;
					else
						cout << Humans[name] << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}
