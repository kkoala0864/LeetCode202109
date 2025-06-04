#include <Solution.h>

bool dfs(const string& ls, const string& rs, int i, const string& num) {
	if (i == num.size()) return true;
	if (i > num.size()) return false;
	if (ls[0] == '0' && ls.size() > 1) return false;
	if (rs[0] == '0' && rs.size() > 1) return false;

	string sum;
	int carry = 0;
	for (int j = 0 ; j < max(ls.size(), rs.size()) ; ++j) {
		int v = carry;
		if (j < ls.size()) v += (ls[ls.size() - 1 - j] - '0');
		if (j < rs.size()) v += (rs[rs.size() - 1 - j] - '0');
		sum.push_back((v % 10) + '0');
		carry = v / 10;
	}
	if (carry > 0) sum.push_back(carry + '0');
	reverse(sum.begin(), sum.end());
	if ((num.size() - i) < sum.size()) return false;
	string compare = num.substr(i, sum.size());
	if (compare != sum) return false;
	return dfs(rs, compare, i + sum.size(), num);
}

bool Solution::isAdditiveNumber(string num) {
	if (num.size() < 3) return false;
	for (int i = 0 ; i < num.size() - 2 ; ++i) {
		for (int j = i + 1 ; j < num.size() - 1 ; ++j) {
			if (dfs(num.substr(0, i + 1), num.substr(i + 1, j - i), j + 1, num)) return true;
		}
	}
	return false;
}
