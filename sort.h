#pragma once
#include<iostream>
#include<vector>

using namespace std;

template <class T> class SortableVector : public vector<T> {
private:
	void sift(int root, int last);
public:
	void sort();


};

template <class T> void SortableVector<T> ::sift(int root, int last) {
	int free = root;
	T lastElem = (*this)[free];
	while (true) {
		int left = 2 * free + 1, right = 2 * free + 2;
		int max;
		if (left > last) {
			break;
		}
		else if (left == last) {
			max = left;
		}
		else {
			max = ((*this)[left] < (*this)[right]) ? right : left;
		}
		if ((*this)[max] < lastElem || (*this)[max] == lastElem)
			break;
		(*this)[free] = (*this)[max];
		free = max;
	}
	(*this)[free] = lastElem;
}

template <class T> void SortableVector<T> ::sort() {
	for (int root = (int)(*this).size() / 2 - 1; root >= 0; root--) {
		sift(root, (*this).size() - 1);
	}
	for (int last = (*this).size() - 1; last > 0; last--) {
		T temp = (*this)[0];
		(*this)[0] = (*this)[last];
		(*this)[last] = temp;
		sift(0, last - 1);
	}
}

