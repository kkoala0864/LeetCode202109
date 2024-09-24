#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <string>

using std::string;
using std::to_string;
using std::max;
using std::cout;
using std::endl;

int Solution::longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
	tNode* root = new tNode();
	for (const auto& v : arr2) {
		string s = to_string(v);
		tNode* iter = root;
		for (int i = 0 ; i < s.size() ; ++i) {
			if (!iter->child[s[i]-'0']) iter->child[s[i]-'0'] = new tNode();
			iter = iter->child[s[i]-'0'];
		}
	}


	int result = 0;
	for (const auto& v : arr1) {
		string s = to_string(v);
		tNode* iter = root;
		int i = 0;
		for (; i < s.size() ; ++i) {
			if (!iter->child[s[i]-'0']) {
				break;
			}
			iter = iter->child[s[i]-'0'];
		}
		result = max(result, i);

	}
	return result;
}
