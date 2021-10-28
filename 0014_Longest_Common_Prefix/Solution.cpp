#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

string Solution::longestCommonPrefix(vector<string>& strs) {
	string common = strs[0];
	for (int i = 1 ; i < strs.size() ; ++i) {
		int iter = 0;
		while (iter < min(common.size(), strs[i].size())) {
			if (common[iter] != strs[i][iter]) {
				break;
			}
			++iter;
		}
		common = common.substr(0, iter);
	}
	return common;
}
