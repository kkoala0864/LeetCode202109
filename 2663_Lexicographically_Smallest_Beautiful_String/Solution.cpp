#include <Solution.h>

bool check(const string& s, int start) {
	for (int i = start - 1 ; i >= max(0, start - 2) ; --i) {
		if (s[i] == s[start]) return false;
	}
	return true;
}

// doesn't contain palindrome which means cur val can not equal with least two value
string Solution::smallestBeautifulString(string s, int k) {
	int size = s.size();
	for (int i = size - 1 ; i >= 0 ; --i) {
		for (int c = 1 ; (s[i] + c) <= ('a' + k - 1) ; ++c) {
			s[i] += c;
			if (check(s, i)) {
				for (int j = i + 1 ; j < s.size() ; ++j) {
					for (char x = 'a' ; x <= ('a' + k - 1) ; ++x) {
						s[j] = x;
						if (check(s, j)) break;
					}
				}
				return s;
			}
			s[i] -= c;
		}
	}
	return "";
}
