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

		Type pop();

		bool full();//lul
		bool empty();

private:
		struct Node {
				Type data;
				Node *next;
		};

		Node * lst;
};

#endif
