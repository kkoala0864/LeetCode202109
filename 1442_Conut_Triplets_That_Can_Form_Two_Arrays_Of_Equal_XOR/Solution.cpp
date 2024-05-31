#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

int Solution::countTriplets(vector<int>& arr) {
	int size = arr.size();
	unordered_map<int, int> pm;
	vector<int> pre(size, 0), post(size, 0);
	int result = 0;
	int v = 0;
	for (int i = size - 1 ; i > 0 ; --i) {
		v ^= arr[i];
		post[i] = v;
		++pm[v];
	}

	v = 0;
	for (int i = 0 ; i < size - 1 ; ++i) {
		v ^= arr[i];
		pre[i] = v;
		--pm[post[i+1]];
		for (int j = 0 ; j <= i ; ++j) {
			int target = v;
			if (j > 0) {
				target ^= pre[j-1];
			}
			if (target == post[i+1]) {
				++result;
			}
			target ^= post[i+1];
			result += pm[target];
		}
	}
	return result;
}
