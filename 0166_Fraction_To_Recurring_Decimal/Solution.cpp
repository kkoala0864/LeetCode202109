#include <Solution.h>

string Solution::fractionToDecimal(int numerator, int denominator) {
	if (numerator == 0) return "0";

	bool isneg = (numerator < 0) != (denominator < 0);
	long long num = numerator;
	long long deno = denominator;
	if (isneg) {
		num = abs(num);
		deno = abs(deno);
	}

	long long left = num / deno;
	string result = to_string(left);
	long long right = num % deno;

	string fraction;
	unordered_map<long long, int> idx;

	while (right != 0 && idx.count(right) == 0) {
		idx[right] = fraction.size();
		right *= 10;
		fraction += to_string(right / (long long)deno);
		right %= (long long)deno;
	}

	if (right == 0) {
		if (!fraction.empty()) {
			result += ("." + fraction);
		 }
	} else {
		int pIdx = idx[right];
		string repeat = fraction.substr(pIdx);
		result = result + "." + fraction.substr(0, pIdx) + "(" + fraction.substr(pIdx) + ")";
	}
	if (isneg) result = "-" + result;
	return result;
}
