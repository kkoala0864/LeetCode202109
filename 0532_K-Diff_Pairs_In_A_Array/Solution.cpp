#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

int Solution::findPairs(vector<int>& nums, int k) {
	unordered_map<int, vector<int>> map;

	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) map[nums[i]].emplace_back(i);

	for (const auto & iter : map) {
		if (map.find(iter.first + k) != map.end()) {
			if (iter.second[0] < map[iter.first+k].back()) ++result;
			else if (iter.second.back() > map[iter.first+k][0]) ++result;
		}
	}
	return result;

}
