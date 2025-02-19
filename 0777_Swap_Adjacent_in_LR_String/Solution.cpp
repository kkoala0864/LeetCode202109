#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool Solution::canTransform(string start, string result) {
	string ss, rs;
	vector<int> sli, rli, sri, rri;
	int size = start.size();
	for (int i = 0 ; i < size ; ++i) {
		if (start[i] == 'L') {
			sli.emplace_back(i);
			ss.push_back(start[i]);
		} else if (start[i] == 'R') {
			sri.emplace_back(i);
			ss.push_back(start[i]);
		}
		if (result[i] == 'L') {
			rli.emplace_back(i);
			rs.push_back(result[i]);
		} else if (result[i] == 'R') {
			rri.emplace_back(i);
			rs.push_back(result[i]);
		}
	}
	if (ss != rs) return false;
	for (int i = 0 ; i < sri.size() ; ++i) {
		if (sri[i] > rri[i]) return false;
	}
	for (int i = 0 ; i < sli.size() ; ++i) {
		if (sli[i] < rli[i]) return false;
	}
	return true;
}
