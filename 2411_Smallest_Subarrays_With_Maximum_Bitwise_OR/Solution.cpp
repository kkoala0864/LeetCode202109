#include <Solution.h>

vector<int> sub(vector<int>& a, vector<int>& b) {
	vector<int> result(32, 0);
	for (int i = 0 ; i < 32 ; ++i) result[i] = a[i] - b[i];
	return result;
}

bool check(int mx, vector<vector<int>>& preORBits, int mid) {
	auto bits = sub(preORBits.back(), preORBits[mid]);
	for (int i = 0 ; i < 32 ; ++i) {
		int mb = (1 << i) & mx ? 1 : 0;
		int bb = bits[i] > 0 ? 1 : 0;
		if (mb != bb) return false;
	}
	return true;
}

void doOper(int v, vector<int>& bits, int oper) {
	for (int i = 0 ; i < 32 ; ++i) {
		if ((1 << i) & v) {
			if (oper == 0) ++bits[i];
			else --bits[i];
		}
	}
}

int getLen(vector<vector<int>>& preORBits, int curMax) {
	int l = 0, r = preORBits.size() - 1;
	int mid = 0;

	while (l < r) {
		mid = r - ((r - l) >> 1);
		bool ret = check(curMax, preORBits, mid);
		if (ret) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return !check(curMax, preORBits, l) ? preORBits.size() : max(((int)preORBits.size() - l - 1), 1);
}

vector<int> Solution::smallestSubarrays(vector<int>& nums) {
	int size = nums.size();

	vector<vector<int>> preORBits;
	vector<int> cur(32, 0);
	int v = 0;
	vector<int> result(size, INT_MAX);

	for (int i = size - 1 ; i >= 0 ; --i) {
		v |= nums[i];
		doOper(nums[i], cur, 0);
		preORBits.emplace_back(cur);
		result[i] = getLen(preORBits, v);
	}
	return result;
}
