#include <Solution.h>

vector<int> Solution::countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
	vector<int> result;
	int size = nums.size();
	vector<int> isPeak(size, 0);
	BTree t(size);
	for (int i = 1 ; i < size - 1 ; ++i) {
		if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
			isPeak[i] = 1;
			t.update(i, 1, 1, 0, size);
		}
	}

	for (const auto& q : queries) {
		if (q[0] == 1) {
			result.emplace_back(t.query(q[1] + 1, q[2] - 1, 1, 0, size));
		} else {
			if (nums[q[1]] == q[2]) continue;
			nums[q[1]] = q[2];
			for (int i = max(1, q[1] - 1) ; i <= min(size - 2, q[1] + 1) ; ++i) {
				int check = ((nums[i] > nums[i-1]) && (nums[i] > nums[i+1])) ? 1 : 0;
				if (check != isPeak[i]) {
					t.update(i, check, 1, 0, size);
					isPeak[i] = check;
				}
			}
		}
	}
	return result;
}
