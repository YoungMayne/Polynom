#pragma once

#ifndef _t_vector_sorted_H
#define _t_vector_sorted_H

template<typename KEY, typename DATA>
struct Nexus {
		KEY key;
		DATA data;
};

template<typename KEY, typename DATA>
class t_vector_sorted {
public:
		t_vector_sorted() {}
		t_vector_sorted(const Nexus<KEY, DATA> &obj);
		~t_vector_sorted();

		void add(const Nexus<KEY, DATA> &obj);
		void remove(const KEY &key);
		void clear();

		bool exist(const KEY &key);
		bool get(const KEY &key, Nexus<KEY, DATA> &result);
		bool empty();

		int size();
private:
		Nexus<KEY, DATA> *table;
		int t_size = 0;

		Nexus<KEY, DATA>* get_new_nexus(int size = 1);
		int get_index_binary(const KEY & key, bool existing);
};

//-------------PUBLIC-------------//

template<typename KEY, typename DATA>
inline t_vector_sorted<KEY, DATA>::t_vector_sorted(const Nexus<KEY, DATA>& obj){
		add(obj);
}

template<typename KEY, typename DATA>
inline t_vector_sorted<KEY, DATA>::~t_vector_sorted(){
		if (t_size > 0) {
				delete[]table;
		}
}

template<typename KEY, typename DATA>
inline void t_vector_sorted<KEY, DATA>::add(const Nexus<KEY, DATA>& obj) {
		int index;

		if (t_size == 0) {
				index = 0;
		}
		else {
				index = get_index_binary(obj.key, false);
				if (index == -1) {
						return;
				}
		}

		Nexus<KEY, DATA> *temp = get_new_nexus(t_size + 1);
		for (int i = 0; i < index; ++i) {
				temp[i] = table[i];
		}
		for (int i = index; i < t_size; ++i) {
				temp[i + 1] = table[i];
		}
		delete[] table;
		table = temp;
		table[index] = obj;
		t_size += 1;
}

template<typename KEY, typename DATA>
inline void t_vector_sorted<KEY, DATA>::remove(const KEY & key) {
		int index = get_index_binary(key, true);

		if (index == -1) {
				return;
		}

		Nexus<KEY, DATA> *temp = get_new_nexus(t_size - 1);
		for (int i = 0; i < index; ++i) {
				temp[i] = table[i];
		}
		for (int i = index + 1; i < t_size; ++i) {
				temp[i - 1] = table[i];
		}
		delete[] table;
		table = temp;
		t_size -= 1;
}

template<typename KEY, typename DATA>
inline void t_vector_sorted<KEY, DATA>::clear() {
		if (t_size > 0) {
				delete[] table;
		}
		t_size = 0;
}

template<typename KEY, typename DATA>
inline bool t_vector_sorted<KEY, DATA>::exist(const KEY & key) {
		return get_index_binary(key, true) != -1;
}

template<typename KEY, typename DATA>
inline bool t_vector_sorted<KEY, DATA>::get(const KEY & key, Nexus<KEY, DATA>& result) {
		int index = get_index_binary(key, true);

		if (index == -1) {
				return false;
		}
		else {
				result = table[index];
				return true;
		}
}

template<typename KEY, typename DATA>
inline bool t_vector_sorted<KEY, DATA>::empty() {
		return t_size == 0;
}

template<typename KEY, typename DATA>
inline int t_vector_sorted<KEY, DATA>::size() {
		return t_size;
}

//-------------PRIVATE-------------//

template<typename KEY, typename DATA>
inline Nexus<KEY, DATA>* t_vector_sorted<KEY, DATA>::get_new_nexus(int size) {
		Nexus<KEY, DATA> *result;

		try {
				result = new Nexus<KEY, DATA>[size];
		}
		catch (std::exception &e) {
				throw "No available memory";
		}

		return result;
}

template<typename KEY, typename DATA>
inline int t_vector_sorted<KEY, DATA>::get_index_binary(const KEY & key, bool existing) {
		int left = 0;
		int right = t_size;

		while (true) {
				int mid = (left + right) / 2;

				if (key < table[mid].key) {
						right = mid - 1;
				}
				else if (key > table[mid].key) {
						left = mid + 1;
				}
				else {
						if (existing == true) {
								return mid;
						}
						else {
								return -1;
						}
				}

				if (left > right) {
						if (existing == true) {
								return -1;
						}
						else {
								return right;
						}
				}
		}
}

#endif 