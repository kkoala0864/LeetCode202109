#include <Solution.h>
#include <iostream>

int Solution::minLength(string s) {
	string cur;

	for (const auto& c : s) {
		if (cur.empty()) {
			cur.push_back(c);
		} else {
			if ((c == 'B' && cur.back() == 'A') || (c == 'D' && cur.back() == 'C')) {
				cur.pop_back();
			} else {
				cur.push_back(c);
			}
		}
	}
	return cur.size();

}
