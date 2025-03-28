#include <data_type.h>
#include <map>
#include <unordered_map>
#include <unordered_set>

using std::map;
using std::unordered_map;
using std::unordered_set;

class StockPrice {
public:
	StockPrice() {
		curT = -1;
		curP = 0;
	}

	void update(int timestamp, int price) {
		if (tTop.count(timestamp)) {
			int oriPrice = tTop[timestamp];
			pTot[oriPrice].erase(timestamp);
			if (pTot[oriPrice].empty())
				pTot.erase(oriPrice);
		}
		tTop[timestamp] = price;
		pTot[price].emplace(timestamp);
		if (timestamp >= curT) {
			curT = timestamp;
			curP = price;
		}
	}

	int current() {
		return curP;
	}

	int maximum() {
		auto iter = pTot.rbegin();
		return iter->first;
	}

	int minimum() {
		auto iter = pTot.begin();
		return iter->first;
	}

private:
	int curT;
	int curP;
	unordered_map<int, int> tTop;
	map<int, unordered_set<int>> pTot;
	virtual ~StockPrice() {
	}
	StockPrice &operator=(const StockPrice &source);
	StockPrice(const StockPrice &);
};
