#include <data_type.h>
#include <iostream>
#include <random>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
public:
	RandomizedCollection() {

	}

	bool insert(int val) {
		bool ret = ums.count(val) == 0;
		ums.emplace(val);
		return ret;
	}

	bool remove(int val) {
		bool ret = ums.count(val) > 0;
		if (!ret) return ret;
		auto iter = ums.find(val);
		ums.erase(iter);
		return ret;
	}

	int getRandom() {
		int size = ums.size();

		random_device rd;
		std::mt19937 gen(rd());
		uniform_int_distribution<> id(1, size);
		int idx = id(gen) - 1;
		auto iter = ums.begin();
		advance(iter, idx);
		return *iter;
	}

private:
	unordered_multiset<int> ums;
	virtual ~RandomizedCollection() {
	}
	RandomizedCollection &operator=(const RandomizedCollection &source);
	RandomizedCollection(const RandomizedCollection &);
};
