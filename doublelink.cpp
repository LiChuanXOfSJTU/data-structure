#include <iostream>
#include "list.h"
using namespace std;
template <class elemType>
class Dlinklist :public list<elemType> {
private:
	struct node {
		elemType data;
		node *next;
		node *prev;
		node() :next(NULL) ,prev(NULL){}
		node(const elemType &x, node *p = NULL,node *q=NULL)
		{
			data = x; next = p; prev = q;
		}
		~node() {}
	};
	node *head;//头指针
	node *tail;//尾指针
	int currentLength;
protected:

	node * get(int i) const
	{
		if (i < 0)
			return head;


		node *p = head->next;
		int j;
		for (j = 0; j < i; j++) p = p->next;
		return p;

	}//获得第i个位置节点指针
public:
	Dlinklist();//构造函数
	~Dlinklist() { clear(); delete head; delete tail; }//析构函数，清空链表，删除头结点

	void clear();
	int length() const { return currentLength; }//返回当前长度
	void insert(int i, const elemType &x);//插入元素
	void remove(int i);//删除第i个位置的节点
	int search(const elemType &x)const;//查找元素，返回所在位置
	elemType visit(int i) const;//访问第i个元素，并返回元素值
	void traverse()const;//遍历链表


};

template<class elemType>
Dlinklist<elemType>::Dlinklist()
{
	head = new node;
	tail = new node;
	head->next = tail;
	tail->prev = head;
	currentLength = 0;
}
template<class elemType>
void Dlinklist<elemType>::clear()
{
	node  *p = head->next, *q;
	head->next = tail;
	tail->prev = head;
	while (p != tail) {
		q = p->next;
		delete p;   p = q;
	}
	currentLength = 0;

}

template<class elemType>
void Dlinklist<elemType>::insert(int i, const elemType &x)
{
	node *p;
	node *q;
	p = get(i - 1);
	q = new node(x);
	q->prev = p;
	q->next = p->next;
	p->next = q;
	++currentLength;

}
template<class elemType>
void Dlinklist<elemType>::remove(int i)
{
	node *p;
	p = get(i);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	--currentLength;

}
template<class elemType>
 elemType Dlinklist<elemType>:: visit(int i) const
{
	 node *p = get(i);
	 return p->data;
}
 template<class elemType>
 int Dlinklist<elemType>::search(const elemType &x)const
 {
	 node *p = head->next;
	 int i = 0;
	 while (p != tail && p->data != x)
	 {
		 p = p->next; ++i;
	 }
	 if (p == tail) return -1;
	 else return i;
 }
 template<class elemType>
 void Dlinklist<elemType>::traverse()const
 {
	 node *p = head->next;
	 cout << endl;
	 while (p != tail) {
		 cout << p->data << "  ";
		 p = p->next;
	 }
	 cout << endl;

 }

 int main() {
	 Dlinklist<int> l;
	 for (int i = 0; i < 20; ++i)
		 l.insert(i, i);
	 l.traverse();
	 cout << l.visit(10) << endl;
	 if (l.search(10) == -1)
		 cout << "error" << endl;
	 else
		 cout << l.search(10) << endl;
	 l.insert(10, 100);
	 l.traverse();
	 cout << l.visit(10) << endl;
	 l.remove(10);
	 l.traverse();
	 system("pause");
	 return 0;
 }


