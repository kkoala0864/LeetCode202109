#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,3,4,2,3,1,4,2};
	int k = 3;
	Solution *test = new Solution();
	auto result = test->medianSlidingWindow(input, k);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
