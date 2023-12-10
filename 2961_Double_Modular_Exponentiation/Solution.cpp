#include <Solution.h>
#include <iostream>

bool check(const vector<int>& v, int target) {
	int val = v[0] % 10;

	int tmp = 1;
	for (int i = 0 ; i < v[1] ; ++i) {
		tmp *= val;
		tmp %= 10;
	}

	val = tmp;
	tmp = 1;
	for (int i = 0 ; i < v[2] ; ++i) {
		tmp *= val;
		tmp %= v[3];
	}
	return tmp == target;
}

vector<int> Solution::getGoodIndices(vector<vector<int>>& variables, int target) {
	vector<int> result;
	for (int i = 0 ; i < variables.size() ; ++i) {
		if (check(variables[i], target)) result.emplace_back(i);
	}
	return result;
}
