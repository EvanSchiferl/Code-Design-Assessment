#pragma once


template<typename T>
class tForwardList 
{
	tForwardList(const tForwardList& other);
	tForwardList& operator= (const tForwardList &rhs);
	bool empty() const;
	void clear();
	void resize(size_t newSize);

	struct Node
	{
		T data;
		Node * next;
	};

	Node * head;

public:
	tForwardList();
	~tForwardList();
	

	void push_front(const T& val);
	void pop_front();

	T& front();
	const T& front() const;

	void remove(const T& val);


	tForwardList& operator= (const tForwardList &rhs)
	{
		Node *tmp = new Node;
		tmp->data = value;
		tmp->next = NULL;
		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
			tmp = NULL;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}

	bool empty() const
	{
		Node *tmp = new Node;
		tmp = head;
		while (tmp != NULL)
		{
			std::cout << tmp->data << "\t";
			tmp = tmp->next;
		}
	}

	void clear()
	{
		
	}

	void resize(size_t newSize)
	{

	}

	tForwardList()
	{

	}

	~tForwardList()
	{

	}

	void push_front(const T& val)
	{
		Node *tmp = new Node();
		tmp->data = next;
		tmp->next = head;
		head = tmp;
	}

	void pop_front()
	{
		Node *tmp = new Node;
		tmp = head;
		head = head->next;
		delete tmp;
	}

	const T& front() const
	{
		return head const;
	}

	void remove(const T& val)
	{
		Node *cur = new Node;
		Node *pre = new Node;
		cur = head;
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		tail = pre;
		pre->next = NULL;
		delete cur;
	}

	T& front()
	{
		return head;
	}


	class const_iterator
	{
		Node * cur;

	public:
		const_iterator();
		const_iterator(Node * startNode);
		const_iterator(const iterator& it);

		bool operator==(const const_iterator& rhs) const;
		bool operator!=(const const_iterator& rhs) const;
		T& operator*() const;
		const_iterator& operator++();
		const_iterator operator++(int);


		const_iterator()
		{

		}

		const_iterator(Node * startNode)
		{

		}

		const_iterator(const iterator& it)
		{

		}

		bool operator==(const const_iterator& rhs) const
		{

		}
		
		bool operator!=(const const_iterator& rhs) const
		{

		}

		T& operator*() const
		{

		}

		const_iterator& operator++()
		{

		}

		const_iterator operator++(int)
		{

		}
	};

	const_iterator cbegin()
	{

	}

	const_iterator cend()
	{

	}

	const_iterator cbegin();
	const_iterator cend();
};

