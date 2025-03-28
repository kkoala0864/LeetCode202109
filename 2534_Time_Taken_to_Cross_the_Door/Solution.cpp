#include <Solution.h>
#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::pair;
using std::queue;

vector<int> Solution::timeTaken(vector<int> &arrival, vector<int> &state) {
	vector<queue<int>> delayList(2, queue<int>());
	vector<int> result(arrival.size(), 0);
	int cs = 1;
	int curT = -1;

	for (int i = 0; i < arrival.size(); ++i) {
		int os = (cs + 1) & 1;
		while (curT < arrival[i]) {
			if (delayList[0].empty() && delayList[1].empty()) {
				curT = arrival[i];
				cs = 1;
			} else {
				int state = delayList[cs].empty() ? os : cs;
				result[delayList[state].front()] = curT++;
				delayList[state].pop();
				cs = state;
			}
		}
		delayList[state[i]].emplace(i);
	}
	int os = (cs + 1) & 1;
	while (!delayList[cs].empty()) {
		result[delayList[cs].front()] = curT++;
		delayList[cs].pop();
	}
	while (!delayList[os].empty()) {
		result[delayList[os].front()] = curT++;
		delayList[os].pop();
	}
	return result;
}
