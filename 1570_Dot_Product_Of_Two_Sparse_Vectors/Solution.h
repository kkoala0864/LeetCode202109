#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class SparseVector {
public:
	unordered_map<int, int> val;
	SparseVector(vector<int> &nums) {
		for (int i = 0; i < nums.size(); ++i) {
			val[i] = nums[i];
		}
	}

	int dotProduct(SparseVector &vec) {
		int result = 0;
		for (const auto &e : val) {
			if (vec.val.find(e.first) == vec.val.end())
				continue;
			result += (vec.val[e.first] * e.second);
		}
		return result;
	}

private:
	virtual ~SparseVector() {
	}
	SparseVector &operator=(const SparseVector &source);
	SparseVector(const SparseVector &);
};
