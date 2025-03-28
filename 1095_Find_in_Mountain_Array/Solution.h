#include <data_type.h>
#include <vector>

using std::vector;

class MountainArray {
public:
	MountainArray(vector<int> &v)
	    : arr(v) {
	}
	int get(int index) {
		return arr[index];
	}
	int length() {
		return arr.size();
	}

private:
	vector<int> arr;
};

class Solution {
public:
	Solution() {
	}
	int findInMountainArray(int target, MountainArray &mountainArr);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
