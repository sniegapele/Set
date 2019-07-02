#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class my_set {
	T* values;
	int size;
public:
	my_set();
	~my_set();

	void add(T value);
	void remove(T value);
	bool get(T value);
	int get_size() const { return size; }

	void print();
};

template<typename T>
my_set<T>::my_set():size(0) {
	values = new T[0];
}

template<typename T>
my_set<T>::~my_set() {
	delete[] values;
}

template<typename T>
void my_set<T>::add(T value) {
	if (get(value))
		return;
	++size;
	T* temp = new int[size];
	for (int i = 0; i < size - 1; ++i)
		temp[i] = values[i];
	temp[size - 1] = value;
	values = temp;
}

template<typename T>
void my_set<T>::remove(T value) {
	if (!get(value))
		return;
	--size;
	T* temp = new int[size];
	int t = 0;
	for (int i = 0; i < size + 1; ++i) {
		if (values[i] != value) {
			temp[t] = values[i];
			++t;
		}
	}
	values = temp;
}

template<typename T>
bool my_set<T>::get(T value) {
	for (int i = 0; i < size; ++i)
		if (values[i] == value)
			return true;
	return false;
}

template<typename T>
void my_set<T>::print() {
	std::vector<T> temp;
	for (int i = 0; i < size; ++i)
		temp.push_back(values[i]);

	std::sort(temp.begin(), temp.end());

	for (int i = 0; i < size; ++i)
		std::cout << temp[i] << " ";
	std::cout << std::endl;
}

#endif