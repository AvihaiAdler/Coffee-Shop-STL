#ifndef __LIST_H__
#define __LIST_H__

#include<iostream>

template <class T> class Link;

template <class T>
class List
{
	Link<T>* first;
	Link<T>* last;
	int size;

public:
	List();
	List(const List<T>& list);
	~List();

	T& operator[](int index) const;
	List<T>& operator=(const List<T>& other);

	int getSize() const { return size; }
	bool isEmpty() const;
	void push_back(const T& value);
	void pop_back();
	void remove(int index);
	void remove(const T& value);
};

template <class T>
class Link
{
	T value;
	Link<T>* next;
	Link<T>* previous;

	Link(const T& value) : value(value), next(nullptr), previous(nullptr) {}
	friend class List<T>;
};

template <class T>
List<T>::List()
{
	first = last = nullptr;
	size = 0;
}

template <class T> 
List<T>::List(const List<T>& other)
{
	*this = other;
}

template <class T>
List<T>::~List() 
{
	while (last != nullptr)
		pop_back();
}

template <class T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this != &other)
	{
		Link<T>* current = other.first;
		while (current != nullptr)
		{
			this->push_back(current->value);
			current = current->next;
		}
	}
	return *this;
}

template <class T>
T& List<T>::operator[](int index) const
{
	int counter = 0;
	Link<T>* current = first;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->value;
		}
		current = current->next;
		counter++;
	}
	return last->next->value;
}

template <class T>
bool List<T>::isEmpty() const { size == 0 ? return true : return false; }

template <class T>
void List<T>::push_back(const T& value)
{
	Link<T>* newlink = new Link<T>(value); //opertaor= of value!
	if (first == nullptr)
		first = last = newlink;
	else
	{
		newlink->previous = last;
		last->next = newlink;
		last = last->next;
	}
	size++;
}

template <class T>
void List<T>::pop_back()
{
	Link<T>* pop = last;
	if (pop != nullptr)
	{
		if (last != first)
		{
			last = last->previous;
			last->next = nullptr;
			delete pop;
			size--;
		}
		else
		{
			first = last = nullptr;
			delete pop;
			size--;
		}
	}
}

template <class T>
void List<T>::remove(int index)
{
	int counter = 0;
	Link<T>* removeable = first;
	while (removeable != nullptr)
	{
		if (counter == index)
			break;
		removeable = removeable->next;
		counter++;
	}

	if (removeable != nullptr)
	{
		if (removeable == first)
		{
			first = first->next;
			first->previous = nullptr;
			removeable->next = nullptr;
			delete removeable;
		} 
		else if (removeable == last)
		{
			pop_back();
		}
		else
		{
			removeable->previous->next = removeable->next;
			removeable->next->previous = removeable->previous;
			removeable->next = nullptr;
			removeable->previous = nullptr;
			delete removeable;
		}
	}
}

//Redundent and a bit stupid - but the writers of the headers chose to implement remove() by index and not the other way around
template <class T>
void List<T>::remove(const T& value)
{
	int counter = 0;
	Link<T>* removeable = first;
	if (*removeable->value == value)	//operator== for value required
		remove[0];
	else
	{
		while (removeable != nullptr)
		{
			if (*removeable->value == value)
				remove[counter];
			removeable = removeable->next;
			counter++;
		}
	}
}

#endif // !__LIST_H__

