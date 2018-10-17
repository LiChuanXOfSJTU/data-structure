#include<iostream>
using namespace std;
template<class T>
class queue
{
public:
	virtual bool isEmpty() = 0;
	virtual void enQueue(const T &x) = 0;
	virtual T deQueue() = 0;
	virtual T getHead() = 0;
	virtual ~ queue() {}

};

template<class T>
class linkQueue :public queue<T>
{
private:
	struct node
	{
		T data;
		node *next;
		node (const T &x, node *p = NULL)
		{
			data = x;
			next = p;
		}
		node ():next(NULL){}
		~node (){}

	};
	node *front;
	node *rear;
public:
	linkQueue() { front = NULL; rear = NULL; }
	~linkQueue();
	bool isEmpty() { return front == NULL; }
	void enQueue(const T &x);
	T deQueue();
	T getHead() { return front->data; }

};

template<class T>
linkQueue<T>::~linkQueue()
{
	node *tmp;
	while (front != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}

}

template<class T>
void linkQueue<T>::enQueue(const T &x)
{
	if (rear == NULL)
		front = rear = new node(x);
	else
	{
		rear->next = new node(x);
		rear = rear->next;
	}

}

template<class T>
T linkQueue<T>::deQueue()
{
	node *tmp = front;
	T value = front->data;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	delete tmp;
	return value;
}