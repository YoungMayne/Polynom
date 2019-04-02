#pragma once
#include <iostream>

#ifndef  _RLIST_H
#define _RLIST_H


template<typename Type>
class rlist {
public:
		rlist();
		rlist(const Type &data);
		~rlist();

		void push(const Type &data);
		void clear();
		void pop();

		Type get();

		bool empty();
private:
		struct Node {
				Type data;
				Node *next;
		};

		Node* lst = nullptr;
};

//-------------PUBLIC-------------//

template<typename Type>
rlist<Type>::rlist() {}

template<typename Type>
rlist<Type>::rlist(const Type &data) {
		push(data);
}

template<typename Type>
rlist<Type>::~rlist() {
		while (lst != nullptr) {
				if (lst->next == lst) {
						delete lst;
						lst = nullptr;
				}
				else {
						Node *temp = lst;
						lst = lst->next;
						delete temp;
						temp = nullptr;
				}
		}
}

template<typename Type>
void rlist<Type>::push(const Type &data) {
		Node *temp;

		try {
				temp = new Node;
		}
		catch (std::exception &e) {
				throw "No available memory";
		}

		temp->data = data;
		if (lst == nullptr) {
				temp->next = temp;
		}
		else {
				temp->next = lst->next;
				lst->next = temp;
		}
		lst = temp;
}

template<typename Type>
void rlist<Type>::clear() {
		while (lst != nullptr) {
				if (lst->next == lst) {
						delete lst;
						lst = nullptr;
				}
				else {
						Node *temp = lst;
						lst = lst->next;
						delete temp;
						temp = nullptr;
				}
		}
}

template<typename Type>
void rlist<Type>::pop() {
		if (empty() == true) {
				return;
		}

		Type	result = lst->data;
		Node *temp = lst;

		if (lst->next == lst) {
				lst = nullptr;
		}
		else {
				while (lst->next != temp) {
						lst = lst->next;
				}
				lst->next = temp->next;
		}
		delete temp;
}

template<typename Type>
Type rlist<Type>::get() {
		return lst->data;
}

template<typename Type>
bool rlist<Type>::empty() {
		return lst == nullptr;
}

#endif
