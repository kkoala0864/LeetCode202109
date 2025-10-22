#include <data_type.h>

class SparseVector {
public:
	SparseVector(vector<int> &nums) {
		for (int i = 0 ; i < nums.size() ; ++i) {
			if (nums[i] == 0) continue;
			v.emplace_back(pair<int, int>(i, nums[i]));
		}
	}

	int dotProduct(SparseVector& vec) {
		int result = 0;
		int ci = 0;
		int vi = 0;
		while (ci < v.size() && vi < vec.v.size()) {
			if (v[ci].first == vec.v[vi].first) {
				result += (v[ci++].second * vec.v[vi++].second);
			} else {
				if (v[ci].first < vec.v[vi].first) {
					++ci;
				} else {
					++vi;
				}
			}
		}
		return result;
	}

	vector<pair<int, int>> v;
private:
	SparseVector &operator=(const SparseVector &source);
	SparseVector(const SparseVector &);
};
