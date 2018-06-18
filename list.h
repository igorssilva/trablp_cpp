#ifndef LIST_H
#define LIST_H

#include <cassert>
#include <memory>
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
	T value;
	Node *next;
	Node *prev;

	friend class List<T>;
};

template <class T>
struct List
{
	// construtor de lista vazia
	inline List() : head(nullptr), tail(nullptr), sz(0) { this->assert_invariant(); }

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
		return this->sz;
	}

	// lista vazia
	inline bool empty() const { return this->size() == 0; }

	// insere uma objeto
	void insert(const T &object);

	// remove um objeto
	void remove(const T &object);

	//remove um objeto
	void remove(Node<T> *n);

	// Encontra o objeto na lista
	Node<T> *find(const T &object);

	//Retorna o item no index
	T index(std::size_t index);

	// altera o valor de um nó da lista
	void changeValue(const T &object);

	// remove um objeto do fim da lista
	void pop_back();

	// filtra a lista pelo predicado passado
	List<T> *filter(std::function<bool(const T &)> fn);

	// retorna uma copia de uma parte da lista
	List<T> *slice(std::size_t b);

	// ordena a lista de acordo com a função passada
	void sort(std::function<bool(const T &, const T &)> fn);

	void apply(std::function<void(const T &)> fn);
	// the invariant - must be always true for a well-formed List<>
	// the first member function that we write for any non-trivial class
	bool valid() const;
	inline void assert_invariant() const { assert(this->valid()); }

  private:
	Node<T> *head;
	Node<T> *tail;
	std::size_t sz; // number of nodes
	void swap(Node<T> *a, Node<T> *b);
	void _quickSort(Node<T> *l, Node<T> *h, std::function<bool(const T &, const T &)> fn);
	Node<T> *partition(Node<T> *l, Node<T> *h, std::function<bool(const T &, const T &)> fn);
};

template <class T>
bool List<T>::valid() const
{
	if (this->sz == 0)
		return this->head == nullptr && this->tail == nullptr;

	else if (this->sz == 1)
		return this->head != nullptr && this->tail == this->head && this->head->prev == nullptr && this->head->next == nullptr;

	else
	{
		if (this->head != nullptr && this->tail != nullptr && this->head != this->tail && this->head->prev == nullptr && this->tail->next == nullptr)
		{
			std::size_t n1 = 0;
			for (Node<T> *t = this->head; t != nullptr; t = t->next)
				++n1;

			std::size_t n2 = 0;
			for (Node<T> *t = this->tail; t != nullptr; t = t->prev)
				++n2;

			return n1 == this->sz && n1 == n2;
		}
		else
			return false;
	}
}

template <class T>
void List<T>::insert(const T &object)
{
	this->assert_invariant();

	if (this->sz == 0)
		this->head = this->tail = new Node<T>(object);

	else
	{
		this->tail->next = new Node<T>(object, nullptr, this->tail);
		this->tail = this->tail->next;
	}

	this->sz++;

	this->assert_invariant();
}

template <class T>
void List<T>::pop_back()
{
	assert(!this->empty());
	this->assert_invariant();

	if (this->sz == 1)
	{
		delete this->head;

		this->head = this->tail = nullptr;
	}

	else
	{
		this->tail = this->tail->prev;
		delete this->tail->next;
		this->tail->next = nullptr;
	}

	this->sz--;

	this->assert_invariant();
}

template <class T>
Node<T> *List<T>::find(const T &object)
{
	Node<T> *n = nullptr;
	for (n = this->head; n != nullptr; n = n->next)
	{
		if (*(n->value) == *object)
		{
			return n;
		}
	}

	return nullptr;
}

template <class T>
void List<T>::remove(const T &object)
{
	this->assert_invariant();
	Node<T> *n = this->find(object);

	this->remove(n);
	this->assert_invariant();
}

