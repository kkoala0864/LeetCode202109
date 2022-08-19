#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

string Solution::longestCommonPrefix2(vector<string>& strs) {
	string result = strs[0];
	for (int i = 1 ; i < strs.size() ; ++i) {
		int iter = 0;
		int size = min(result.size(), strs[i].size());
		while (iter < size) {
			if (result[iter] == strs[i][iter]) ++iter;
			else break;
		}
		result = result.substr(0, iter);
	}
	return result;
}
