#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>

struct Node {
	T* key;
	Node<T>* next;
	Node<T>* prev;
};

template <class T>

class List {
	private:
		Node<T>* head;
        Node<T>* tail
		int size;

	public:
		List ();
		virtual ~List ();
		void insert (T& key);
        void remove (T& key);
        Node<T>* find(T& key);

		int size ();
		Node<T>* front ();
		Node<T>* end ();
		
		void change(Node<T>& node, T& key)

		List<T> filter(std::function<int(int)> f)
		
};	

#endif /* LIST_H */