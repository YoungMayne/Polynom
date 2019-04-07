#pragma once

#ifndef _Node
#define _Node

template<typename KEY, typename DATA>
struct Nexus {
		KEY key;
		DATA data;
};

#endif

#ifndef _rbtree_H
#define _rbtree_H

typedef enum {
		RED,
		BLACK
}cType;

template<typename KEY, typename DATA>
class rbtree {
public:
		rbtree() {}
		rbtree(const Nexus<KEY, DATA> &obj);
		~rbtree();

		bool add(const Nexus<KEY, DATA> &obj);
		bool exist(const KEY &key);
		bool get(const KEY &key, Nexus<KEY, DATA> &result);
		bool empty();

		void remove(const KEY &key);
		void clear();

		void print();
private:
		struct leaf {
				Nexus<KEY, DATA> data;
				cType cType = RED;

				leaf *right = nullptr;
				leaf *left = nullptr;
				leaf *parent = nullptr;
		};
		leaf *head = nullptr;

		void rotate_left(leaf *&l);
		void rotate_right(leaf* &l);
		void addfixup(leaf* &l);
		void removefixup(leaf* &l);
		bool get_leaf(const KEY &key, leaf* &result);

		std::vector<KEY> keys;
};

//-------------PUBLIC-------------//

template<typename KEY, typename DATA>
inline rbtree<KEY, DATA>::rbtree(const Nexus<KEY, DATA>& obj){
		add(obj);
}

template<typename KEY, typename DATA>
inline rbtree<KEY, DATA>::~rbtree(){
		if (head == nullptr) {
				return;
		}

		while (head != nullptr) {
				if (head->left != nullptr) {
						while (head->left != nullptr) {
								head = head->left;
						}
						leaf *temp = head;
						head = head->parent;
						delete temp;
						head->left = nullptr;
				}
				else if (head->right != nullptr) {
						while (head->right != nullptr) {
								head = head->right;
						}
						leaf *temp = head;
						head = head->parent;
						delete temp;
						head->right = nullptr;
				}
				else if (head->parent == nullptr) {
						delete head;
						head = nullptr;
				}
				else {
						delete head;
						head = nullptr;
				}
		}
}

template<typename KEY, typename DATA>
inline bool rbtree<KEY, DATA>::add(const Nexus<KEY, DATA>& obj) {
		leaf *current = head;
		leaf *parent = nullptr;

		while (current != nullptr) {
				if (obj.key == current->data.key) {
						return false;
				}
				parent = current;
				current = obj.key < current->data.key ? current->left : current->right;
		}

		leaf *temp;
		try {
				temp = new leaf;
		}
		catch (std::exception &e) {
				throw "No available memory";
		}

		temp->data.key = obj.key;
		temp->data.data = obj.data;
		temp->parent = parent;
		temp->cType = RED;

		if (parent == nullptr) {
				head = temp;
		}
		else {
				if (obj.key < parent->data.key) {
						parent->left = temp;
				}
				else {
						parent->right = temp;
				}
		}
		addfixup(temp);

		keys.push_back(obj.key);
		return true;
}

template<typename KEY, typename DATA>
inline bool rbtree<KEY, DATA>::exist(const KEY & key){
		leaf *current = head;

		while (current != nullptr) {
				if (current->data.key == key) {
						return true;
				}
				else {
						current = key < current->data.key ? current->left : current->right;
				}
		}

		return false;
}

template<typename KEY, typename DATA>
inline bool rbtree<KEY, DATA>::get(const KEY &key, Nexus<KEY, DATA> &result){
		if (head == nullptr) {
				return false;
		}
		leaf *current = head;

		while (current != nullptr) {
				if (current->data.key == key) {
						result = current->data;
						return true;
				}
				else {
						current = key < current->data.key ? current->left : current->right;
				}
		}

		return false;
}

template<typename KEY, typename DATA>
inline bool rbtree<KEY, DATA>::empty(){
		return head == nullptr;
}

template<typename KEY, typename DATA>
inline void rbtree<KEY, DATA>::remove(const KEY & key){
		leaf *elem;

		if (get_leaf(key, elem) == false) {
				return;
		}
		for (int i = 0; i < keys.size(); ++i) {
				if (keys[i] == key) {
						keys.erase(keys.begin() + i);
				}
		}

		leaf *temp1;
		leaf *temp2;

		if (elem->left == nullptr || elem->right == nullptr) {
				temp2 = elem;
		}
		else {
				temp2 = elem->right;
				while (temp2->left != nullptr) {
						temp2 = temp2->left;
				}
		}
		if (temp2->left != nullptr) {
				temp1 = temp2->left;
		}
		else {
				temp1 = temp2->right;
				if (temp1 == nullptr) {
						temp1 = new leaf;
				}
		}
		temp1->parent = temp2->parent;
		if (temp2->parent) {
				if (temp2 == temp2->parent->left) {
						temp2->parent->left = temp1;
				}
				else {
						temp2->parent->right = temp1;
				}
		}
		else {
				head = temp1;
		}
		if (temp2 != elem) {
				elem->data = temp2->data;
		}
		if (temp2->cType == BLACK) {
				removefixup(temp1);
		}

		delete temp2;
}

