#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::map;
using std::sort;

bool Solution::isNStraightHand(vector<int> &hand, int groupSize) {
	if (hand.size() % groupSize)
		return false;
	map<int, int> m;
	for (const auto &v : hand)
		++m[v];

	int size = hand.size() / groupSize;

	for (int i = 0; i < size; ++i) {
		int v = m.begin()->first;

		for (int j = 0; j < groupSize; ++j) {
			int tv = v + j;
			if (m.count(tv) == 0)
				return false;
			--m[tv];
			if (m[tv] == 0)
				m.erase(tv);
		}
	}
	return true;
}
