#include <data_type.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

using std::vector;
using std::unordered_set;
using std::priority_queue;
using std::pair;
using std::cout;
using std::endl;

class FirstUnique {
    public :
	FirstUnique(vector<int>& nums) {
		idx = 0;
		for (int i = 0 ; i < nums.size() ; ++i) {
			if (m.count(nums[i])) {
				continue;
			} else {
				if (s.count(nums[i])) {
					s.erase(nums[i]);
					m.emplace(nums[i]);
				} else {
					pq.emplace(pair<int, int>(idx++, nums[i]));
					s.emplace(nums[i]);
				}
			}
		}
	}

	int showFirstUnique() {
		if (s.empty()) return -1;
		while (!pq.empty() && s.count(pq.top().second) == 0) {
			pq.pop();
		}
		return pq.top().second;
	}

	void add(int value) {
		if (m.count(value)) {
			return;
		} else {
			if (s.count(value)) {
				s.erase(value);
				m.emplace(value);
			} else {
				pq.emplace(pair<int, int>(idx++, value));
				s.emplace(value);
			}
		}
	}
    private :
	int idx;
	unordered_set<int> m, s;
	priority_queue<pair<int ,int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        virtual ~FirstUnique() {}
        FirstUnique& operator=(const FirstUnique& source);
        FirstUnique(const FirstUnique&);
};

