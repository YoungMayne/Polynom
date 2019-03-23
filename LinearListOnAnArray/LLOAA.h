#pragma once
#include <iostream>

template<typename KEY, typename DATA>
struct Nexus {
		KEY key;
		DATA data;
};

#ifndef _LLOAA_H
#define _LLOAA_H


template<typename KEY, typename DATA>
class LLOAA {
public:
		LLOAA() {}
		LLOAA(const Nexus<KEY, DATA> &obj);
		~LLOAA();

		void add(const Nexus<KEY, DATA> &obj);
		void remove(KEY key);
		void clear();

		bool get(KEY key, Nexus<KEY, DATA> &result);
		bool empty();

		int size();
private:
		Nexus<KEY, DATA> *table;
		int t_size = 0;

		Nexus<KEY, DATA>* get_new_nexus(int size = 1);
};

//-------------PUBLIC-------------//

template<typename KEY, typename DATA>
LLOAA<KEY, DATA>::LLOAA(const Nexus<KEY, DATA> &obj) {
		table = get_new_nexus();
		*table = obj;
		t_size += 1;
}

template<typename KEY, typename DATA>
LLOAA<KEY, DATA>::~LLOAA() {
		if (t_size > 0) {
				delete[] table;
		}
}

template<typename KEY, typename DATA>
void LLOAA<KEY, DATA>::add(const Nexus<KEY, DATA> &obj) {
		Nexus<KEY, DATA> *temp = get_new_nexus(t_size + 1);

		for (int i = 0; i < t_size; ++i) {
				if (table[i].key == obj.key) {
						delete[] temp;
						return;
				}
				else {
						temp[i] = table[i];
				}
		}
		temp[t_size] = obj;
		delete[] table;
		table = temp;
		t_size += 1;
}

template<typename KEY, typename DATA>
void LLOAA<KEY, DATA>::remove(KEY key) {
		Nexus<KEY, DATA> *temp = get_new_nexus(t_size - 1);
		int n_size = 0;

		for (int i = 0; i < t_size; ++i) {
				if (table[i].key != key) {
						temp[n_size] = table[i];
						n_size += 1;
				}
		}
		delete[] table;
		table = temp;
		t_size -= 1;
}

template<typename KEY, typename DATA>
void LLOAA<KEY, DATA>::clear() {
		delete[] table;
		t_size = 0;
}

template<typename KEY, typename DATA>
bool LLOAA<KEY, DATA>::get(KEY key, Nexus<KEY, DATA> &result) {
		for (int i = 0; i < t_size; ++i) {
				if (table[i].key == key) {
						result = table[i];
						return true;
				}
		}

		return false;
}

template<typename KEY, typename DATA>
bool LLOAA<KEY, DATA>::empty() {
		return t_size == 0;
}

template<typename KEY, typename DATA>
int LLOAA<KEY, DATA>::size() {
		return t_size;
}

//-------------PRIVATE-------------//

template<typename KEY, typename DATA>
Nexus<KEY, DATA>* LLOAA<KEY, DATA>::get_new_nexus(int size) {
		Nexus<KEY, DATA> *result;

		try {
				result = new Nexus<KEY, DATA>[size];
		}
		catch (std::exception &e) {
				throw "No available memory";
		}

		return result;
}
#endif 
