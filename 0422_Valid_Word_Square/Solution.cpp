#include <Solution.h>
#include <iostream>

bool Solution::validWordSquare(vector<string> &words) {
	for (int i = 0; i < words.size(); ++i) {
		for (int j = 0; j < words[i].size(); ++j) {
			if (words.size() <= j || words[j].size() <= i)
				return false;
			if (words[i][j] != words[j][i])
				return false;
		}
	}
	return true;
}
