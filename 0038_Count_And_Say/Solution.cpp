#include <Solution.h>
#include <iostream>

string Solution::countAndSay(int n) {
	if (n == 1) return "1";
	string result(1, '1');
	for (int i = 2 ; i <= n ; ++i) {
		string tmp;
		int cnt = 1;
		for (int j = 1 ; j < result.size() ; ++j) {
			if (result[j] == result[j-1]) {
				++cnt;
			} else {
				tmp += to_string(cnt) + string(1,result[j-1]);
				cnt = 1;
			}
		}
		tmp += to_string(cnt) + string(1, result.back());
		result = move(tmp);
	}
	return result;
}
