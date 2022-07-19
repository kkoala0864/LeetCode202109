#include <Solution.h>
#include <iostream>

using std::to_string;

string Solution::countAndSay(int n) {
	string result("1");
	for (int i = 2 ; i <= n ; ++i) {
		string local("");
		char c = result[0];
		int cnt = 1;
		for (int j = 1 ; j < result.size() ; ++j) {
			if (c != result[j]) {
				local += to_string(cnt);
				local.push_back(c);
				c = result[j];
				cnt = 1;
			} else {
				++cnt;
			}
		}

		local += to_string(cnt);
		local.push_back(c);
		result = local;
	}
	return result;
}
