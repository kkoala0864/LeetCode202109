#include <Solution.h>

long long quickPow(long long n) {
	if (n == 0) return 1;
	long long v = quickPow(n / 2);
	long long vv = v * v;
	return n & 1 ? vv * 10 : vv;
}

string toKBase(long long v, int k) {
	string result;
	while (v > 0) {
		result.push_back((v % k) + '0');
		v /= k;
	}
	return result;
}

bool isPalin(string s) {
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r]) return false;
		++l;
		--r;
	}
	return true;
}

long long Solution::kMirror(int k, int n) {
	long long result = 0;
	for (long long i = 1 ; i <= 9 && n > 0 ; ++i) {
		if (isPalin(toKBase(i, k))) {
			result += (long long)i;
			--n;
		}
	}
	if (n == 0) return result;

	int len = 1;
	while (n > 0) {
		int maxValue = quickPow(len);
		int base = quickPow(len - 1);
		for (int i = base ; i < maxValue ; ++i) {
			string cur = to_string(i);
			string rev_cur = cur;
			reverse(rev_cur.begin(), rev_cur.end());
			string tmp = cur + rev_cur;
			long long v = stoll(tmp);
			if (isPalin(toKBase(v, k))) {
				--n;
				result += v;
			}
			if (n == 0) return result;
		}
		for (int i = base ; i < maxValue ; ++i) {
			string cur = to_string(i);
			string rev_cur = cur;
			reverse(rev_cur.begin(), rev_cur.end());
			for (int mid = 0 ; mid < 10 ; ++mid) {
				string tmp = cur + string(1, mid + '0') + rev_cur;
				long long v = stoll(tmp);
				if (isPalin(toKBase(v,k))) {
					--n;
					result += v;
				}
				if (n == 0) return result;
			}
		}
		++len;
	}
	return -1;
}
