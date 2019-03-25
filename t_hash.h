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
	~hash_table() {};

	void add(const Nexus2<DATA> &obj);
	void remove(const std::string &key);
	void clear();

	bool exist(const std::string &key);
	bool get(const std::string &key, Nexus2<DATA> &result);
	bool empty();

	int size();
private:
	std::vector<std::vector<Nexus2<DATA>>> htable;
	int hash_func(std::string _key) { return _key.size() % 10; };
};

template<typename DATA>
inline hash_table<DATA>::hash_table()
{
	htable.resize(10);
	for (int i = 0; i < htable.size(); i++)
	{
		htable[i] = {};
	}
}

template<typename DATA>
inline void hash_table<DATA>::add(const Nexus2<DATA>& obj)
{
	int k = hash_func(obj.key);
	for (int i = 0; i < htable[k].size(); i++)
	{
		if (htable[k][i] == obj.key)
			return;
	}
	htable[k].push_back(obj);
}

template<typename DATA>
inline void hash_table<DATA>::remove(const std::string & key)
{
	int k = hash_func(key);
	for (int i = 0; i < htable[k].size(); i++)
	{
		if (htable[k][i].key == key)
		{
			htable[k].erase(i);
			return;
		}
	}
}

template<typename DATA>
inline void hash_table<DATA>::clear()
{
	for (int i = 0; i < htable.size(); i++)
	{
		htable[i].clear();
	}
}

template<typename DATA>
inline bool hash_table<DATA>::exist(const std::string & key)
{
	int k = hash_func(key);
	for (int i = 0; i < htable[k].size(); i++)
	{
		if (htable[k][i].key == key)
			return true;
	}
	return false;
}

template<typename DATA>
inline bool hash_table<DATA>::get(const std::string & key, Nexus2<DATA>& result)
{
	int k = hash_func(key);
	for (int i = 0; i < htable[k].size(); i++)
	{
		if (htable[k][i].key == key)
			return true;
	}
	return false;
}

template<typename DATA>
inline bool hash_table<DATA>::empty()
{
	for (int i = 0; i < htable.size(); i++)
	{
		if (!(htable[i].empty()))
			return false;
	}
	return true;
}

template<typename DATA>
inline int hash_table<DATA>::size()
{
	int count = 0;
	for (int i = 0; i < htable.size(); i++)
	{
		count += htable[i].size();
	}
	return count;
}