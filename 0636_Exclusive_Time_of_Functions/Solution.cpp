#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

void parse(const string &s, vector<int> &oper) {
	int sp1 = s.find(":");
	int sp2 = s.find(":", sp1 + 1);
	oper[0] = stoi(s.substr(0, sp1));
	oper[1] = s.substr(sp1 + 1, sp2 - sp1 - 1) == "start" ? 0 : 1;
	oper[2] = stoi(s.substr(sp2 + 1));
}

// if oper[1] = 0
//	dfs nextId; return nextId occupy Time
//	curId cumulate nextId occupy Time
//
// if oper[1] = 1
//      result[curId] += curT - startTime - occupy Time
//	return curT - startTime

int dfs(int &li, const vector<string> &logs, vector<int> &result) {
	vector<int> start(3, 0);
	parse(logs[li++], start);
	int occupyT = 0;
	while (logs[li].find("end") == std::string::npos) {
		occupyT += dfs(li, logs, result);
	}

	vector<int> end(3, 0);
	parse(logs[li++], end);
	result[end[0]] += end[2] - start[2] + 1 - occupyT;
	return end[2] - start[2] + 1;
}

vector<int> Solution::exclusiveTime(int n, vector<string> &logs) {
	vector<int> result(n, 0);
	int li = 0;
	while (li < logs.size()) {
		dfs(li, logs, result);
	}
	return result;
}
