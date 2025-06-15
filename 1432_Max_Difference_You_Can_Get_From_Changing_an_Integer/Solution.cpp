#include <Solution.h>

int Solution::maxDiff(int num) {
	string str = to_string(num);
	char replace = '#';
	string maxStr;
	for (int i = 0 ; i < str.size() ; ++i) {
		if (replace == '#' && str[i] != '9') {
			replace = str[i];
		}
		maxStr.push_back(str[i] == replace ? '9' : str[i]);
	}
	string minStr1;
	replace = '#';
	for (const auto& c : str) {
		if (replace == '#' && c != '1') {
			replace = c;
		}
		minStr1.push_back(c == replace ? '1' : c);
	}
	string minStr0(1, str[0]);
	replace = '#';
	for (int i = 1 ; i < str.size() ; ++i) {
		if (replace == '#' && str[i] != '0' && str[i] != str[0]) {
			replace = str[i];
		}
		minStr0.push_back(str[i] == replace ? '0' : str[i]);
	}
	int maxV = stoi(maxStr);
	int v0 = stoi(minStr0);
	int v1 = stoi(minStr1);
	return max(maxV - v0, maxV - v1);
}
