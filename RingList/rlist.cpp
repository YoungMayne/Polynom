#include "rlist.h"

template<typename Type>
rlist<Type>::rlist() {}

template<typename Type>
rlist<Type>::rlist(const Type &data) {
		push(data);
}

template<typename Type>
rlist<Type>::~rlist() {
		while (lst != nullptr) {
				Node *temp = lst;
				lst = lst->next;
				delete temp;
		}
}

template<typename Type>
void rlist<Type>::push(const Type &data) {
		if (lst == nullptr) {
				try {
						lst = new Node;
						lst->data = data;
						lst->next = lst;
				}
				catch (std::exception &e) {
						throw "No available memory";
				}
		}
		else {
				try {
						Node *temp = new Node;
						temp->data = data;
						temp->next = lst->next;
						lst->next = temp;
						lst = temp;
				}
				catch (std::exception &e) {
						throw "No available memory";
				}
		}
}

template<typename Type>
void rlist<Type>::clear(){
		while (lst != nullptr) {
				Node *temp = lst;
				lst = lst->next;
				delete temp;
		}
}

template<typename Type>
Type rlist<Type>::pop() {
		Type	result = lst->data;
		Node *temp = lst;

		if (lst->next == lst) {
				delete temp;
				lst = nullptr;
		}
		else {
				while (lst->next != temp) {
						lst = lst->next;
				}

				lst->next = temp->next;
				delete temp;
		}

		return result;
}

template<typename Type>
bool rlist<Type>::full(){
		try {
				Node *temp = new Node;
		}
		catch (std::exception &e) {
				return true;
		}

		return false;
}

template<typename Type>
bool rlist<Type>::empty(){
		return lst == nullptr;
}
