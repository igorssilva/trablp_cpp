#ifndef LIST_H
#define LIST_H

#include <cassert>
#include <functional>
#include <memory>

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

	//remove um objeto
	void remove(Node<T> *n);

	// Encontra o objeto na lista
	Node<T> *find(const T &object);

	inline T val(const T &object)
	{
		return find(object)->value;
	}

	// altera o valor de um nó da lista
	void changeValue(const T &object);

	// remove um objeto do fim da lista
	void pop_back();

	// filtra a lista pelo predicado passado
	List<T> *filter(std::function<bool(const T &)> fn);

	// retorna uma copia de uma parte da lista
	List<T> *slice(int b);
	List<T> *slice(int b, int e);

	// ordena a lista de acordo com a função passada
	void sort(std::function<bool(const T &, const T &)> fn);

	void apply(std::function<void(const T &)> fn);
	// the invariant - must be always true for a well-formed List<>
	// the first member function that we write for any non-trivial class
	bool valid() const;
	inline void assert_invariant() const { assert(valid()); }

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
	Node<T> *n = nullptr;
	for (n = head; n != nullptr; n = n->next)
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
	assert_invariant();
	Node<T> *n = find(object);

	if (n != nullptr)
	{
		if (n == head)
		{
			head = n->next;
		}
		else
		{
			if (n == tail)
			{
				tail = n->prev;
			}
			else
			{
				Node<T> *prev_node = n->prev;
				Node<T> *next_node = n->next;
				prev_node->next = n->next;
				next_node->prev = n->prev;
			}
		}
		delete n;
		sz--;
	}

	assert_invariant();
}

template <class T>
void List<T>::remove(Node<T> *n)
{
	assert_invariant();
	if (n != nullptr)
	{
		if (n == head)
		{
			head = n->next;
		}
		else
		{
			if (n == tail)
			{
				tail = n->prev;
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
		sz--;
	}

	assert_invariant();
}

template <class T>
void List<T>::changeValue(const T &object)
{

	assert_invariant();
	Node<T> *n = this->find(object);
	if (n != nullptr)
	{
		n->value = object;
		//this->remove(n);
		//this->insert(object);
	}

	assert_invariant();
}

template <class T>
List<T> *List<T>::filter(std::function<bool(const T &)> fn)
{

	List<T> *novo = new List<T>();
	Node<T> *n = nullptr;

	for (n = head; n != nullptr; n = n->next)
	{
		if (fn(n->value))
		{
			novo->insert(n->value);
		}
	}

	return novo;
}

template <class T>
List<T> *List<T>::slice(int b)
{

	List<T> *l = new List<T>();

	if (empty())
	{
		return l;
	}

	if (b > sz)
	{
		return l;
	}

	Node<T> *n = head;
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
List<T> *List<T>::slice(int b, int e)
{
	List<T> *l = new List<T>();

	if (empty())
	{
		return l;
	}

	Node<T> *n = nullptr;
	int i = 0;
	for (n = head; i < b && n != nullptr; n = n->next)
	{
	}

	int j = e - b;

	for (n; j < e && n != nullptr; n = n->next)
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

#endif /* LIST_H */