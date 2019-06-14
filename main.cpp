#include<iostream>
#include "sort.h"
#include "Human.h"
#include <ctime>
#include<vector>
#include <stdlib.h>
#include "Human.h"

using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");
	SortableVector<Human> vec;
	if (readHumans("phone_book.txt", vec) == 0) {
		cout << "не получается окрыть входной файл";
	}
	//cout << "Введите новые записи в телефонную книгу" << endl;
	//cout << "Оставте пустую строку, если ввод записей закончен" << endl;
	//write_hum("phone_book.txt", vec);
	string name1,nowaya;
	getline(cin,name1);
	nowaya = convert(name1);
	cout<<findByNameBT(vec,nowaya);
	system("pause");
	return 0;
}
