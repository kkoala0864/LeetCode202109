#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::to_string;

string Solution::multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0") return "0";
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int size = num1.size() + num2.size();
	string result(size, '0');

	for (int i = 0 ; i < num1.size() ; ++i) {
		int val1 = num1[i] - '0';
		for (int j = 0 ; j < num2.size() ; ++j) {
			int val2 = num2[j] - '0';

			int location = i + j;
			int val = (val1*val2) + (result[location]-'0');
			result[location] = (val % 10) + '0';
			result[location + 1] += (val / 10);
		}
	}
	if (result.back() == '0') {
		result.pop_back();
	}
	reverse(result.begin(), result.end());
	return result;
}

