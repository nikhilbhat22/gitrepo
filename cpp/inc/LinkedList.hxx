#ifndef __LINKED_LIST_HXX__
#define __LINKED_LIST_HXX__

#include <iostream>
#include "logger.hxx"
#include <cstring>

template<typename T> class LinkedList;
template<typename T> class LinkedListHelper;

template <typename T>
class Node
{
friend class LinkedList<T>;
friend class LinkedListHelper<T>;
	T data;
	Node<T>* next;
public:
	~Node();
	Node();
	Node(const T& in);

	void SetData(const T& in);
	void SetNext(Node<T>* in);

	T Data();
};

template <typename T>
Node<T>::~Node()
{
}

template <typename T>
Node<T>::Node()
	: next(0)
{
}

template <typename T>
Node<T>::Node(const T& in)
	: next(0), data(in)
{
}

template <typename T>
T
Node<T>::Data()
{
	return data;
}

template <typename T>
void
Node<T>::SetNext(Node<T>* in)
{
	next = in;
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

template <typename T>
class LinkedList
{
friend class LinkedListHelper<T>;
	void deleteChildNode(Node<T>*);
	Node<T>* head;
	Node<T>* tail;
	unsigned int size;

public:
	LinkedList();
	~LinkedList();
	void Insert(T&);
	unsigned int Size() const;
	void Print() const;
	const Node<T>* Head() const;
	const Node<T>* Tail() const;
};

template <typename T>
LinkedList<T>::LinkedList()
	: head(0), tail(0), size(0)
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	deleteChildNode(head);
}

template <typename T>
void
LinkedList<T>::deleteChildNode(Node<T>* node)
{
	if (node->next)
	{
		deleteChildNode(node->next);
	}
	delete node;	
	node = 0;
}

template <typename T>
void
LinkedList<T>::Insert(T& in)
{
	if (head == 0)
	{
		head = new Node<T>(in);
		tail = head;
		size = 1;
	}
	else
	{
		++size;
		tail->next = new Node<T>(in);
		tail = tail->next;
	}
}

template <typename T>
unsigned int
LinkedList<T>::Size() const
{
	return size;
}

template <typename T>
void
LinkedList<T>::Print() const
{
	Node<T>* nxt = head;
	for (int i = 0; i < size; ++i)
	{
		nxt = nxt->next;
	}
}

template <typename T>
const Node<T>*
LinkedList<T>::Head() const
{
	return head;
}

template <typename T>
const Node<T>*
LinkedList<T>::Tail() const
{
	return tail;
}

//--------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------

template <typename T>
class LinkedListHelper
{
public:
	static bool CheckCycle(const LinkedList<T>& in);
};

template <typename T>
bool
LinkedListHelper<T>::CheckCycle(const LinkedList<T>& in)
{
	Node<T>* slow = in.head;
	Node<T>* fast = in.head->next;
	
	while (slow != 0 && fast != 0 && fast->next)
	{
		if (slow == fast)
			return true;

		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}

#endif
