#include <Solution.h>
#include <iostream>

// cnt(start -> finish) = cnt(finish) - cnt(start - 1)

long long quickPow(long long x, long long n) {
	if (n == 0) return 1;
	long long v = quickPow(x, n/2);
	long long vv = v * v;
	return n & 1 ? vv * x : vv;
}

long long getV(string& s, int i, int limit) {
	if (i == s.size() - 1) return min(s[i] - '0', limit) + 1;
	long long first = min(s[i] - '0' - 1, limit) + 1;
	long long result = first * quickPow(limit + 1, s.size() - i - 1);
	if ((s[i] - '0') <= limit) {
		result += getV(s, i + 1, limit);
	}
	return result;
}

long long cnt(long long v, int limit, string s) {
	string fs = to_string(v);
	if (fs.size() < s.size() || fs.size() == s.size() && fs < s) return 0;
	string up = fs.substr(0, fs.size() - s.size());
	string tail = fs.substr(fs.size() - s.size(), s.size());
	if (up.empty()) up = "0";
	if (tail < s) {
		v = stoll(up);
		--v;
		up = to_string(v);
	}
	return getV(up, 0, limit);
}

long long Solution::numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
	long long fv = cnt(finish, limit, s);
	long long sv = start > 0 ? cnt(start - 1 , limit, s) : 0;
	return fv - sv;
}
