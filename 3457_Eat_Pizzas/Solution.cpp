#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

long long Solution::maxWeight(vector<int>& pizzas) {
	int size = pizzas.size() / 4;
	int odd = size / 2 + (size & 1);
	int even = size / 2;

	sort(pizzas.begin(), pizzas.end(), std::greater<int>());

	int idx = 0;
	long long result = 0;
	for (int i = 0 ; i < odd ; ++i) {
		result += pizzas[idx++];
	}
	for (int i = 0 ; i < even ; ++i) {
		++idx;
		result += pizzas[idx++];
	}
	return result;

}
