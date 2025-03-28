#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::min;

bool compare(const string &s1, const string &s2, vector<int> &o) {
	int size = min(s1.size(), s2.size());

	for (int i = 0; i < size; ++i) {
		if (s1[i] == s2[i])
			continue;
		else if (o[s1[i] - 'a'] > o[s2[i] - 'a'])
			return false;
		else
			return true;
	}
	return s1.size() < s2.size();
}

bool Solution::isAlienSorted(vector<string> &words, string order) {
	vector<int> o(26, 0);
	for (int i = 0; i < order.size(); ++i)
		o[order[i] - 'a'] = i;
	for (int i = 0; i < words.size() - 1; ++i) {
		if (words[i] == words[i + 1])
			continue;
		if (!compare(words[i], words[i + 1], o))
			return false;
	}
	return true;
}
