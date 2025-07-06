#include <data_type.h>

class FindSumPairs {
public:
	FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
		for (const auto& v : nums1) {
			++valCnt1[v];
		}
		n2 = nums2;
		for (const auto& v : nums2) {
			++valCnt2[v];
		}
	}

	void add(int index, int val) {
		if (index >= n2.size()) return;
		int v = n2[index];
		--valCnt2[v];
		if (valCnt2[v] == 0) {
			valCnt2.erase(v);
		}
		n2[index] += val;
		v = n2[index];
		++valCnt2[v];
	}

	int count(int tot) {
		int result = 0;
		for (const auto& e : valCnt2) {
			int rest = tot - e.first;
			if (valCnt1.count(rest) == 0) continue;
			result += (e.second * valCnt1[rest]);
		}
		return result;
	}

private:
	unordered_map<int, int> valCnt1;
	unordered_map<int, int> valCnt2;
	vector<int> n2;
	virtual ~FindSumPairs() {
	}
	FindSumPairs &operator=(const FindSumPairs &source);
	FindSumPairs(const FindSumPairs &);
};
