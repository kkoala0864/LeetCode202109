#include <Solution.h>
#include <iostream>

vector<int> getZArray(const string& s) {
	string str = s;
	vector<int> z(str.size(), 0);

	int l = 0, r = 0;
	for (int i = 1 ; i < str.size() ; ++i) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i-l]);
		}
		while ((i + z[i]) < str.size() && s[z[i]] == s[i+z[i]]) {
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

	auto result = getZArray(text);
	for (int i =  0 ; i < result.size() ; ++i) cout << result[i] << " ";
	cout << endl;
	return result;
}
