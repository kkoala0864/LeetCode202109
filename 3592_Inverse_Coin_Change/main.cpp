#include <Solution.h>

int main(void) {
	vector<int> nums = {1, 0};
	Solution *test = new Solution();
	auto result = test->findCoins(nums);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
