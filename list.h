#ifndef LIST_H
#define LIST_H

#include <cassert>
#include <functional>

// declara Lista
template <class T>
struct List;

// node segura uma copia do objeto
template <class T>
struct Node
{

	explicit Node(const T &object, Node *next_node = nullptr, Node *prev_node = nullptr)
		: value(object), next(next_node), prev(prev_node) {}

  private:
	T* value;
	Node *next;
	Node *prev;

	friend class List<T>;
};

template <class T>
struct List
{
	// construtor de lista vazia
	inline List() : head(nullptr), tail(nullptr), sz(0) { assert_invariant(); }

	// desconstrutor da lista
	inline ~List()
	{
		assert_invariant();
		while (!empty())
			pop_back();
	}

	// tamanho da lista
	inline int size() const
	{
		assert_invariant();
		return sz;
	}

	// lista vazia
	inline bool empty() const { return size() == 0; }

	// insere uma objeto
	void insert(const T &object);

	// remove um objeto
	void remove(const T &object);

	// Encontra o objeto na lista
	Node<T> *find(const T &object);

	// altera o valor de um nó da lista
	void changeValue(const T &object);

	// remove um objeto do fim da lista
	void pop_back();

	// filtra a lista pelo predicado passado
	List<T> *filter(std::function<bool(const T &)> fn);

		// the invariant - must be always true for a well-formed List<>
		// the first member function that we write for any non-trivial class
		bool valid() const;
	inline void assert_invariant() const { assert(valid()); }

  private:
	Node<T> *head;
	Node<T> *tail;
	std::size_t sz; // number of nodes
};

template <class T>
bool List<T>::valid() const
{
	if (sz == 0)
		return head == nullptr && tail == nullptr;

	else if (sz == 1)
		return head != nullptr && tail == head && head->prev == nullptr && head->next == nullptr;

	else
	{
		if (head != nullptr && tail != nullptr && head != tail && head->prev == nullptr && tail->next == nullptr)
		{
			std::size_t n1 = 0;
			for (Node<T> *t = head; t != nullptr; t = t->next)
				++n1;

			std::size_t n2 = 0;
			for (Node<T> *t = tail; t != nullptr; t = t->prev)
				++n2;

			return n1 == sz && n1 == n2;
		}
		else
			return false;
	}
}

template <class T>
void List<T>::insert(const T &object)
{
	assert_invariant();

	if (empty())
		head = tail = new Node<T>(object);

	else
	{
		tail->next = new Node<T>(object, nullptr, tail);
		tail = tail->next;
	}

	++sz;

	assert_invariant();
}

template <class T>
void List<T>::pop_back()
{
	assert(!empty());
	assert_invariant();

	if (size() == 1)
	{
		delete head;
		head = tail = nullptr;
	}

	else
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}

	--sz;

	assert_invariant();
}

template <class T>
Node<T> *List<T>::find(const T &object)
{
	Node<T> *n;
	for (n = this->head; n != nullptr; n = n->next)
	{
		if (n->value == object)
		{
			return n;
		}
	}

	return nullptr;
}

template <class T>
void List<T>::remove(const T &object)
{
	Node<T> *n = this->find(object);

	if (n != nullptr)
	{
		if (n == this->head)
		{
			this->head = n->next;
		}
		else
		{
			if (n == this->tail)
			{
				this->tail = n->prev;
			}
			else
			{
				Node<T> *prev_node = n->prev;
				Node<T> *next_node = n->next;
				prev_node->next = n->next;
				next_node->prev = n->prev;
			}
		}
		delete n->value;
		delete n;
		this->sz--;
	}
}

template <class T>
void List<T>::changeValue(const T &object)
{
	Node<T> *n = this->find(object);
	if (n != nullptr)
	{
		delete n->value;
		n->value = object;
	}
}

template <class T>
List<T> *List<T>::filter(std::function<bool(const T &)> fn)
{
	List<T> *novo = new List<T>();
	Node<T> *n;

	for (n = this->head; n != nullptr; n = n->next)
	{
		if (fn(n->value))
		{
			novo->insert(n->value);
		}
	}

	return novo;
}

#endif /* LIST_H */