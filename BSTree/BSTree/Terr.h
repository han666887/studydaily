#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <class T,class V>
struct TreeNode {
	T key;
	V value;
	TreeNode<T,V>* left;
	TreeNode<T,V>* right;

	TreeNode(const T& key,const V& value)
	:key(key),
	value(value),
	left(nullptr),
	right(nullptr)
	{}

};

template <class T,class V>
class BSTree {
	typedef TreeNode<T,V> node;
public:
	//����
	bool Insert(const T& key,const V& value) {
		if (root == nullptr) {
			node* cur = new node(key,value);
			root = cur;
			return true;
		}
		else {
			node* parent = nullptr;
			node* cur = root;
			while (cur) {
				if (key > cur->key) {
					parent = cur;
					cur = cur->right;
				}
				else if (key < cur->key) {
					parent = cur;
					cur = cur->left;
				}
				else {
					return false;
				}
			}
			cur = new node(key,value);
			if (cur->key > parent->key) {
				parent->right = cur;
			}
			else {
				parent->left = cur;
			}
			return true;
		}
	}


	//Ѱ��
	node* Find(const T& key) {
		node* cur = root;
		while (cur) {
			if (key > cur->key) {
				cur = cur->right;
			}
			else if (key < cur->key) {
				cur = cur->left;
			}
			else {
				return cur;
			}
		}
		return nullptr;
	}

	//ɾ��
	bool Erase(const T& key) {
		node* parent = root;
		node* cur = root;
		while (cur) {
			if (key > cur->key) {
				parent = cur;
				cur = cur->right;
			}
			else if (key < cur->key) {
				parent = cur;
				cur = cur->left;
			}
			else {
				//�ҵ��ˣ�ɾ��
				//����Ϊ��
				if (cur->left == nullptr) {
					if (cur==root) {
						root = cur->right;
					}
					else {
						if (parent->left == cur) {
							parent->left = cur->right;
						}
						else {
							parent->right = cur->right;
						}
						delete cur;
						return true;
					}
				}
				//�Һ���Ϊ��
				else if (cur->right == nullptr) {
					if (cur==root) {
						root = cur->left;
					}
					else {
						if (parent->left == cur) {
							parent->left = cur->left;
						}
						else {
							parent->right = cur->left;
						}
						delete cur;
						return true;
					}
					
				}
				//���Ҷ���Ϊ��
				else {
					node* rightminparent = cur;
					node* rightmin = cur->right;
					while (rightmin->left) {      //���ұ���Сֵ�滻Ҫɾ���Ľڵ㣬Ȼ��ɾ����С�ڵ㡣
						rightminparent = rightmin;
						rightmin = rightmin->left;
					}

					cur->key = rightmin->key;
					if (rightminparent->left == rightmin) {
						rightminparent->left = rightmin->right;
					}
					else {
						rightminparent->right = rightmin->right;
					}
					delete rightmin;
					return true;
				}
			}

		}
		return false;
	}
	
	//ǰ�����
	void _InOrder(node* root) {
		if (root == nullptr) {
			return;
		}
		else {
			cout << root->key << ":"<<root->value<<endl;
			_InOrder(root->left);
			
			_InOrder(root->right);
		}
	}
	void InOrder() {
		_InOrder(root);
	}
private:
	node* root = nullptr;
};

void Text() {
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	/*BSTree<int> bst;
	for (auto e : a) {
		bst.Insert(e);
	}
	bst.InOrder();*/

	/*bst.Erase(5);
	bst.InOrder();

	bst.Erase(3);
	bst.InOrder();

	bst.Erase(4);
	bst.InOrder();

	bst.Erase(1);
	bst.InOrder();

	bst.Erase(7);
	bst.InOrder();

	bst.Erase(8);
	bst.InOrder();

	bst.Erase(2);
	bst.InOrder();

	bst.Erase(6);
	bst.InOrder();

	bst.Erase(0);
	bst.InOrder();

	bst.Erase(9);
	bst.InOrder();*/


	/*for (auto e : a) {
		bst.Erase(e);
		bst.InOrder();
	}*/

	//�ֵ�ʱ�临�Ӷ�Ϊlogn
	/*BSTree<string, string> bst;
	bst.Insert("sort", "����");
	bst.Insert("string", "�ַ���");
	bst.Insert("love", "ϲ��");
	bst.Insert("tree", "��");
	bst.Insert("insert", "����");

	string str;
	while (cin >> str) {
		if (bst.Find(str) != nullptr) {
			cout << bst.Find(str)->value<<endl;
		}
		else {
			cout << "�޴˵���" << endl;
		}
	}*/

	//ͳ�ƴ�Ƶ
	string strArr[] = { "����","����", "�㽶", "����", "ƻ��", "����", "����", "ƻ��", "����", 
		"�㽶", "����", "����", "����", "ƻ��", "����", "���ܹ�", "����", "����", "����" };
	BSTree<string, int> countTree;

	for (auto str : strArr) {
		TreeNode<string, int>* node = countTree.Find(str);
		if (node == nullptr) {
			countTree.Insert(str, 1);
		}
		else {
			node->value++;
		}
	}
	countTree.InOrder();
}