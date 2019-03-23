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

		Type pop();

private:
		struct Node {
				Type data;
				Node *next;
		};

		Node * lst;
};

#endif _RLIST_H
