#include <data_type.h>

class BigArray {
	public:
		BigArray(vector<int> elements) {
			vec = elements;
		}
		int at(long long index) {
			return vec[index];
		}
		long long size() {
			return vec.size();
		}
	private:
		vector<int> vec;
};

class Solution {
public:
	Solution() {
	}
	int countBlocks(BigArray* nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
