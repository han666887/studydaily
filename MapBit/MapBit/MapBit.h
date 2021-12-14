#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//λͼ
class MapBit {
public:
	MapBit(size_t key) {
		size_t len = key % 32 + 1;
		table.resize(len, 0);
		num = 0;
	}
	void Set(size_t key) {

		size_t a = key / 32;
		size_t b = key % 32;
		int bit = (int)pow(2, b);

		table[a] |=bit;
		num++;
	}
	void Remove(size_t key) {
		size_t a = key / 32;
		size_t b = key % 32;
		int bit = (int)pow(2, b);

		table[a] ^= bit;
	}
	int Find(size_t key) {
		size_t a = key / 32;
		size_t b = key % 32;
		int bit = (int)pow(2, b);

		int re=table[a] & bit;
		if (re == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
private:
	vector<int> table;
	size_t     num;
};

//void Text1() {
//	MapBit mb(100);
//	mb.Set(1);
//	mb.Set(0);
//	mb.Set(11);
//	mb.Set(100);
//	for (size_t i = 0; i <= 100; i++) {
//		printf("[%d]:%d\n", i, mb.Find(i));
//	}
//}