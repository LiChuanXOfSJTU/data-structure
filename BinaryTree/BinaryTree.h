#include<iostream>
using namespace std;
template <class T>
class BinaryTree 
{
private:
	struct Node 
	{  //二叉树的结点类，用来存储和处理树上每一个结点。这个结点类是树类专用的，因此可作为树类的私有内嵌类
		Node *left, *right; // 结点的左、右儿子的地址 
		T data; // 结点的数据信息 
		Node() : left(NULL), right(NULL) { }
		Node(T item, Node *L = NULL, Node * R = NULL) :
			data(item), left(L), right(R) {}
		~Node() {}
    };
	Node *root; // 二叉树的根结点
public:
	BinaryTree() : root(NULL) {} // 构造空二叉树 
	BinaryTree(const T & value)
	{
		root = new Node(value);
	} // 构造只有一个结点的二叉树 
	~BinaryTree() { clear(); }
	T getRoot() const
	{
		return root->data;
	} // 获取根结点的值
	T getLeft() const
	{
		return root->left->data;
	} // 获取左儿子的值
	T getRight() const
	{
		return root->right->data;
	} // 获取右儿子的值

	void makeTree(const T &x, BinaryTree &lt, BinaryTree &rt) //构造以x为根结点，lt和rt为左右子树的二叉树
	{
		root = new Node(x, lt.root, rt.root);
		lt.root = NULL; rt.root = NULL;
	}
	void delLeft() //对左子树调用clear函数删除 左子树，然后将结点x的left置为NULL
	{
		BinaryTree tmp = root->left;
		root->left = NULL; tmp.clear();
	}
	void delRight() //对右子树调用clear函数删除右子树，然后将结点x的right置为NULL
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
			cout << "\n前序遍历："; 
			preOrder(root);
		}
	}

	void postOrder() const
	
	{
		if (root != NULL) {
			cout << "\n后序遍历：";
			postOrder(root);
		}
	}

	void midOrder() const
	{
		if (root != NULL) {
			cout << "\n中序遍历：";
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



