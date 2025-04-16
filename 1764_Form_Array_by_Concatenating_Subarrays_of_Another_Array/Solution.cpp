#include <Solution.h>
#include <iostream>
#include <string>

bool Solution::canChoose(vector<vector<int>>& groups, vector<int>& nums) {
	string ns(1,',');
	for (const auto& v : nums) {
		ns += to_string(v);
		ns.push_back(',');
	}
	int idx = 0;
	for (const auto& g : groups) {
		string gs(1, ',');
		for (const auto& v : g) {
			gs += to_string(v);
			gs.push_back(',');
		}
		idx = ns.find(gs, idx);
		if (idx == string::npos) return false;
		idx += gs.size() - 1;
	}
	return true;
}

