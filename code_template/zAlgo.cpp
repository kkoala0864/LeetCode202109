#include <Solution.h>
#include <iostream>

vector<int> getZArray(const string &s, const string &pattern) {
	string str = pattern + "#" + s;
	vector<int> z(str.size(), 0);

	int l = 0, r = 0;
	for (int i = 1; i < str.size(); ++i) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while ((i + z[i]) < str.size() && str[z[i]] == str[i + z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

vector<int> Solution::zAlgorithm(const string &text, const string &pattern) {
	int m = text.size(), n = pattern.size();

	auto result = getZArray(text, pattern);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return result;
}
