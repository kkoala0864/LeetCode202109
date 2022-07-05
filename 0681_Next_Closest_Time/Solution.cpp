#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;
using std::to_string;
using std::cout;
using std::endl;

string Solution::nextClosestTime(string time) {
	unordered_set<int> oSet;
	int timeBase = 0;
	int t = 0;
	for (const auto& c : time) {
		if (c != ':') {
			t = (t * 10) + (c - '0');
			oSet.emplace(c - '0');
		} else {
			timeBase += t * 60;
			t = 0;
		}
	}
	timeBase += t;
	if (oSet.size() == 1) return time;
	vector<int> h, m;
	for (auto& i1 : oSet) {
		for (auto& i2 : oSet) {
			int val = i1 * 10 + i2;
			if (val < 24) h.emplace_back(val);
			if (val < 60) m.emplace_back(val);
		}
	}
	int minDiff = INT_MAX;
	string result("");
	for (const auto& hv : h) {
		for (const auto& mv : m) {
			int diff = (hv * 60 + mv) - timeBase;
			if (diff == 0) continue;
			if (diff < 0) diff += 1440;
			if (diff != 0 && diff < minDiff) {
				minDiff = diff;
				string hs = to_string(hv);
				if (hv < 10) hs = "0" + hs;
				string ms = to_string(mv);
				if (mv < 10) ms = "0" + ms;
				result = hs + ":" + ms;
			}
		}
	}
	return result;
}
