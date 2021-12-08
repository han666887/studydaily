#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


enum Colour {
	RED,
	BLACK,
};

template <class k, class v>
class RBTreeNode {
public:
	RBTreeNode(const pair<k,v>& kv)
		:left(nullptr),
		right(nullptr),
		parent(nullptr),
		col(RED),
		kv(kv)
	{}
	RBTreeNode<k, v>* left;
	RBTreeNode<k, v>* right;
	RBTreeNode<k, v>* parent;
	enum Colour col;
	pair<k, v> kv;
};

template <class k,class v>
class RBTree {
	typedef RBTreeNode<k, v> Node;
public:
	//����
	void RotateL(Node* parent) {
		Node* pparent = parent->parent;
		Node* subr = parent->right;
		Node* subrl = subr->left;
		parent->right = subrl;
		if (subrl != nullptr) {
			subrl->parent = parent;
		}
		parent->parent = subr;
		subr->left = parent;

		subr->parent = pparent;
		if (pparent != nullptr) {
			if (pparent->left == parent) {
				pparent->left = subr;
			}
			else {
				pparent->right = subr;
			}
		}
		else {
			root = subr;
		}
	}
	//�ҵ���
	void RotateR(Node* parent) {
		Node* pparent = parent->parent;
		Node* subl = parent->left;
		Node* sublr = subl->right;
		parent->left = sublr;
		if (sublr != nullptr) {
			sublr->parent = parent;
		}
		parent->parent = subl;
		subl->right = parent;
		subl->parent = pparent;
		if (pparent != nullptr) {
			if (pparent->left == parent) {
				pparent->left = subl;
			}
			else {
				pparent->right = subl;
			}
		}
		else {
			root = subl;
		}
	}

	//����
	bool Insert(const pair<k, v>& kv) {
		if (root == nullptr) {
			root = new Node(kv);
			root->col = BLACK;
			return true;
		}
		else {
			Node* pparent = nullptr;
			Node* cur = root;
			//�Ҳ���λ��
			while (cur) {
				if (kv.first < cur->kv.first) {
					pparent = cur;
					cur = cur->left;
				}
				else if (kv.first > cur->kv.first) {
					pparent = cur;
					cur = cur->right;
				}
				else {
					return false;
				}
			}
			//�ҵ��˽�����ϵ
			cur = new Node(kv);
			if (kv.first < pparent->kv.first) {
				pparent->left = cur;
				cur->parent = pparent;
			}
			else {
				pparent->right = cur;
				cur->parent = pparent;
			}
			//������ɫ
			while (pparent&&pparent->col == RED) {
				Node* grandfather = pparent->parent;
				//���������
				if (pparent == grandfather->left) {
					Node* uncle = grandfather->right;
					if (uncle && uncle->col == RED) {
						pparent->col = BLACK;
						uncle->col = BLACK;
						grandfather->col = RED;

						//�����ϴ���
						cur = grandfather;
						pparent = cur->parent;
						if (cur == root) {
							cur->col = BLACK;
						}
					}
					else {
						//˫���䵥��
						if (cur == pparent->right) {
							RotateL(pparent);
							swap(pparent, cur);
						}

						RotateR(grandfather);
						cur->col = BLACK;
						grandfather->col = RED;
						break;
					}
				}
				//�ұ�
				else {
					Node* uncle = grandfather->left;
					//����ڵ㴿�ڲ�Ϊ��ɫ
					if (uncle && uncle->col == RED) {
						pparent->col = BLACK;
						uncle->col = BLACK;
						grandfather->col = RED;

						//�����ϴ���
						cur = grandfather;
						pparent = cur->parent;
						if (cur == root) {
							cur->col = BLACK;
						}
					}
					else {
						//˫���䵥��
						if (cur == pparent->left) {
							RotateR(pparent);
							swap(pparent, cur);
						}

						RotateL(grandfather);
						cur->col = BLACK;
						grandfather->col = RED;
						break;
					}
				}
			}
			if (cur->parent == nullptr) {
				cur->col = BLACK;
			}
			return true;
		}
	}

	void _Inorder(Node* root) {
		if (root == nullptr) {
			return;
		}
		_Inorder(root->left);
		cout << root->kv.first << ":" << root->kv.second << endl;
		_Inorder(root->right);
	}

	void Print() {
		_Inorder(root);
	}
private:
	Node* root = nullptr;
};

void Test() {
	int a[] = { 16,3,7,11,9,26,18,14,15 };
	RBTree<int, int> t;
	for (auto e : a) {
		t.Insert(make_pair(e, e));
	}
	t.Print();
}