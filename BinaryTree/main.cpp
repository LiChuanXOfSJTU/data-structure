#include<iostream>
#include"BinaryTree.h"
#include"Queue.h"
using namespace std;
template<class T>
int BinaryTree<T>::height(Node *t) const
{
	if (t == NULL)
		return 0;
	else
	{
		int lt = height(t->left);
		int rt = height(t->right);
		return 1 + ((lt > rt) ? lt : rt);
	}
}

template<class T>
void BinaryTree<T>::clear(Node *t)
{
	if (t->left != NULL)
		clear(t->left);
	if (t->right != NULL)
		clear(t->right);
	delete t;
}

template<class T>
int BinaryTree<T>::size(Node *t)const
{
	if (t == NULL)
		return 0;
	else
		return 1 + size(t->right) + size(t->left);

}

template<class T>
void BinaryTree<T>::preOrder(Node *t)const
{
	if (t != NULL)
	{
		cout << t->data << " ";
		preOrder(t->left);
		preOrder(t->right);
	}
}

template<class T>
void BinaryTree<T>::postOrder(Node *t)const
{
	if (t != NULL)
	{
		postOrder(t->left);
		postOrder(t->right);
		cout << t->data << " ";

	}
}

template<class T>
void BinaryTree<T>::midOrder(Node *t)const
{
	if (t != NULL)
	{
		midOrder(t->left);
		cout << t->data << " ";
		midOrder(t->right);
	}
}

template<class T>
void BinaryTree<T>::createTree(T flag)
{
	linkQueue<Node *> que;
	Node *tmp;
	T x, ldata, rdata;

	cout << "\nplease input the root:";
	cin >> x;
	root = new Node(x);
	que.enQueue(root);

	while (!que.isEmpty())
	{
		tmp = que.deQueue();
		cout << "\nplease input" << tmp->data << "two sons(" << flag << "represent the empty node):";
		cin >> ldata>> rdata;
		if (ldata != flag)
		{
			tmp->left = new Node(ldata);
			que.enQueue(tmp->left);
		}
		if (rdata != flag)
		{
			tmp->right = new Node(rdata);
			que.enQueue(tmp->right);
		}
	}
	cout << endl;
	cout << "creat finished" << endl;


}

template<class T>
void BinaryTree<T>::swap(Node *t)
{
	if (t->left)
		swap(t->left);
	if (t->right)
		swap(t->right);
	
	Node *tmp;
	tmp = t->left;
	t -> left = t->right;
	t->right = tmp;

}

template<class T>
bool BinaryTree<T>::isCompleteTree()
{
	if (root == NULL)
		return false;
	linkQueue<Node *> q;
	Node *cur;
	q.enQueue(root);
	while (!q.isEmpty())
	{
		cur = q.deQueue();
		if (cur->left&&cur->right)
		{
			q.enQueue(cur->left);
			q.enQueue(cur->right);
		}
		if (cur->left == NULL && cur->right)
		{
			return false;
		}
		if ((cur->left&&cur->right == NULL) || (cur->left == NULL && cur->right == NULL))
		{
			
			while (!q.isEmpty())
			{
				cur = q.deQueue();
				if (cur->left == NULL && cur->right == NULL)
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			return true;
		}

	}
	return true;
}



int main()
{
	BinaryTree<char> tree;
	tree.createTree('@');
	cout << "the height of tree is " << tree.height() << endl;
	cout << "the size of tree is " << tree.size() << endl;
	tree.midOrder();
	tree.preOrder();
	tree.postOrder();
	tree.swap();//½»»»×óÓÒ×ÓÊ÷
	tree.midOrder();
	if (tree.isCompleteTree())
		cout << "complete tree" << endl;
	else
		cout << "not complete tree" << endl;
	system("pause");
	return 0;

}