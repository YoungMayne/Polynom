<<<<<<< HEAD
#pragma once

#pragma once
#include <string>
#include <iostream>
#include <vector>



template<typename DATA>
struct Nexus3 {
	std::string key;
	DATA data;
	bool empty = true;
};

template<typename DATA>
class hash_table2 {
public:
	hash_table2() {};
	/*hash_table(const Nexus<DATA> &obj);*/
	~hash_table2() {};

	bool add(const Nexus3<DATA> &obj);
	void remove(const std::string &key);
	void clear();

	bool exist(const std::string &key);
	bool get(const std::string &key, Nexus3<DATA> &result);
	bool empty();

	int size();
	void print();
private:
	Nexus3<DATA> htable[50];
	int hash_func(std::string _key) { return _key.size() % 50; };
};

template<typename DATA>
inline bool hash_table2<DATA>::add(const Nexus3<DATA>& obj)//
{
	int k = hash_func(obj.key);
	if (size() == 50)
		return false;
	for (int j = 0; j < 50; j++)
	{
		if ((htable[j].empty == false) && (htable[j].key == obj.key))
			return false;
	}
	if (htable[k].empty == true)
	{
		htable[k] = obj;
		htable[k].empty = false;
		return true;
	}
	else
	{
		int i = k + 1;
		while ((i % 50) != k)
		{
			if (htable[i].empty == true)
			{
				htable[i] = obj;
				htable[i].empty = false;
				return true;
			}
			i++;
		}
		return false;
	}
}

template<typename DATA>
inline void hash_table2<DATA>::remove(const std::string & key)//
{
	int k = hash_func(key);
	if (!(htable[k].empty) && (htable[k].key == key))
	{
		htable[k].empty = true;
		return;
	}
	else
	{
		int i = k + 1;
		while ((i % 50) != k)
		{
			if (!(htable[i].empty) && (htable[i].key == key))
			{
				htable[i].empty = true;
				return;
			}
			i++;
		}
		return;
	}
}

template<typename DATA>
inline void hash_table2<DATA>::clear()//
{
	for (int i = 0; i < 50; i++)
		htable[i].empty = true;
}

template<typename DATA>
inline bool hash_table2<DATA>::exist(const std::string & key)//
{
	int k = hash_func(key);
	if (!(htable[k].empty) && (htable[k].key == key))
	{
		return true;
	}
	else
	{
		int i = k + 1;
		while ((i % 50) != k)
		{
			if (!(htable[i].empty) && (htable[i].key == key))
			{
				return true;
			}
			i++;
		}
		return false;
	}
}

template<typename DATA>
inline bool hash_table2<DATA>::get(const std::string & key, Nexus3<DATA>& result)//
{
	int k = hash_func(key);
	if (!(htable[k].empty) && (htable[k].key == key))
	{
		result = htable[k];
		return true;
	}
	else
	{
		int i = k + 1;
		while ((i % 50) != k)
		{
			if (!(htable[i].empty) && (htable[i].key == key))
			{
				result = htable[i];
				return true;
			}
			i++;
		}
		return false;
	}
}

template<typename DATA>
inline bool hash_table2<DATA>::empty()//
{
	for (int i = 0; i < 50; i++)
	{
		if (htable[i].empty == false)
			return false;
	}
	return true;
}

template<typename DATA>
inline int hash_table2<DATA>::size()//
{
	int count = 0;
	for (int i = 0; i < 50; i++)
	{
		if (htable[i].empty == false)
			count++;
	}
	return count;
}

template<typename DATA>
inline void hash_table2<DATA>::print()
{
	for (int i = 0; i < 50; i++)
	{
		if (htable[i].empty == false)
		{
			std::cout << htable[i].key << "\t|\t" << htable[i].data.to_str() << std::endl;
		}
	}
}
=======
#pragma once

#pragma once
#include <string>
#include <iostream>
#include <vector>



template<typename DATA>
struct Nexus3 {
	std::string key;
	DATA data;
	bool empty = true;
};

template<typename DATA>
class hash_table2 {
public:
	hash_table2() {};
	/*hash_table(const Nexus<DATA> &obj);*/
	~hash_table2() {};

	bool add(const Nexus3<DATA> &obj);
	void remove(const std::string &key);
	void clear();

	bool exist(const std::string &key);
	bool get(const std::string &key, Nexus3<DATA> &result);
	bool empty();

	int size();
	void print();
private:
	Nexus3<DATA> htable[50];
	int hash_func(std::string _key) { return _key.size() % 50; };
};

template<typename DATA>
inline bool hash_table2<DATA>::add(const Nexus3<DATA>& obj)//
{
	int k = hash_func(obj.key);
	if (size() == 50)
		return false;
	for (int j = 0; j < 50; j++)
	{
		if ((htable[j].empty == false) && (htable[j].key == obj.key))
			return false;
	}
	if (htable[k].empty == true)
	{
		htable[k] = obj;
		htable[k].empty = false;
		return true;
	}
	else
	{
		int i = k + 1;
		while ((i % 50) != k)
		{
			if (htable[i].empty == true)
			{
				htable[i] = obj;
				htable[i].empty = false;
				return true;
			}
			i++;
		}
		return false;
	}
}

template<typename DATA>
inline void hash_table2<DATA>::remove(const std::string & key)//
{
	int k = hash_func(key);
	if (!(htable[k].empty) && (htable[k].key == key))
	{
		htable[k].empty = true;
		return;
	}
	else
	{
		int i = k + 1;
		while ((i % 50) != k)
		{
			if (!(htable[i].empty) && (htable[i].key == key))
			{
				htable[i].empty = true;
				return;
			}
			i++;
		}
		return;
	}
}

template<typename DATA>
inline void hash_table2<DATA>::clear()//
{
	for (int i = 0; i < 50; i++)
		htable[i].empty = true;
}

template<typename DATA>
inline bool hash_table2<DATA>::exist(const std::string & key)//
{
	int k = hash_func(key);
	if (!(htable[k].empty) && (htable[k].key == key))
	{
		return true;
	}
	else
	{
		int i = k + 1;
		while ((i % 50) != k)
		{
			if (!(htable[i].empty) && (htable[i].key == key))
			{
				return true;
			}
			i++;
		}
		return false;
	}
}

template<typename DATA>
inline bool hash_table2<DATA>::get(const std::string & key, Nexus3<DATA>& result)//
{
	int k = hash_func(key);
	if (!(htable[k].empty) && (htable[k].key == key))
	{
		result = htable[k];
		return true;
	}
	else
	{
		int i = k + 1;
		while ((i % 50) != k)
		{
			if (!(htable[i].empty) && (htable[i].key == key))
			{
				result = htable[i];
				return true;
			}
			i++;
		}
		return false;
	}
}

template<typename DATA>
inline bool hash_table2<DATA>::empty()//
{
	for (int i = 0; i < 50; i++)
	{
		if (htable[i].empty == false)
			return false;
	}
	return true;
}

template<typename DATA>
inline int hash_table2<DATA>::size()//
{
	int count = 0;
	for (int i = 0; i < 50; i++)
	{
		if (htable[i].empty == false)
			count++;
	}
	return count;
}

template<typename DATA>
inline void hash_table2<DATA>::print()
{
	for (int i = 0; i < 50; i++)
	{
		if (htable[i].empty == false)
		{
			std::cout << htable[i].key << "\t|\t" << htable[i].data.to_str() << std::endl;
		}
	}
}
>>>>>>> d5110f4ae81c3939e8fddcfc0408e8bf33715c5c
