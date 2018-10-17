#include <iostream>
#include "list.h"
using namespace std;





template <class elemType>
class linklist :public list<elemType> {
private:
	struct node {
		elemType data;
		node *next;
		node() :next(NULL) {}
		node(const elemType &x,node *p=NULL)
		{
			data = x; next = p;
		}
		~ node(){}
	};
	node *head;//ͷָ��
	int currentLength;
protected:

	node *get(int i) const
	{
		if (i < 0)
			return head;
			

		node *p = head->next;
		int j;
		for (j = 0; j < i; j++) p = p->next;
		return p;

	}//��õ�i��λ�ýڵ�ָ��
public:
	linklist();//���캯��
	~linklist() { clear(); delete head; }//�����������������ɾ��ͷ���

	void clear();
	int length() const { return currentLength; }//���ص�ǰ����
	void insert(int i, const elemType &x);//����Ԫ��
	void remove(int i);//ɾ����i��λ�õĽڵ�
	int search(const elemType &x)const;//����Ԫ�أ���������λ��
	elemType visit(int i) const;//���ʵ�i��Ԫ�أ�������Ԫ��ֵ
	void traverse()const;//��������
	void erase(int x, int y);//ɾ����������ֵ��[x,y]�Ľڵ�
	void inverse();//��������
};


template<class elemType>
linklist<elemType>::linklist()
{
	head = new node;
    currentLength = 0;

}

template<class elemType>
 void linklist<elemType>::clear()
{   
	node *p = head->next;
	node *q;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	head->next = NULL;
	currentLength = 0;


}
 
 template<class elemType>
 void linklist<elemType>::remove(int i)
 {
	 node *p;
	 node *q;
	 p = get(i - 1);
	 q = p->next;
	 p->next = q->next;
	 delete q;
	 currentLength--;


  }
 
 template<class elemType>
 void linklist<elemType>::insert(int i, const elemType &x)
 {
	 node *p = get(i - 1);
	 node *q;
	 q = new node(x);
	 q->next = p->next;
	 p->next = q;
	 ++currentLength;
 }
 
 template<class elemType>
 int linklist<elemType>::search(const elemType &x)const
 {
	 node *p = head->next;
	 int i = 0;
	 while (p != NULL&&p->data!=x)
	 {
		 p = p->next;
		 i++;
	 }
	 if (p == NULL)
		 return -1;
	 else
		 return i;

	 

 }

 template<class elemType>
 elemType linklist<elemType>::visit(int i) const
 {
	 node *p = get(i);
	 return p->data;
 }

 template<class elemType>
 void linklist<elemType>::traverse()const
 {
	 node *p = head->next;
	 while (p != NULL)
	 {
		 cout << p->data << " ";
		 p = p->next;
	 }
	 cout << endl;

}

 template<class elemType>
 void linklist<elemType>::erase(int x, int y)
 {
	 
		 node *p = head->next;
		 node *q=head;

		 while (p != NULL)
		 {
			 
			 if (p->data <= y && p->data >= x)
			 {
				 q->next = p->next;
				 delete p;
				 p = NULL;
				 p = q->next;

			 }
			 else
			 {
				 p = p->next;
				 q = q->next;
			 }
		 }
	 
 }
  
 template<class elemType>
 void linklist<elemType>::inverse()
 {
	 node *p = head->next->next;
	 node *q;
	 head->next->next = NULL;//???

	 while (p != NULL)
	 {
		 q = p->next;
		 p->next = head->next;
		 head->next = p;
		 p = q;
	 }

 }

int main() {
	 linklist<int> l;
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
	 l.erase(2, 8);
	 l.traverse();
	 l.inverse();
	 l.traverse();
     system("pause");
	 return 0;
 }
