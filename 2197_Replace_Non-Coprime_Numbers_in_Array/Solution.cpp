#include <Solution.h>

long long gcd(long long a, long long b) {
	if (a < b) swap(a,b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	int g = gcd(a, b);
	return (a * b) / g;
}

long long canComb(long long a, long long b) {
	if (a == 1) return 1;
	if (a % b == 0 || b % a == 0) return max(a, b);
	if (gcd(a, b) == 1) return 1;
	return lcm(a, b);
}

vector<int> Solution::replaceNonCoprimes(vector<int>& nums) {
	vector<int> result;

	for (const auto& v : nums) {
		if (result.empty() || v == 1) result.emplace_back(v);
		else {
			long long tail = v;
			while (!result.empty() && canComb(result.back(), tail) != 1) {
				tail = canComb(result.back(), tail);
				result.pop_back();
			}
			result.emplace_back(tail);
		}
	}
	return result;
}