template <class T>
void List<T>::remove(Node<T> *n)
{
	if (n != nullptr)
	{
		if (this->sz == 1)
		{
			this->head = this->tail = nullptr;
		}
		else
		{
			if (n == this->head)
			{
				this->head = n->next;
				this->head->prev = nullptr;
			}
			else
			{
				if (n == this->tail)
				{
					this->tail = n->prev;
					this->tail->next = nullptr;
				}
				else
				{
					Node<T> *prev_node = n->prev;
					Node<T> *next_node = n->next;
					prev_node->next = n->next;
					next_node->prev = n->prev;
				}
			}
		}
		delete n;
		this->sz--;
	}
}

template <class T>
void List<T>::changeValue(const T &object)
{

	this->assert_invariant();
	Node<T> *n = this->find(object);
	if (n != nullptr)
	{
		n->value = object;
	}

	this->assert_invariant();
}

template <class T>
List<T> *List<T>::filter(std::function<bool(const T &)> fn)
{

	List<T> *novo = new List<T>();
	Node<T> *n = this->head;
	for (n; n != nullptr; n = n->next)
	{
		if (fn(n->value))
		{
			novo->insert(n->value);
		}
	}

	return novo;
}

template <class T>
List<T> *List<T>::slice(std::size_t b)
{

	List<T> *l = new List<T>();

	if (this->sz == 0 || b >= this->sz)
	{
		return l;
	}

	Node<T> *n = this->head;
	int i = 0;
	while (i < b)
	{
		n = n->next;
		i++;
	}

	for (n; n != nullptr; n = n->next)
	{
		l->insert(n->value);
	}

	return l;
}

template <class T>
//Troca o elemento a e b de lugar
void List<T>::swap(Node<T> *a, Node<T> *b)
{
	if (a == b)
	{
		return;
	}

	T temp = a->value;
	a->value = b->value;
	b->value = temp;
}

template <class T>
/*
	Considera o último elemento como pivô, coloca o elemento pivô em seu
	posição correta na lista ordenada, e coloca todos os menores (menores que
	pivô) para a esquerda do pivô e todos os elementos maiores para a direita do pivô
*/
Node<T> *List<T>::partition(Node<T> *l, Node<T> *h, std::function<bool(const T &, const T &)> fn)
{
	// Seleciona o pivo como o elemento h
	T x = h->value;

	// 1--
	Node<T> *i = l->prev;
	Node<T> *j;
	for (j = l; j != h; j = j->next)
	{

		if (fn(j->value, x))
		{
			// i++
			if (i == nullptr)
			{
				i = l;
			}
			else
			{
				i = i->next;
			}

			swap(i, j);
		}
	}
	// i++
	if (i == nullptr)
	{
		i = l;
	}
	else
	{
		i = i->next;
	}
	swap(i, h);
	return i;
}

template <class T>
//Ordena a lista de acordo com a comparação passada por função
void List<T>::_quickSort(Node<T> *l, Node<T> *h, std::function<bool(const T &, const T &)> fn)
{

	if (h != nullptr && l != h && l != h->next)
	{
		Node<T> *p = partition(l, h, fn);
		_quickSort(l, p->prev, fn);
		_quickSort(p->next, h, fn);
	}
}

template <class T>
//Funcao chamada para ordenar
void List<T>::sort(std::function<bool(const T &, const T &)> fn)
{
	_quickSort(head, tail, fn);
}

template <class T>
void List<T>::apply(std::function<void(const T &)> fn)
{
	Node<T> *n = nullptr;
	for (n = head; n != nullptr; n = n->next)
	{
		fn(n->value);
	}
}

//Retorna o item na posição index, 0 a size - 1;
template <class T>
T List<T>::index(std::size_t index)
{
	if (index > 0 && index <= this->sz)
	{
		Node<T> *node = this->head;
		index--;
		while (index > 0)
		{
			node = node->next;
			index--;
		}

		return node->value;
	}

	return nullptr;
}

#endif /* LIST_H */