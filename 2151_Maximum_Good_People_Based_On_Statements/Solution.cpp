#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>

using std::bitset;
using std::max;
using std::string;

bool check(const vector<vector<int>> &statements, const string &str) {
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] != '1')
			continue;
		for (int j = 0; j < str.size(); ++j) {
			if (i == j)
				continue;
			if (statements[i][j] == 2)
				continue;
			if (statements[i][j] != (str[j] - '0'))
				return false;
		}
	}
	return true;
}

int Solution::maximumGood(vector<vector<int>> &statements) {
	int size = statements.size();
	int result = 0;
	int totalSize = 1 << size;
	for (int i = 0; i < totalSize; ++i) {
		string bitStr = bitset<15>(i).to_string().substr(15 - size);
		if (check(statements, bitStr)) {
			int cnt = 0;
			for (const auto &iter : bitStr)
				if (iter == '1')
					++cnt;
			result = max(result, cnt);
		}
	}
	return result;
}
