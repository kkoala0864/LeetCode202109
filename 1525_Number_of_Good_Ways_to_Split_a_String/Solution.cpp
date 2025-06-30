#include <Solution.h>

int Solution::numSplits(string s) {
	int size = s.size();
	vector<int> prefix(size, 0), postfix(size, 0);

	unordered_set<char> us;
	for (int i = 0 ; i < s.size() ; ++i) {
		us.emplace(s[i]);
		prefix[i] = us.size();
	}
	us.clear();
	for (int i = s.size() - 1 ; i >= 0 ; --i) {
		us.emplace(s[i]);
		postfix[i] = us.size();
	}

	int result = 0;
	for (int i = 0 ; i < s.size() - 1 ; ++i) {
		if (prefix[i] != postfix[i+1]) continue;
		++result;
	}

	return result;
}
