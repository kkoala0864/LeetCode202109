#include <Solution.h>
#include <iostream>

string Solution::largestGoodInteger(string num) {
	string result;
	string cur;
	for (const auto& c : num) {
		if (cur.empty()) {
			cur.push_back(c);
		} else {
			if (cur.back() == c) {
				cur.push_back(c);
				if (cur.size() == 3) {
					if (result.empty() || result[0] < cur[0]) {
						result = cur;
					}
					cur = "";
				}
			} else {
				cur = string(1, c);
			}
		}
	}
	return result;
}
