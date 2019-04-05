#pragma once
#include <string>
#include <iostream>
#include <vector>



template<typename DATA>
struct Nexus2 {
		std::string key;
		DATA data;
};

template<typename DATA>
class hash_table {
public:
		hash_table();
		/*hash_table(const Nexus<DATA> &obj);*/
		~hash_table();

		bool add(const Nexus2<DATA> &obj);
		void remove(const std::string &key);
		void clear();

		bool exist(const std::string &key);
		bool get(const std::string &key, Nexus2<DATA> &result);
		bool empty();

		int size();
		void print();
private:
	struct Node
	{
		Nexus2<DATA> data;
		Node *next = nullptr;
	};
	Node *htable[10];
		std::vector<std::vector<Nexus2<DATA>>> htable2;
		int hash_func(std::string _key) { return _key.size() % 10; };
};

template<typename DATA>
inline hash_table<DATA>::hash_table()//
{
	for (int i = 0; i < 10; i++)
	{
		htable[i] = nullptr;
	}
}

template<typename DATA>
inline hash_table<DATA>::~hash_table()
{
	for (int i = 0; i < 10; i++)
	{
		while (htable[i] != nullptr)
		{
			Node *tmp = htable[i];
			htable[i] = htable[i]->next;
			delete tmp;
		}
	}
}

template<typename DATA>
inline bool hash_table<DATA>::add(const Nexus2<DATA>& obj)//
{
	int k = hash_func(obj.key);
	Node *tmp = new Node;
	tmp->data.key = obj.key;
	tmp->data.data = obj.data;
		if (htable[k] == nullptr)
		{
			htable[k] = tmp;
			return true;
		}
	Node *tmp1 = htable[k];
	while (tmp1 != nullptr)
	{
		tmp1 = tmp1->next;
	}
	tmp1 = tmp;
	return true;
}

template<typename DATA>
inline void hash_table<DATA>::remove(const std::string & key)//
{
	int k = hash_func(key);
	if (htable[k] == nullptr)
		return;
	Node *tmp = htable[k];
	Node *tmp1 = tmp->next;
	while ((tmp1 != nullptr) && (tmp1->data.key != key))
	{
		tmp = tmp->next;
		tmp1 = tmp1->next;
	}
	if (tmp1 == nullptr)
		return;
	else
	{
		tmp->next = tmp1->next;
		delete tmp1;
		return;
	}
}

template<typename DATA>
inline void hash_table<DATA>::clear()//
{
	for (int i = 0; i < 10; i++)
	{
		while (htable[i] != nullptr)
		{
			Node *tmp = htable[i];
			htable[i] = htable[i]->next;
			delete tmp;
		}
	}
}

template<typename DATA>
inline bool hash_table<DATA>::exist(const std::string & key)//
{
	int k = hash_func(key);
	Node *tmp = htable[k];
	while (tmp != nullptr)
	{
		if (tmp->data.key == key)
			return true;
		tmp = tmp->next;
	}
	return false;
}

template<typename DATA>
inline bool hash_table<DATA>::get(const std::string & key, Nexus2<DATA>& result)//
{
	int k = hash_func(key);
	Node *tmp = htable[k];
	while (tmp != nullptr)
	{
		if (tmp->data.key == key)
		{
			result = tmp->data;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

template<typename DATA>
inline bool hash_table<DATA>::empty()//
{
	for (int i = 0; i < 10; i++)
	{
		if (htable[i] != nullptr)
			return false;
	}
	return true;
}

template<typename DATA>
inline int hash_table<DATA>::size()//
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		Node *tmp = htable[i];
		while (tmp != nullptr)
		{
			count++;
			tmp = tmp->next;
		}
	}
	return count;
}

template<typename DATA>
inline void hash_table<DATA>::print()
{
	for (int i = 0; i < 10; i++)
	{
		Node *tmp = htable[i];
		while (tmp != nullptr)
		{
			std::cout << tmp->data.key << "\t|\t" << tmp->data.data.to_str() << std::endl;
			tmp = tmp->next;
		}
	}
}
