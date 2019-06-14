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

using namespace std;

struct Human {
	string name;
	HumanData data;
	Human() {};
	Human(string aname, string addr, string ph) : name(aname), data(addr, ph) {}
	void operator =(const Human& r);
	bool operator ==(const Human& h) const;
	bool operator >(const Human& h) const;
	bool operator <(const Human& h) const;
};
istream& operator >>(istream& in, Human& human) {
	getline(in, human.name, '-');
	getline(in, human.data.address, '-');
	getline(in, human.data.phone);
	return in;
}
ostream& operator <<(ostream& out, const Human& human) {
	out << human.name << "-" << human.data.address << "-" << human.data.phone;
	return out;
}

void Human::operator =(const Human& r) {
	name = r.name;
	data.address = r.data.address;
	data.phone = r.data.phone;
}

bool Human::operator ==(const Human& r) const {
	if (name == r.name)
		return 1;
	return 0;
}

bool Human::operator >(const Human& r) const {
	if (name > r.name)
		return 1;
	return 0;
}

bool Human::operator <(const Human& r) const {
	if (name < r.name)
		return 1;
	return 0;
}

