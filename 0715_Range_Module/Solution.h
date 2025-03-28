#include <data_type.h>
#include <map>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::prev;

class RangeModule {
public:
	RangeModule() {
	}

	void addRange(int left, int right) {
		--right;
		auto iter = m.lower_bound(left);
		if (iter != m.begin()) {
			auto last = prev(iter);
			if (last->second >= (left - 1)) {
				left = last->first;
				right = max(last->second, right);
			}
		}
		auto next = m;
		while (iter != m.end() && right >= (iter->first - 1)) {
			right = max(right, iter->second);
			next.erase(iter->first);
			++iter;
		}
		next[left] = right;
		m = next;
	}

	bool queryRange(int left, int right) {
		--right;
		auto iter = m.lower_bound(left);

		if (iter != m.end() && right >= iter->first) {
			return left >= iter->first && iter->second >= right;
		}

		if (iter == m.begin())
			return false;
		auto last = prev(iter);
		if (last->second >= left) {
			return last->second >= right;
		} else {
			return false;
		}
	}

	void removeRange(int left, int right) {
		--right;
		auto iter = m.lower_bound(left);

		auto next = m;
		if (iter != m.begin()) {
			auto last = prev(iter);
			if (last->second >= left) {
				next[last->first] = left - 1;
				if (last->second > right) {
					next[right + 1] = last->second;
				}
			}
		}
		while (iter != m.end()) {
			if (right < iter->first) {
				break;
			}
			next.erase(iter->first);
			if (right < iter->second) {
				next[right + 1] = iter->second;
			}
			++iter;
		}
		m = next;
	}
	void print() {
		for (const auto &e : m)
			cout << "print : " << e.first << " : " << e.second << endl;
		cout << endl;
	}

private:
	map<int, int> m;
	virtual ~RangeModule() {
	}
	RangeModule &operator=(const RangeModule &source);
	RangeModule(const RangeModule &);
};
