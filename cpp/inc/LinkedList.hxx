
template <typename T>
class Node
{
	T data;
	T* next;
public:
	Node();
	Node(T& in);
	void SetData(T& in);
	void SetNext(T* in);
};

template <typename T>
class LinkedList
{
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList();
	void Insert(T&);
};
