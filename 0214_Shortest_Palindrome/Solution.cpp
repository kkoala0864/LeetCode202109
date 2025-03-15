#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

// s = A'AB
// r = B'A'A
// => (A'A)B
// => B'(A'A)

int KMPCheck(string str) {

	string post = str;
	reverse(post.begin(), post.end());
	str.push_back('#');
	str += post;

	vector<int> lps(str.size(), 0);

	int len = 0;
	int i = 1;

	while (i < str.size()) {
		if (str[i] == str[len]) {
			++len;
			lps[i] = len;
			++i;
		} else {
			if (len == 0) {
				lps[i] = 0;
				++i;
			} else {
				len = lps[len-1];
			}
		}
	}
	return lps.back();
}

string Solution::shortestPalindrome(string s) {
	int longestSize = KMPCheck(s);

	if (longestSize == s.size()) return s;
	string result = s.substr(longestSize);
	reverse(result.begin(), result.end());
	result += s;
	return result;
}
