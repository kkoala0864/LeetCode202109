#include <data_type.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

// latest time be voted
// count leading persons

class TopVotedCandidate {
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		int size = persons.size();
		cnt = vector<pair<int, int>>(size + 1, {0, 0});
		vector<int> pc(size + 1, 0);

		leading[-1] = -1;
		for (int i = 0 ; i < size ; ++i) {
			++pc[persons[i]];
			maxCnt = max(maxCnt, pc[persons[i]]);
			cnt[pc[persons[i]]] = {persons[i], times[i]};
			leading[times[i]] = cnt[maxCnt].first;
		}
	}

	int q(int t) {
		auto iter = leading.upper_bound(t);
		--iter;
		return iter->second;
	}

private:
	vector<pair<int, int>> cnt;
	map<int, int> leading; // [time] = leading person
	int maxCnt = 0;
	virtual ~TopVotedCandidate() {
	}
	TopVotedCandidate &operator=(const TopVotedCandidate &source);
	TopVotedCandidate(const TopVotedCandidate &);
};
