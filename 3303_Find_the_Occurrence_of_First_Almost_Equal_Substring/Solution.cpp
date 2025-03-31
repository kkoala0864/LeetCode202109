#include <Solution.h>
#include <iostream>
#include <vector>

vector<int> getZ(const string& s, const string& p) {
	string str = p + "#" + s;
	vector<int> z(str.size(), 0);
	int l = 0, r = 0;

	for (int i = 1 ; i < str.size() ; ++i) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}
		while ((i + z[i]) < str.size() && str[i + z[i]] == str[z[i]]) {
			++z[i];
		}
		if ((i + z[i] - 1) > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int Solution::minStartingIndex(string s, string pattern) {
	int m = s.size();
	int n = pattern.size();

	vector<int> preZ = getZ(s, pattern);

	string rs = s;
	reverse(rs.begin(), rs.end());
	string rp = pattern;
	reverse(rp.begin(), rp.end());

	vector<int> postZ = getZ(rs, rp);
	reverse(postZ.begin(), postZ.end());

	for (int i = 0 ; i <= (m - n) ; ++i) {
		int preLen = preZ[i + n + 1];
		int postTail = i + n - 1;
		int postLen = postZ[postTail];
		if ((preLen + postLen) >= (n - 1)) {
			return i;
		}
	}
	return -1;
}
