#include "LinkedList.hxx"

template <typename T>
Node<T>::Node()
	: next(0)
{
}

template <typename T>
Node<T>::Node(T& in)
	: next(0), data(in)
{
}

template <typename T>
LinkedList<T>::LinkedList()
	: head(0)
{
}

template <typename T>
void
LinkedList<T>::Insert(T& in)
{
	if (head == 0)
	{
		head = new Node<T>(in);
		tail = head;
	}
	else
	{
		tail.SetNext(new Node<T>(in));
		tail = tail.Next();
	}
}
