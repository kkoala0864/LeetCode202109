#include <Solution.h>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::to_string;
using std::cout;
using std::endl;

int getNextCi(vector<int>& cnt, int ci) {
	for (int i = ci ; i >= 0 ; --i) {
		if (cnt[i] > 0) return i;
	}
	return -1;
}

int Solution::maximumSwap(int num) {
	string v = to_string(num);
	vector<int> cnt(10, 0);

	for (int i = 0 ; i < v.size() ; ++i) {
		++cnt[v[i]-'0'];
	}
	int ci = getNextCi(cnt, 9);
	int rv = -1;

	for (int i = 0 ; i < v.size() ; ++i) {
		if ((v[i]-'0') != ci) {
			rv = v[i] - '0';
			v[i] = ci + '0';
			break;
		}
		--cnt[ci];
		ci = getNextCi(cnt, ci);
	}
	if (rv == -1) return num;
	for (int i = v.size() - 1 ; i >= 0 ; --i) {
		if ((v[i]-'0') != ci) continue;
		v[i] = rv + '0';
		break;
	}
	return stoi(v);
}
