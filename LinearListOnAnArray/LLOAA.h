#pragma once
#include <iostream>

template<typename KEY, typename DATA>
struct Nexus {
		KEY key;
		DATA data;
};

#ifndef _LLOAA_H
#define _LLOAA_H


template<typename KEY, typename DATA>
class LLOAA{
public:
		LLOAA() {}
		LLOAA(const Nexus<KEY, DATA> &obj);
		~LLOAA();

		void add(const Nexus<KEY, DATA> &obj);
		void remove(KEY key);
		void clear();

		bool get(KEY key, Nexus<KEY, DATA> &result);
		bool empty();

		int size();
private:
		Nexus<KEY, DATA> *table = nullptr;
		int t_size = 0;

		Nexus<KEY, DATA>* get_new_nexus();
		Nexus<KEY, DATA>* get_new_nexus(int size);
};

#endif 
