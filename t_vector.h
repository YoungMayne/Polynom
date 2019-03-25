#pragma once
#include <iostream>

#ifndef _t_vector_H
#define _t_vector_H

template<typename KEY, typename DATA>
class t_vector {
public:
		t_vector() {}
		t_vector(const Nexus<KEY, DATA> &obj);
		~t_vector();

		bool add(const Nexus<KEY, DATA> &obj);
		void remove(const KEY &key);
		void clear();

		bool exist(const KEY &key);
		bool get(const KEY &key, Nexus<KEY, DATA> &result);
		bool empty();

		int size();
private:
		Nexus<KEY, DATA> *table = nullptr;
		int t_size = 0;

		Nexus<KEY, DATA>* get_new_nexus(int size = 1);
};

//-------------PUBLIC-------------//

template<typename KEY, typename DATA>
t_vector<KEY, DATA>::t_vector(const Nexus<KEY, DATA> &obj) {
		add(obj);
}

template<typename KEY, typename DATA>
t_vector<KEY, DATA>::~t_vector() {
		if (t_size > 0) {
				delete[] table;
		}
}

template<typename KEY, typename DATA>
bool t_vector<KEY, DATA>::add(const Nexus<KEY, DATA> &obj) {
		Nexus<KEY, DATA> *temp = get_new_nexus(t_size + 1);

		for (int i = 0; i < t_size; ++i) {
				if (table[i].key == obj.key) {
						delete[] temp;
						return false;
				}
				else {
						temp[i] = table[i];
				}
		}
		temp[t_size] = obj;
		delete[] table;
		table = temp;
		t_size += 1;
		
		return true;
}

template<typename KEY, typename DATA>
void t_vector<KEY, DATA>::remove(const KEY &key) {
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
void t_vector<KEY, DATA>::clear() {
		if (t_size > 0) {
				delete[] table;
		}
		t_size = 0;
}

template<typename KEY, typename DATA>
inline bool t_vector<KEY, DATA>::exist(const KEY &key) {
		for (int i = 0; i < t_size; ++i) {
				if (table[i].key == key) {
						return true;
				}
		}

		return false;
}

template<typename KEY, typename DATA>
bool t_vector<KEY, DATA>::get(const KEY &key, Nexus<KEY, DATA> &result) {
		for (int i = 0; i < t_size; ++i) {
				if (table[i].key == key) {
						result = table[i];
						return true;
				}
		}

		return false;
}

template<typename KEY, typename DATA>
bool t_vector<KEY, DATA>::empty() {
		return t_size == 0;
}

template<typename KEY, typename DATA>
int t_vector<KEY, DATA>::size() {
		return t_size;
}

//-------------PRIVATE-------------//

template<typename KEY, typename DATA>
Nexus<KEY, DATA>* t_vector<KEY, DATA>::get_new_nexus(int size) {
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
