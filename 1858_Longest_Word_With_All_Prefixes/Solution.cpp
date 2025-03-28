#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::sort;

string Solution::longestWord(vector<string> &words) {
	Node *root = new Node();

	auto cmp = [](const string &lhs, const string &rhs) {
		return lhs.size() < rhs.size();
	};
	sort(words.begin(), words.end(), cmp);

	int maxLen = 0;
	string result;
	for (const auto &w : words) {
		Node *iter = root;
		bool check = true;
		for (int i = 0; i < w.size(); ++i) {
			if (!iter->child[w[i] - 'a']) {
				if (i != w.size() - 1) {
					check = false;
					break;
				} else {
					iter->child[w[i] - 'a'] = new Node();
				}
			}
			iter = iter->child[w[i] - 'a'];
		}
		if (check) {
			if (maxLen < w.size()) {
				result = w;
				maxLen = w.size();
			} else if (maxLen == w.size()) {
				result = min(result, w);
			}
		}
	}
	return result;
}
