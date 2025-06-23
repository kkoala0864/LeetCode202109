#include <Solution.h>

long long quickPow(long long x, long long n) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	long long v = quickPow(x, n / 2);
	long long vv = v * v;
	return n & 1 ? vv * x : vv;
}

string toKBase(long long v, long long k) {
	string ret;
	while (v > 0) {
		ret.push_back((v % k) + '0');
		v /= k;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool isPalin(const string& s) {
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
	for (int i = 1 ; i < 10 && n > 0 ; ++i) {
		string kStr = toKBase(i, k);
		if (isPalin(kStr)) {
			result += i;
			--n;
		}
	}
	if (n == 0) return result;
	while (n > 0) {
		for (int sz = 1 ; sz < 10 && n > 0 ; ++sz) {
			int limit = quickPow(10, sz);
			int base = quickPow(10, sz - 1);
			for (int i = base ; i < limit; ++i) {
				string pre = to_string(i);
				string post = pre;
				reverse(post.begin(), post.end());
				long long v = stoll(pre + post);
				string kStr = toKBase(v, k);
				if (isPalin(kStr)) {
					result += v;
					--n;
				}
			}
			for (int i = base ; i < limit && n > 0; ++i) {
				string pre = to_string(i);
				string post = pre;
				reverse(post.begin(), post.end());
				for (int mid = 0 ; mid < 10 && n > 0; ++mid) {
					long long v = stoll(pre + string(1, mid + '0') + post);
					string kStr = toKBase(v, k);
					if (isPalin(kStr)) {
						result += v;
						--n;
					}
				}
			}
		}
	}
	return result;
}
