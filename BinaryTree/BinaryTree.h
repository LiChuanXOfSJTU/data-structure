#include<iostream>
using namespace std;
template <class T>
class BinaryTree 
{
private:
	struct Node 
	{  //�������Ľ���࣬�����洢�ʹ�������ÿһ����㡣��������������ר�õģ���˿���Ϊ�����˽����Ƕ��
		Node *left, *right; // �������Ҷ��ӵĵ�ַ 
		T data; // ����������Ϣ 
		Node() : left(NULL), right(NULL) { }
		Node(T item, Node *L = NULL, Node * R = NULL) :
			data(item), left(L), right(R) {}
		~Node() {}
    };
	Node *root; // �������ĸ����
public:
	BinaryTree() : root(NULL) {} // ����ն����� 
	BinaryTree(const T & value)
	{
		root = new Node(value);
	} // ����ֻ��һ�����Ķ����� 
	~BinaryTree() { clear(); }
	T getRoot() const
	{
		return root->data;
	} // ��ȡ������ֵ
	T getLeft() const
	{
		return root->left->data;
	} // ��ȡ����ӵ�ֵ
	T getRight() const
	{
		return root->right->data;
	} // ��ȡ�Ҷ��ӵ�ֵ

	void makeTree(const T &x, BinaryTree &lt, BinaryTree &rt) //������xΪ����㣬lt��rtΪ���������Ķ�����
	{
		root = new Node(x, lt.root, rt.root);
		lt.root = NULL; rt.root = NULL;
	}
	void delLeft() //������������clear����ɾ�� ��������Ȼ�󽫽��x��left��ΪNULL
	{
		BinaryTree tmp = root->left;
		root->left = NULL; tmp.clear();
	}
	void delRight() //������������clear����ɾ����������Ȼ�󽫽��x��right��ΪNULL
	{
		BinaryTree tmp = root->right;
		root->right = NULL; tmp.clear();
	}
	bool isEmpty() const
	{
		return root == NULL;
	}
	void clear()
	{
		if (root != NULL) 
			clear(root); 
		root = NULL;
	}
	int size() const { return size(root); }
	int height() const { return height(root); }
	void preOrder() const
	{
		if (root != NULL) {
			cout << "\nǰ�������"; 
			preOrder(root);
		}
	}

	void postOrder() const
	
	{
		if (root != NULL) {
			cout << "\n���������";
			postOrder(root);
		}
	}

	void midOrder() const
	{
		if (root != NULL) {
			cout << "\n���������";
			midOrder(root);
		}
	}
	
	void createTree(T flag);
	void swap()
	{
		swap(root);
	}

	bool isCompleteTree();

private:
	void clear(Node *t);
	int height(Node *t) const;
	int size(Node *t) const;
	void preOrder(Node *t) const;
	void postOrder(Node *t) const;
	void midOrder(Node *t) const;
	void swap(Node *t);
};



