#include <Solution.h>
#include <iostream>
#include <string>

using std::string;
using std::to_string;
using std::cout;
using std::endl;

bool compare(string lhs, string rhs) {
	if (lhs == rhs) return true;
	int ls = lhs.size();
	int rs = rhs.size();
	if (ls != rs) {
		int diffSize = abs(ls - rs);
		if (ls < rs) {
			lhs = string(diffSize, '0') + lhs;
		} else {
			rhs = string(diffSize, '0') + rhs;
		}
	}

	int cnt = 0;
	vector<int> lv(10, 0), rv(10, 0);
	for (int i = 0 ; i < lhs.size() ; ++i) {
		if (lhs[i] == rhs[i]) continue;
		++lv[lhs[i]-'0'];
		++rv[rhs[i]-'0'];
		++cnt;
	}
	if (cnt != 2) return false;
	for (int i = 0 ; i < 10 ; ++i) {
		if (lv[i] != rv[i]) return false;
	}
	return true;
}

int Solution::countPairs(vector<int>& nums) {
	vector<string> numToStr;
	int result = 0;
	for (const auto& v : nums) numToStr.push_back(to_string(v));
	for (int i = 0 ; i < nums.size() - 1 ; ++i) {
		for (int j = i + 1 ; j < nums.size() ; ++j) {
			if (compare(numToStr[i], numToStr[j])) {
				++result;
			}
		}
	}
	return result;
}
