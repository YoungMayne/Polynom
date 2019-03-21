#pragma once
#include <iostream>

template<typename Type>
class rlist
{
public:
		rlist();
		~rlist();

		void push(Type data);

		Type pop();

private:
		struct Node
		{
				Type data;
				Node *next;
		};

		Node * lst;
};

