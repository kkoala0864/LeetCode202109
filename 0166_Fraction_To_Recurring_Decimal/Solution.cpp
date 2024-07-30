#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::to_string;
using std::unordered_map;

string Solution::fractionToDecimal(int numerator, int denominator) {
	if (numerator == 0) return "0";
	bool isNeg = ((numerator >> 31) & 1) != ((denominator >> 31) & 1);
	long num = numerator;
	long den = denominator;
	num = num < 0 ? -num : num;
	den = den < 0 ? -den : den;
	string result;
	long v = num / den;
	result += to_string(v);
	num %= den;
	if (num == 0) return isNeg ? "-" + result : result;

	string rhs;
	unordered_map<long, int> m;
	while (num > 0) {
		long v = num / den;
		rhs.push_back(v + '0');
		num %= den;
		if (m.count(num)) break;
		m[num] = rhs.size();
		num *= 10;
	}

	rhs[0] = '.';
	if (num > 0) {
		string tmp = rhs.substr(0, m[num]);
		tmp.push_back('(');
		tmp += rhs.substr(m[num]);
		tmp.push_back(')');
		rhs = move(tmp);
	}
	result += rhs;
	return isNeg ? "-" + result : result;
}
