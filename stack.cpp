#ifndef STACK_CPP_
#define STACK_CPP_
#include <iostream>
#include <string>

template <typename T>
class Stack
{
private:
	int size;
	int max_size;
	struct unit
	{
		T item;
		unit * next;
	};
	unit * first;
	unit * last;
public:
	Stack();
	Stack(int);
	~Stack();
	bool is_empty() const;
	bool is_full() const;
	bool push(T &);
	bool pop(T &);
	int count() const {return size;}
};

template <typename T>
Stack<T>::Stack() : size(0), max_size(0)
{
	first = NULL;
	last = NULL;
}

template <typename T>
Stack<T>::Stack(int n) : size(0), max_size(n)
{
	first = NULL;
	last = NULL;
}

template <typename T>
Stack<T>::~Stack()
{
	std::cout << "destructor called\n";
	unit * current = first;
	while (current!=NULL)
	{
		first = current;
		current = current->next;
		delete first;	
	}
}

template <typename T>
bool Stack<T>::is_empty() const
{
	return first==NULL;
}

template <typename T>
bool Stack<T>::is_full() const
{
	return size==max_size && max_size>0;
}

template <typename T>
bool Stack<T>::push(T & u)
{
	if (is_full())
		return false;
	std::cout << "pushing " << u << "\n";
	unit * newunit = new unit;
	newunit->item = u;
	newunit->next = NULL;
	if (size==0)
		first = newunit;
	else
		last->next = newunit;
	last = newunit;
	size ++;
	return true;
}

template <typename T>
bool Stack<T>::pop(T & u)
{
	if (is_empty())
		return false;
	u = last->item;
	if (first==last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		unit * temp = first;
		while (temp->next!=last)
			temp = temp->next;
		temp->next = NULL;
		delete last;
		last = temp;
	}
	size--;
	return true;
}

	
#endif
