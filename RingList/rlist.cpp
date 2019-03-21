#include "rlist.h"

template<typename Type>
rlist<Type>::rlist()
{
}

template<typename Type>
rlist<Type>::~rlist()
{
}

template<typename Type>
void rlist<Type>::push(Type data)
{
		if (lst == nullptr)
		{
				lst = new Node;
				lst->data = data;
				lst->next = lst;
		}
		else
		{
				try
				{
						Node *temp = new Node;
						temp->data = data;
						temp->next = lst->next;
						lst->next = temp;
						lst = temp;
				}
				catch (std::exception &e)
				{
						throw "No available memory";
				}
		}
}

template<typename Type>
Type rlist<Type>::pop()
{
		Type result = lst->data;
		Node *temp = lst;

		if (lst->next == lst)
		{				
				delete temp;
				lst = nullptr;
		}
		else
		{
				while (lst->next != temp)
				{
						lst = lst->next;
				}
				lst->next = temp->next;
				delete temp;
		}

		return result;
}
