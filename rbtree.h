#pragma once

#ifndef _rbtree_H
#define _rbtree_H

typedef enum {
		RED,
		BLACK
}Color;

template<typename KEY, typename DATA>
class rbtree {
public:
		rbtree() {}

		bool add(const Nexus<KEY, DATA> &obj);
		bool get(const KEY &key, Nexus<KEY, DATA> &result);

		void remove(const KEY &key);

private:
		struct leaf {
				Nexus<KEY, DATA> data;
				Color cType;

				leaf *right = nullptr;
				leaf *left = nullptr;
				leaf *parent = nullptr;
		};
		leaf *head = nullptr;

		void rotate_left(leaf *&l);
		void rotate_right(leaf* &l);
		void fixup(leaf* &l);
};

//-------------PUBLIC-------------//

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
		fixup(temp);

		return true;
}

template<typename KEY, typename DATA>
inline bool rbtree<KEY, DATA>::get(const KEY &key, Nexus<KEY, DATA> &result){
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
inline void rbtree<KEY, DATA>::remove(const KEY & key){
		leaf *x, *y;

		if (z->left == NIL || z->right == NIL) {
				y = z;
		}
		else {
				y = z->right;
				while (y->left != NIL) y = y->left;
		}

		/* x is y's only child */
		if (y->left != NIL)
				x = y->left;
		else
				x = y->right;

		/* remove y from the parent chain */
		x->parent = y->parent;
		if (y->parent)
				if (y == y->parent->left)
						y->parent->left = x;
				else
						y->parent->right = x;
		else
				root = x;

		if (y != z) z->data = y->data;


		if (y->color == BLACK)
				deleteFixup(x);

		free(y);
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
		if (l->parent) {
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
inline void rbtree<KEY, DATA>::fixup(leaf* &l) {
		while (l != head && l->parent->cType == RED) {
				if (l->parent == l->parent->parent->left) {
						leaf *temp = l->parent->parent->right;
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








#endif 
