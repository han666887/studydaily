#define _CRT_SECURE_NO_WARNINGS
#include "MapBit.h"
#include <string>
//布隆过滤器
//哈希函数
struct HashStr1 {
	//BKDR
	size_t operator()(const string& str) {
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); i++) {
			hash *= 131;//魔术数
			hash += str[i];
		}
		return hash;
	}
};

struct HashStr2 {
	//RsHash
	size_t operator()(const string& str) {
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); i++) {
			hash *= 63689;//魔术数
			hash += str[i];
		}
		return hash;
	}
};
struct HashStr3 {
	//SDBMHash
	size_t operator()(const string& str) {
		size_t hash = 0;
		for (size_t i = 0; i < str.size(); i++) {
			hash *= 65599;//魔术数
			hash += str[i];
		}
		return hash;
	}
};


template <class K = string,class Hash1= HashStr1, class Hash2= HashStr2, class Hash3= HashStr3>
class BloomFilter {
public:

	BloomFilter(size_t num) :
		mp(5*num),
		n(5*num){}
	void Set(const K& key) {
		//三个Bit位表示一个字符串
		size_t index1 = Hash1()(key)%n;
		size_t index2 = Hash2()(key)%n;
		size_t index3 = Hash3()(key)%n;
		//位图更改对应bit位
		mp.Set(index1);
		mp.Set(index2);
		mp.Set(index3);

	}
	int Find(const K& key) {

		size_t index1 = Hash1()(key)%n;
		if (mp.Find(index1) == 0) {
			return 0;
		}
		size_t index2 = Hash2()(key)%n;
		if (mp.Find(index2) == 0) {
			return 0;
		}
		size_t index3 = Hash3()(key)%n;
		if (mp.Find(index3) == 0) {
			return 0;
		}
		return 1;
	}
private:
	MapBit mp;
	size_t n;
};

void Text2() {
	BloomFilter<string> bf(100);
	bf.Set("abcd");
	bf.Set("bcde");
	bf.Set("sbcg");

	cout<<bf.Find("abcd")<<endl;
	cout<<bf.Find("bcde")<<endl;
	cout<<bf.Find("sbcg")<<endl;
}