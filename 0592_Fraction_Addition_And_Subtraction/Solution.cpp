#include <Solution.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::swap;
using std::to_string;
using std::vector;

void split(const string &exp, vector<string> &nums) {
	string cur;
	for (const auto &c : exp) {
		if (c == '+' || c == '-') {
			if (!cur.empty()) {
				nums.emplace_back(cur);
				cur = "";
			}
		}
		cur.push_back(c);
	}
	nums.emplace_back(cur);
}

int getGCD(int lhs, int rhs) {
	if (lhs > rhs)
		swap(lhs, rhs);
	if (lhs == 0)
		return rhs;

	rhs %= lhs;
	return getGCD(rhs, lhs);
}

void getDenoAndNum(string &nums, int &deno, int &num, int &sign) {
	sign = nums[0] == '-' ? -1 : 1;
	if (nums[0] == '+' || nums[0] == '-')
		nums = nums.substr(1);
	int idx = nums.find('/');
	num = stoi(nums.substr(0, idx));
	deno = stoi(nums.substr(idx + 1));
}

void calculate(int &deno, int &num, int &sign, int &curDeno, int &curNum, int &curSign) {
	int gcd = getGCD(deno, curDeno);
	int t = deno / gcd;
	int curT = curDeno / gcd;

	num *= curT;
	curNum *= t;

	int v = sign * num + curSign * curNum;
	sign = v < 0 ? -1 : 1;
	num = abs(v);

	deno *= curT;

	gcd = getGCD(num, gcd);
	num /= gcd;
	deno /= gcd;
	deno = num == 0 ? 1 : deno;
}

string Solution::fractionAddition(string expression) {
	vector<string> nums;
	split(expression, nums);

	int deno = 0;
	int num = 0;
	int sign = 0;
	getDenoAndNum(nums[0], deno, num, sign);

	for (int i = 1; i < nums.size(); ++i) {
		int curDeno = 0;
		int curNum = 0;
		int curSign = 0;
		getDenoAndNum(nums[i], curDeno, curNum, curSign);
		calculate(deno, num, sign, curDeno, curNum, curSign);
	}
	string result = sign == -1 ? "-" : "";
	result += (to_string(num) + "/" + to_string(deno));
	return result;
}
