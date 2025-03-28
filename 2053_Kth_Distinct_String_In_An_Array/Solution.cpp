#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

string Solution::kthDistinct(vector<string> &arr, int k) {
	vector<int> strCnt;
	vector<string> disCnt;
	unordered_map<string, int> vToIdx;

	for (int i = 0; i < arr.size(); ++i) {
		if (vToIdx.count(arr[i]) == 0) {
			strCnt.emplace_back(1);
			disCnt.emplace_back(arr[i]);
			vToIdx[arr[i]] = disCnt.size() - 1;
		} else {
			++strCnt[vToIdx[arr[i]]];
		}
	}
	int cnt = 0;
	for (int i = 0; i < strCnt.size(); ++i) {
		if (strCnt[i] == 1)
			++cnt;
		if (cnt == k)
			return disCnt[i];
	}
	return "";
}
