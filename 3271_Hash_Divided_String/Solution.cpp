#include <Solution.h>
#include <iostream>

string Solution::stringHash(string s, int k) {
	string result;
	for (int i = 0 ; i < s.size() / k ; ++i) {
		int v = 0;
		for (int j = 0 ; j < k ; ++j) {
			v += (s[i*k+j] - 'a');
		}
		v %= 26;
		result.push_back(v + 'a');
	}
	return result;
}
