#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int getV(const string &s) {
	int result = 0;
	int base = 1;

	for (int i = 0; i < s.size(); ++i) {
		result = result << 1;
		if (s[i] == '1') {
			result += base;
		}
	}
	return result;
}

string getS(int v, int size) {
	string result;

	for (int i = size - 1; i >= 0; --i) {
		int base = 1 << i;
		result.push_back((v / base) + '0');
		v = v % base;
	}
	return result;
}

string Solution::findDifferentBinaryString(vector<string> &nums) {
	int size = nums.size();
	vector<bool> v(1 << size, false);

	for (const auto &n : nums) {
		int val = getV(n);
		v[val] = true;
	}
	for (int i = 0; i < v.size(); ++i) {
		if (v[i])
			continue;
		cout << i << endl;
		return getS(i, size);
	}
	return "";
}
