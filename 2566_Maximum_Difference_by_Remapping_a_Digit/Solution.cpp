#include <Solution.h>

int Solution::minMaxDifference(int num) {
	string str = to_string(num);
	char min_remap = '#';
	char max_remap = '#';
	string maxStr;
	string minStr;
	for (int i = 0 ; i < str.size() ; ++i) {
		if (min_remap == '#' && str[i] != '0') {
			min_remap = str[i];
		}
		if (max_remap == '#' && str[i] != '9') {
			max_remap = str[i];
		}
		minStr.push_back(str[i] == min_remap ? '0' : str[i]);
		maxStr.push_back(str[i] == max_remap ? '9' : str[i]);
	}

	int maxV = stoi(maxStr);
	int minV = stoi(minStr);
	return maxV - minV;
}
