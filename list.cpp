#include <iostream>
#include "LIST.h"
using namespace std;

class OutOfBound {};
class IllegalSize {};


template <class elemType>
class seqList :public list<elemType> {
private:
	elemType * data;
	int currentLength;
	int maxSize;
	void doubleSpace();
public:
	seqList(int initSize = 10);//构造函数，带默认参数的
	void clear() { currentLength = 0; }//比较简单，将长度置为0
	int length()const { return currentLength; }
	void insert(int i, const elemType &x);
	void remove(int i);
	int search(const elemType &x)const;
	elemType visit(int i)const;
	void traverse()const;
	~seqList() { delete[]data; }
	 
	seqList<elemType> operator +(const seqList<elemType> &a);
	
    seqList<elemType> & operator = (const seqList<elemType> &other);
    // 复制构造函数
	seqList(const seqList<elemType> &c);
	
};

template<class elemType>
void seqList<elemType>::doubleSpace() {
	elemType *tmp = data;
	data = new elemType[maxSize * 2];
	maxSize *= 2;
	for (int i = 0; i < maxSize; ++i)
		data[i] = tmp[i];
	delete[]tmp;
}

template<class elemType>
seqList<elemType>::seqList(int initSize) {
	if (initSize <= 0)
		throw IllegalSize();
	data = new elemType[initSize];
	maxSize = initSize;
	currentLength = 0;
}
template<class elemType>
seqList<elemType>::seqList(const seqList<elemType> &c)
{
	currentLength = c.currentLength;
	maxSize = c.maxSize;
	data = new elemType[maxSize];
	for (int i = 0; i < currentLength; i++)
		data[i] = c.data[i];
}


template<class elemType>
void seqList<elemType>::insert(int i, const elemType &x) {
	if (i > currentLength || i < 0)
		throw OutOfBound();
	if (maxSize == currentLength)
		doubleSpace();
	for (int j = currentLength; j > i; j--)
		data[j] = data[j - 1];
	data[i] = x;
	currentLength++;
}

template<class elemType>
void seqList<elemType>::remove(int i) {
	if (i < 0 || i >= currentLength)
		throw OutOfBound();
	for (int j = i; j < currentLength - 1; ++j)
		data[j] = data[j + 1];
	currentLength--;
}

template<class elemType>
int seqList<elemType>::search(const elemType &x)const {
	for (int i = 0; i < currentLength; ++i)
		if (data[i] == x)
			return i;
	return -1;
}

template<class elemType>
elemType seqList<elemType>::visit(int i)const {
	if (i > currentLength - 1 || i < 0)
		throw OutOfBound();
	return data[i];
}

template<class elemType>
void seqList<elemType>::traverse()const {
	for (int i = 0; i < currentLength; ++i)
		cout << data[i] <<" ";
	cout << endl;
}



template<class elemType>
seqList<elemType>& seqList<elemType>:: operator =(const seqList<elemType> &other)
{
	if (this == &other) return *this;
	delete[]data;

	currentLength = other.currentLength;
	maxSize = other.maxSize;
	data = new elemType[maxSize];
	for (int i = 0; i < currentLength; ++i)
		data[i] = other.data[i];
	return *this;
}
template<class elemType>
seqList<elemType> seqList<elemType>::operator +(const seqList<elemType> &a)
{

	seqList<elemType> c(a.length() +length());

	int i, j;
	for (i = 0; i < a.currentLength; i++)
	{
		c.data[i] = a.data[i];

	}
	for (j = 0; j < currentLength; j++)
	{
		c.data[i++] = data[j];
	}
	c.currentLength = i;
	return c;
}

int main() {
	seqList<int> l;
	for (int i = 0; i < 20; ++i)
		l.insert(i, i);
	l.traverse();
	cout << l.visit(10) << endl;
	cout << l.search(10) << endl;
	l.insert(10, 100);
	l.traverse();
	cout << l.visit(10) << endl;
	l.remove(10);
	l.traverse();
	seqList<int> m;
	m = l;
	m.traverse();
	seqList<int> SUM;
	SUM = m + l;
	SUM.traverse();
	//SUM.traverse();
	system("pause");
	return 0;
}

