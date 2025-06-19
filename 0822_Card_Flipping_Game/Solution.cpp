#include <Solution.h>

int Solution::flipgame(vector<int>& fronts, vector<int>& backs) {
	unordered_set<int> alwaysExist;
	int size = fronts.size();
	for (int i = 0 ; i < size ; ++i) {
		if (fronts[i] == backs[i]) alwaysExist.emplace(fronts[i]);
	}

	int result = INT_MAX;
	for (int i = 0 ; i < size ; ++i) {
		if (alwaysExist.count(fronts[i]) == 0) {
			result = min(result, fronts[i]);
		}
		if (alwaysExist.count(backs[i]) == 0) {
			result = min(result, backs[i]);
		}
	}
	return result == INT_MAX ? 0 : result;

}
