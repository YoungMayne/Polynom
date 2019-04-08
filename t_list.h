#pragma once

#ifndef _Node
#define _Node

template<typename KEY, typename DATA>
struct Nexus {
		KEY key;
		DATA data;
};

#endif

#ifndef _t_list_H
#define _t_list_H

template<typename KEY, typename DATA>
class t_list {
public:
		t_list();
		t_list(const Nexus<KEY, DATA> &obj);
		~t_list();

		bool add(const Nexus<KEY, DATA> &obj);
		void remove(const KEY &key);
		void clear();

		bool exist(const KEY &key);
		bool get(const KEY &key, Nexus<KEY, DATA> &result);
		bool empty();

		void print();
private:
		struct p_nexus {
				Nexus<KEY, DATA> data;
				p_nexus *next = nullptr;
		};
		p_nexus *first = nullptr;

		void push_to(p_nexus* &pointer, const Nexus<KEY, DATA> &obj);
		void print(p_nexus* &n);
		void clear(p_nexus* &n);
};

//-------------PUBLIC-------------//

template<typename KEY, typename DATA>
inline t_list<KEY, DATA>::t_list() {}

template<typename KEY, typename DATA>
inline t_list<KEY, DATA>::t_list(const Nexus<KEY, DATA> &obj) {
		push_to(first, obj);
}

template<typename KEY, typename DATA>
inline t_list<KEY, DATA>::~t_list() {
		if (first != nullptr) {
				clear(first);
		}
}

template<typename KEY, typename DATA>
inline bool t_list<KEY, DATA>::add(const Nexus<KEY, DATA> &obj) {
		if (first == nullptr) {
				push_to(first, obj);
				return true;
		}

		p_nexus *temp = first;
		while (temp->next != nullptr) {
				if (temp->data.key == obj.key) {
						return false;
				}
				else {
						temp = temp->next;
				}
		}
		if (temp->data.key != obj.key) {
				push_to(temp->next, obj);
				return true;
		}
		else {
				return false;
		}
}

template<typename KEY, typename DATA>
inline void t_list<KEY, DATA>::remove(const KEY & key) {
		if (first->data.key == key) {
				p_nexus *temp = first->next;
				delete first;
				first = temp;
				return;
		}

		p_nexus *temp = first;
		while (temp->next != nullptr) {
				if (temp->next->data.key == key) {
						p_nexus *del = temp->next;
						temp->next = temp->next->next;
						delete del;
						return;
				}
				else {
						temp = temp->next;
				}
		}
}

template<typename KEY, typename DATA>
inline void t_list<KEY, DATA>::clear() {
		if (first != nullptr) {
				clear(first);
		}
}

template<typename KEY, typename DATA>
inline bool t_list<KEY, DATA>::exist(const KEY &key) {
		p_nexus *temp = first;

		while (temp != nullptr) {
				if (temp->data.key == key) {
						return true;
				}
				else {
						temp = temp->next;
				}
		}

		return false;
}

template<typename KEY, typename DATA>
inline bool t_list<KEY, DATA>::get(const KEY & key, Nexus<KEY, DATA>& result) {
		p_nexus *temp = first;

		while (temp != nullptr) {
				if (temp->data.key == key) {
						result = temp->data;
						return true;
				}
				else {
						temp = temp->next;
				}
		}

		return false;
}

template<typename KEY, typename DATA>
inline bool t_list<KEY, DATA>::empty() {
		return first == nullptr;
}

template<typename KEY, typename DATA>
inline void t_list<KEY, DATA>::print() {
		if (first != nullptr) {
				print(first);
		}
}

//-------------PRIVATE-------------//

template<typename KEY, typename DATA>
inline void t_list<KEY, DATA>::push_to(p_nexus* &pointer, const Nexus<KEY, DATA> &obj) {
		try {
				pointer = new p_nexus;
		}
		catch (std::exception &e) {
				throw "No available memory";
		}

		pointer->data = obj;
		pointer->next = nullptr;
}

template<typename KEY, typename DATA>
inline void t_list<KEY, DATA>::print(p_nexus *& n) {
		if (n->next != nullptr) {
				print(n->next);
		}
		std::cout << n->data.key << "\t|\t" << n->data.data.to_str() << std::endl;
}

template<typename KEY, typename DATA>
inline void t_list<KEY, DATA>::clear(p_nexus* &n) {
		if (n->next != nullptr) {
				clear(n->next);
		}
		delete n;
		n = nullptr;
}

#endif 
