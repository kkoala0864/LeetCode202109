#include <Solution.h>

int Solution::numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

	vector<bool> visited(baskets.size(), false);
	int cnt = fruits.size();
	for (int fi = 0 ; fi < fruits.size() ; ++fi) {
		int bi = 0;
		for (; bi < baskets.size() ; ++bi) {
			if (visited[bi]) continue;
			if (fruits[fi] <= baskets[bi]) {
				visited[bi] = true;
				break;
			}
		}
		cnt -= (bi != baskets.size());
	}
	return cnt;
}
