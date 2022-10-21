#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::unordered_map;
using std::reverse;
using std::cout;
using std::endl;

string Solution::intToRoman(int num) {
	string result;
	unordered_map<int, char> charMap;
	charMap[1] = 'I';
	charMap[5] = 'V';
	charMap[10] = 'X';
	charMap[50] = 'L';
	charMap[100] = 'C';
	charMap[500] = 'D';
	charMap[1000] = 'M';
	int base = 1;
	while (num) {
		int val = num % 10;
		if (val >= 5) {
			if (val == 9) {
				result = string(1, charMap[base*10]) + result;
				result = string(1, charMap[base]) + result;
			} else {
				val -= 5;
				result = string(val, charMap[base]) + result;
				result = string(1, charMap[base*5]) + result;
			}
		} else {
			if (val == 4) {
				result = string(1, charMap[base*5]) + result;
				result = string(1, charMap[base]) + result;
			} else {
				result = string(val, charMap[base]) + result;
			}
		}
		num /= 10;
		base *= 10;
	}
	return result;
}
