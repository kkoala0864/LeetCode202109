#include <Solution.h>
#include <iostream>

string Solution::makeGood(string s) {
	string result;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (result.empty()) {
			result.push_back(s[i]);
		} else {
			if (((islower(s[i]) && isupper(result.back())) ||
			    (isupper(s[i]) && islower(result.back()))) &&
			    (toupper(s[i]) == toupper(result.back()))) {

				result.pop_back();
			} else {
				result.push_back(s[i]);
			}
		}
	}
	return result;
}
