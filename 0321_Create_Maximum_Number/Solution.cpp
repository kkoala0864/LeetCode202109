#include <Solution.h>
#include <iostream>
#include <string>
#include <algorithm>

using std::max;
using std::string;
using std::cout;
using std::endl;

string findMax(vector<int>& nums, int k) {
	int drop = nums.size() - k;

	string ret;
	for (const auto& v : nums) {
		while (!ret.empty() && drop > 0 && (ret.back()-'0') < v) {
			ret.pop_back();
			--drop;
		}
		ret.push_back('0' + v);
	}
	while (drop-- && !ret.empty()) {
		ret.pop_back();
	}
	return ret;
}

string merge(string& s1, string& s2) {
	string s;
	int size = s1.size() + s2.size();

	for (int i = 0 ; i < size ; ++i) {
		if (s1 > s2) {
			s.push_back(*(s1.begin()));
			s1.erase(s1.begin());
		} else {
			s.push_back(*(s2.begin()));
			s2.erase(s2.begin());
		}
	}
	return s;
}

vector<int> Solution::maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	string maxStr;
	for (int i = 0 ; i <= k ; ++i) {
		if (i > nums1.size()) continue;
		if ((k-i) > nums2.size()) continue;

		string s1 = findMax(nums1, i);
		string s2 = findMax(nums2, k-i);

		string s = merge(s1, s2);
		maxStr = max(maxStr, s);
	}
	vector<int> result;
	for (const auto& c : maxStr) {
		result.emplace_back(c-'0');
	}
	return result;
}