template<typename KEY, typename DATA>
inline void rbtree<KEY, DATA>::clear(){
		if (head == nullptr) {
				return;
		}

		while (head != nullptr) {
				if (head->left != nullptr) {
						while (head->left != nullptr) {
								head = head->left;
						}
						leaf *temp = head;
						head = head->parent;
						delete temp;
						head->left = nullptr;
				}
				else if (head->right != nullptr) {
						while (head->right != nullptr) {
								head = head->right;
						}
						leaf *temp = head;
						head = head->parent;
						delete temp;
						head->right = nullptr;
				}
				else if (head->parent == nullptr) {
						delete head;
						head = nullptr;
				}
				else {
						delete head;
						head = nullptr;
				}
		}
		keys.clear();
}

template<typename KEY, typename DATA>
inline void rbtree<KEY, DATA>::print(){
		auto temp = head;

		for (const auto &c : keys) {
				Nexus<KEY, DATA> result;
				get(c, result);
				std::cout << c << "\t|\t" << result.data.to_str() << std::endl;
		}
}

//-------------PRIVATE-------------//

template<typename KEY, typename DATA>
inline void rbtree<KEY, DATA>::rotate_left(leaf *& l) {
		leaf *temp = l->right;

		l->right = temp->left;
		if (temp->left != nullptr) {
				temp->left->parent = l;
		}
		if (temp != nullptr) {
				temp->parent = l->parent;
		}
		if (l->parent) {
				if (l == l->parent->left) {
						l->parent->left = temp;
				}
				else {
						l->parent->right = temp;
				}
		}
		else {
				head = temp;
		}
		temp->left = l;
		if (l != nullptr) {
				l->parent = temp;
		}
}

template<typename KEY, typename DATA>
inline void rbtree<KEY, DATA>::rotate_right(leaf *& l) {
		leaf *temp = l->left;

		l->left = temp->right;
		if (temp->right != nullptr) {
				temp->right->parent = l;
		}
		if (temp != nullptr) {
				temp->parent = l->parent;
		}
		if (l == nullptr) {
				l = new leaf;
		}
		if (l->parent == nullptr) {
				l->parent = new leaf;
				if (l == l->parent->right) {
						l->parent->right = temp;
				}
				else {
						l->parent->left = temp;
				}
		}
		else {
				head = temp;
		}
		temp->right = l;
		if (l != nullptr) {
				l->parent = temp;
		}
}

template<typename KEY, typename DATA>
inline void rbtree<KEY, DATA>::addfixup(leaf* &l) {
		while (l != head && l->parent->cType == RED) {
				if (l->parent == l->parent->parent->left) {
						leaf *temp = l->parent->parent->right;
						if (temp == nullptr) {
								temp = new leaf;
						}
						if (temp->cType == RED) {
								l->parent->cType = BLACK;
								l->parent->parent->cType = RED;
								l = l->parent->parent;
								temp->cType = BLACK;
						}
						else {
								if (l == l->parent->right) {
										l = l->parent;
										rotate_left(l);
								}
								l->parent->cType = BLACK;
								l->parent->parent->cType = RED;
								rotate_right(l->parent->parent);
						}
				}
				else {
						leaf *temp = l->parent->parent->left;
						if (temp == nullptr) {
								temp = new leaf;
						}
						if (temp->cType == RED) {
								l->parent->cType = BLACK;
								l->parent->parent->cType = RED;
								l = l->parent->parent;
								temp->cType = BLACK;
						}
						else {
								if (l == l->parent->left) {
										l = l->parent;
										rotate_right(l);
								}
								l->parent->cType = BLACK;
								l->parent->parent->cType = RED;
								rotate_left(l->parent->parent);
						}
				}
		}
		head->cType = BLACK;
}

template<typename KEY, typename DATA>
inline void rbtree<KEY, DATA>::removefixup(leaf *& l){
		while (l != head && l->cType == BLACK) {
				if (l == l->parent->left) {
						leaf *temp = l->parent->right;
						if (temp->cType == RED) {
								temp->cType = BLACK;
								l->parent->cType = RED;
								rotate_left(l->parent);
								temp = l->parent->right;
						}
						if (temp->left->cType == BLACK && temp->right->cType == BLACK) {
								temp->cType = RED;
								l = l->parent;
						}
						else {
								if (temp->right->cType == BLACK) {
										temp->left->cType = BLACK;
										temp->cType = RED;
										rotate_right(temp);
										temp = l->parent->right;
								}
								temp->cType = l->parent->cType;
								l->parent->cType = BLACK;
								temp->right->cType = BLACK;
								rotate_left(l->parent);
								l = head;
						}
				}
				else {
						leaf *temp = l->parent->left;
						if (temp->cType == RED) {
								temp->cType = BLACK;
								l->parent->cType = RED;
								rotate_right(l->parent);
								temp = l->parent->left;
						}
						if (temp->right->cType == BLACK && temp->left->cType == BLACK) {
								temp->cType = RED;
								l = l->parent;
						}
						else {
								if (temp->left->cType == BLACK) {
										temp->right->cType = BLACK;
										temp->cType = RED;
										rotate_left(temp);
										temp = l->parent->left;
								}
								temp->cType = l->parent->cType;
								l->parent->cType = BLACK;
								temp->left->cType = BLACK;
								rotate_right(l->parent);
								l = head;
						}
				}
		}
		l->cType = BLACK;
}

template<typename KEY, typename DATA>
inline bool rbtree<KEY, DATA>::get_leaf(const KEY & key, leaf *& result){
		leaf *current = head;

		while (current != nullptr) {
				if (current->data.key == key) {
						result = current;
						return true;
				}
				else {
						current = key < current->data.key ? current->left : current->right;
				}
		}

		return false;
}

#endif 
