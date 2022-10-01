#include <Solution.h>
#include <iostream>

int Solution::findLonelyPixel(vector<vector<char>>& picture) {
	vector<vector<int>> rowCnt(picture.size(), vector<int>());
	vector<vector<int>> colCnt(picture[0].size(), vector<int>());

	for (int i = 0 ; i < picture.size() ; ++i) {
		for (int j = 0 ; j < picture[0].size() ; ++j) {
			if (picture[i][j] == 'B') {
				rowCnt[i].emplace_back(j);
				colCnt[j].emplace_back(i);
			}
		}
	}
	int result = 0;
	for (int i = 0 ; i < rowCnt.size() ; ++i) {
		if (rowCnt[i].size() == 1 && colCnt[rowCnt[i][0]].size() == 1) ++result;
	}
	return result;
}
