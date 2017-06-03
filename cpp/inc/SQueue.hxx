#ifndef __SQUEUE_HXX__
#define __SQUEUE_HXX__

#include <stack>

struct SQInvalidOperation : public std::exception
{
	const char* what() const throw() {return "Dequeue performed on an Empty SQueue";}
};

template <typename T>
class SQueue
{
private:
	std::stack<T> s1;
	std::stack<T> s2;

public:
	SQueue();
	void Enqueue(const T& in);
	T Dequeue();
	T& Peek();
	unsigned int Size() const;
};

template <typename T>
SQueue<T>::SQueue()
{
}

template <typename T>
void
SQueue<T>::Enqueue(const T& in)
{
	s1.push(in);
}

template <typename T>
T
SQueue<T>::Dequeue()
{
	T ret;
	if (s2.size() == 0)
	{
		while (s1.size())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}

	if (s2.size() != 0)
	{
		ret = s2.top();
		s2.pop();
	}
	else
	{
		throw  SQInvalidOperation();
	}
	return ret;
}

template <typename T>
unsigned int
SQueue<T>::Size() const
{
	return s1.size() + s2.size();
}

#endif
