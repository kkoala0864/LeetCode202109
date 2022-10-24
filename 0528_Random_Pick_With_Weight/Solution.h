#include <vector>
#include <cmath>

using std::vector;

class Solution {
    public :
	Solution(vector<int>& w) {
		for (auto& v : w) {
			prefixSum.emplace_back(v + (prefixSum.empty() ? 0 : prefixSum.back()));
		}
	}

	int pickIndex() {
		float randNum = (float) rand() / RAND_MAX;
		float target = randNum * prefixSum.back();
		return lower_bound(prefixSum.begin(), prefixSum.end(), target) - prefixSum.begin();
	}
    private :
	vector<int> prefixSum;
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

