#include "LLOAA.h"

template<typename KEY, typename DATA>
LLOAA<KEY, DATA>::LLOAA(const Nexus<KEY, DATA> &obj) {
		table = get_new_nexus();
		*table = obj;
		t_size += 1;
}

template<typename KEY, typename DATA>
LLOAA<KEY, DATA>::~LLOAA(){
		delete[] table;
}

template<typename KEY, typename DATA>
void LLOAA<KEY, DATA>::add(const Nexus<KEY, DATA> &obj){
		if (t_size == 0) {
				table = get_new_nexus();
				*table = obj;
				t_size += 1;
		}
		else {
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
				table = temp;
				t_size += 1;
				return;
		}
}

template<typename KEY, typename DATA>
void LLOAA<KEY, DATA>::remove(KEY key){
		for (int i = 0; i < t_size; ++i) {
				if (table[i].key == key) {
						Nexus<KEY, DATA> *temp = get_new_nexus(t_size - 1);
						int n_size = 0;
						for (int j = 0; j < t_size - 1; ++j) {
								if (j == i) {
										continue;
								}
								else {
										temp[n_size] = table[j];
										n_size += 1;
								}
						}
						delete[] table;
						table = temp;
						t_size -= 1;
						break;
				}
		}
}

template<typename KEY, typename DATA>
void LLOAA<KEY, DATA>::clear(){
		delete[] table;
		table = nullptr;
		t_size = 0;
}

template<typename KEY, typename DATA>
bool LLOAA<KEY, DATA>::get(KEY key, Nexus<KEY, DATA> &result){
		for (int i = 0; i < t_size; ++i) {
				if (table[i].key == key) {
						result = table[i];
						return true;
				}
		}

		return false;
}

template<typename KEY, typename DATA>
bool LLOAA<KEY, DATA>::empty(){
		return !t_size;
}

template<typename KEY, typename DATA>
int LLOAA<KEY, DATA>::size(){
		return t_size;
}

template<typename KEY, typename DATA>
Nexus<KEY, DATA>* LLOAA<KEY, DATA>::get_new_nexus(){
		Nexus<KEY, DATA> *result;

		try {
				result = new Nexus<KEY, DATA>;
		}
		catch (std::exception &e) {
				throw "No available memory";
		}

		return result;
}

template<typename KEY, typename DATA>
Nexus<KEY, DATA>* LLOAA<KEY, DATA>::get_new_nexus(int size){
		Nexus<KEY, DATA> *result;

		try {
				result = new Nexus<KEY, DATA>[size];
		}
		catch(std::exception &e){
				throw "No available memory";
		}

		return result;
}
