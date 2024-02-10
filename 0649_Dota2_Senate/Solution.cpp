#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;
using std::cout;
using std::endl;

string Solution::predictPartyVictory(string senate) {
	queue<char> que;
	int dc = 0, rc = 0;
	for (const auto& s : senate) {
		if (s == 'R') ++rc;
		else ++dc;
		que.emplace(s);
	}
	int dv = 0, rv = 0;
	do {
		if (que.front() == 'R') {
			if (dv > 0) {
				--dv;
				--rc;
			} else {
				++rv;
				que.emplace('R');
			}
		} else {
			if (rv > 0) {
				--rv;
				--dc;
			} else {
				++dv;
				que.emplace('D');
			}
		}
		que.pop();
	} while (rc > 0 && dc > 0);
	return rc > dc ? "Radiant" : "Dire";
}
