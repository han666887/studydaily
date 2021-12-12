#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

template <class K,class T>
class HashNode {
public:
	HashNode(const pair<K,T>& kt) :
		next(nullptr),
		kt(kt)
	{};
	HashNode<K,T>* next;
	pair<K, T> kt;
};

template<class K,class T>
class HashTable {
	typedef HashNode<K,T> Node;
public:
	bool Insert(const pair<K,T>& v) {
		//À©ÈÝ
		if (table.size() == num) {
			vector<Node*> newtable;
			size_t newnum = table.size() == 0 ? 10 : table.size() * 2;
			newtable.resize(newnum);
			for (size_t i=0; i < table.size(); i++) {
				Node* cur = table[i];
				while (cur) {
					Node* next = cur->next;
					size_t newindex = cur->kt.first % newtable.size();
					
					cur->next = newtable[newindex];
					newtable[newindex] = cur;

					cur = next;
				}
				table[i] = nullptr;
			}
			table.swap(newtable);
		}


		//¼ÆËãÎ»ÖÃ
		size_t index = v.first % table.size();
		Node* cur = table[index];
		while (cur) {
			if (cur->kt.first == v.first) {
				return false;
			}
			else {
				cur = cur->next;
			}
		}
		//Í·²å
		Node* newnode = new Node(v);
		newnode->next = table[index];
		table[index] = newnode;
		num++;
		return true;
	}

	bool Erase(const pair<K, T>& kt) {
		size_t index = kt.first % table.size();
		Node* cur = table[index];
		Node* prev = nullptr;
		while (cur) {
			if (cur->kt.first = kt.first) {
				if (prev == nullptr) {
					table[index] = cur->next;
				}
				else {
					prev = cur->next;
				}
				free(cur);
				num--;
				return true;
			}
			else {
				prev = cur;
				cur = cur->next;

			}
		}
		return false;
	}
	K Find(const pair<K, T>& kt) {
		size_t index = kt.first % table.size();
		Node* cur = table[index];
		while (cur) {
			if (cur->kt.first = kt.first) {
				return kt.first;
			}
			else {
				cur = cur->next;
			}
		}
		return 0;
	}
	void Print() {
		for (size_t i = 0; i < table.size(); i++) {
			Node* cur = table[i];
			while (cur) {
				cout << cur->kt.first << " ";
				cur = cur->next;
			}
		}
		cout << endl;
	}
private:
	vector<Node*> table;
	size_t num=0;
};

void Text1() {
	HashTable<int,int> hs;
	int a[] = { 1,2,3,4,5,6,7,8,11,10};
	for (auto e : a) {
		hs.Insert(make_pair(e, e));
	}
	hs.Print();
	hs.Erase(make_pair(2, 2));
	hs.Print();
	hs.Find(make_pair(2, 2));
    hs.Find(make_pair(3, 3));
	hs.Print();
}