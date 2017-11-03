#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include <string>

template<typename T>
class Queue
{
private:
	int size;
	int max_size;
	struct unit
	{
		T item;
		unit * next;
	};
	unit * last;
	unit * first; 
public:
	Queue();
	Queue(int n);
	~Queue();
	bool enqueue(T &);
	bool dequeue(T &);
	bool is_empty() const;
	bool is_full() const;
	void invert();
	T & operator[](int) const;
};

template<typename T>
Queue<T>::Queue() : max_size(0), size(0)
{
	std::cout << "Initialized empty queue, no size limit\n";
	last = NULL;
	first = NULL;
}

template<typename T>
Queue<T>::Queue(int n) : max_size(n), size(0)
{
	std::cout << "Initialized empty queue, size limit " << n << "\n";
	last = NULL;
	first = NULL;
}

template<typename T>		
Queue<T>::~Queue()
{
	std::cout << "Destructor called\n";
	unit * temp;
	while (first != NULL)
	{
		temp = first;
		first = first->next;
		delete temp;
	}
}

template<typename T>
bool Queue<T>::enqueue(T & u)
{
	if (is_full())
		return false;
	std::cout << "enqueueing " << u << "\n";
	unit * newunit = new unit;
	newunit->item = u;
	newunit->next = NULL;
	if (size==0)
		first = newunit;
	else
		last->next = newunit;
	last = newunit;
	size++;
	return true;
}

template<typename T>
bool Queue<T>::dequeue(T & u)
{
	if (is_empty())
		return false;
	std::cout << "dequeueing\n";
	u = first->item;
	unit * temp = first;
	first = first->next;
	delete temp;
	size--;
	return true;
}

template<typename T>
bool Queue<T>::is_empty() const
{
	return first==NULL;
}

template<typename T>
bool Queue<T>::is_full() const
{
	return size==max_size && max_size>0;
}

template<typename T>
void Queue<T>::invert()
{
	std::cout << "Inverting queue\n";
	unit * current = first;
	unit * previous = NULL;
	unit * temp;
	last = current;
	while (current!=NULL)
	{
		temp = current;
		first = current;
		current = current->next;
		temp->next = previous;
		previous = temp;
	}
}

template<typename T>
T & Queue<T>::operator[](int n) const
{
	int current = 0;
	unit * currentp = first;
	if (n>size-1)
	{
		std::cout << "Outside scope of queue, what does this break\n";
		T empty_value(0);
		return empty_value; //I'm sure this is a disaster
	}
	while (current<n)
	{
		currentp = currentp->next;
		current ++;
	}
	return currentp->item;
}
	
			
		
	
			
#endif
