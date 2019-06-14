#pragma once
#undef UNICODE
#include<iostream>
#include<string>
#include<fstream>
#include "sort.h"
#include<vector>
#include<windows.h>
#include<map>
#include"humanData.h"

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
	getline(in, human.name,'-');  
	getline(in, human.data.address,'-');
	getline(in, human.data.phone);
	return in; 
}
ostream& operator <<(ostream& out, const Human& human) {
	out << human.name << "  " << human.data.address << "  " << human.data.phone;
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
	ofstream out(filename);
	char name[50];
	char addr[50];
	char ph[20];
	while (1) {
		cin.getline(name, 50);
		cin.getline(addr, 50);
		cin.getline(ph, 20);
		if (*name == 0 && *addr == 0 && *ph == 0) {
			break;
		}
		Human h = Human(name,addr,ph);
		humans.push_back(h);
	}
	humans.sort();
	for (int i = 0; i < humans.size(); i++) {
		out << humans[i] << endl;
	}
}

/*
Human findByName(const vector<Human>& humans, const string& name1) { 
	setlocale(LC_ALL, "Russian");
	cout<<"Ищем: "<<name1<<endl; 
	for (vector<Human>::const_iterator it=humans.begin(); it!=humans.end(); it++) {
		if (it->name==name1)     
			return (*it);  
	}  
	Human empty;
	cout << "Заданное имя отсутствует в списке";
	return(empty);
}


string convert(string str) { 
	char* buf = new char[strlen(str.c_str()) + 1]; 
	OemToChar(str.c_str(), buf); 
	string res(buf); 
	delete[] buf;   
	return res; 
}
Human findByNameBT(const vector<Human>& humans, const string& name, int min, int max) {
	int index = (min + max) / 2;
	if (min > max){
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
*/
struct value_type {
	string first;
	HumanData second; 
};

bool readHumans(const char* filename, map<string, HumanData>& humans) { 
	ifstream in(filename); 
	if (!in.is_open())
		return false;  
	string name;  
	HumanData data;
	getline(in, name) >> data; 
	while (!in.fail()) {
		humans[name] = data;
		getline(in, name) >> data;
	}   
	return true;
}
