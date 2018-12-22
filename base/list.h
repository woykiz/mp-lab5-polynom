#ifndef __LIST_H__
#define __LIST_H__

using namespace std;

#include <iostream>
#include <algorithm>

template <class T>
struct Node 
{
	Node<T>* pNext;
	T value;
};

template <class T>
class TList
{
public:

	class iterator : public std::iterator<std::input_iterator_tag, T, T, Node<T>*, T> 
	{
		Node<T>* current;
	public:
		iterator(Node<T>* point) : current(point) {}
		iterator& operator++() { current = current->pNext; return *this; }
		iterator operator++(int) { ListIterator res = *this; ++(*this); return res; }
		iterator operator+(int d)
		{
			for (int i = 0; i < d; i++)
				operator++();
			return *this;
		}
		bool operator==(iterator li) const { return current == li.current; }
		bool operator!=(iterator li) const { return !(*this == li); }
		reference operator*() const { return current->value; }
		pointer getNode() const { return current; }
	};

private:
	Node<T>* pFirst;
	Node<T>* pLast;
	int size;
	iterator IterateElement(int index)
	{
		if (index < 0 || index >= size)
			throw "out of bounds";

		return (iterator(pFirst) + (index));
	}
	T GetReadOnly(int index)
	{
		T el = *IterateElement(index);
		return el;
	}
	void freeMem()
	{
		Node<T>** ptrArray = new Node<T>*[size];
		for (int i = 0; i < size; i++)
			ptrArray[i] = IterateElement(i).getNode();

		for (int i = 0; i < size; i++)
			delete ptrArray[i];

		delete[] ptrArray;
	}
public:


	TList()
	{
		pLast = new Node<T>();
		pFirst = pLast;
		size = 0;
	};
	TList(TList<T>& list)
	{
		size = 0;
		pLast = new Node<T>();
		pFirst = pLast;

		for (auto el : list)
			Add(el);
	}

	T& operator[](int index)
	{
		T el = *IterateElement(index);
		return (T&)el;
	}
	void Add(T element)
	{
		Insert(element, size);
	}
	void Insert(T element, int index)
	{
		Node<T>* n;
		if (index == 0)
		{
			Node<T>* newElement = new Node<T>();
			newElement->pNext = pFirst;
			newElement->value = element;

			pFirst = newElement;
		}
		else
		{
			n = IterateElement(index - 1).getNode();

			Node<T>* newElement = new Node<T>();
			newElement->pNext = n->pNext;
			newElement->value = element;
			n->pNext = newElement;
		}
		size++;
	}
	bool operator==(TList<T>& list)
	{
		if (size != list.size)
			return false;

		for (int i = 0; i < size; i++)
			if (*IterateElement(i) != list.GetReadOnly(i))
				return false;

		return true;
	}

	bool operator!=(TList<T>& list) const
	{
		return !(*this == list);
	}
	TList& operator=(TList<T>& list)
	{
		freeMem();

		pLast = new Node<T>();
		pFirst = pLast;
		size = 0;

		for (auto el : list)
			Add(el);

		return *this;
	}

	~TList()
	{
		freeMem();
	}

	int Size()
	{
		return size;
	}

	iterator begin() { return iterator(pFirst); }
	iterator end() { return iterator(pLast); }
};

#endif