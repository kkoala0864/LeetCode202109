#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;
void list(vector<bool>& flag, string& result, string& cur, int idx, int& k) {
	if (idx == flag.size()) {
		--k;
		if (k == 0) result = cur;
		return;
	}
	for (int i = 0 ; i < flag.size() ; ++i) {
		if (flag[i]) continue;
		flag[i] = true;
		cur.push_back(i + 1 + '0');
		list(flag, result, cur, idx + 1, k);
		flag[i] = false;
		cur.pop_back();
		if (!result.empty()) return;
	}
}

string Solution::getPermutation(int n, int k) {
	vector<bool> flag(n, false);
	string result;
	string cur("");
	list(flag, result, cur, 0, k);
	return result;
}
