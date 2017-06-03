#include <iostream>
#include "logger.hxx"
#include <cstring>

template<typename T> class LinkedList;

template <typename T>
class Node
{
friend class LinkedList<T>;
	T data;
	Node<T>* next;
public:
	Node();
	Node(const T& in);

	void SetData(const T& in);
	void SetNext(T* in);

	T Data();
};

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

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

template <typename T>
class LinkedList
{
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
		deleteChildNode(node->next);
	else
		delete node;	
}

template <typename T>
void
LinkedList<T>::Insert(T& in)
{
	if (head == 0)
	{
		std::cout << "head is null..create" << std::endl;
		head = new Node<T>(in);
		//head = new Node<T>();
		tail = head;
		size = 1;
	}
	else
	{
		std::cout << "head exists..append" << std::endl;
		++size;
		tail->next = new Node<T>(in);
		tail = tail->next;
		std::cout << "tail is " << tail->data << std::endl;
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
		std::cout << " Element : " << nxt->data << std::endl;
		nxt = nxt->next;
	}
}
