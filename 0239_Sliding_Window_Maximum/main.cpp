#include <Solution.h>

int main(void) {
	vector<int> input = {1,3,1,2,0,5};
	int k = 3;
	Solution *test = new Solution();
	auto result = test->maxSlidingWindow(input, k);
	for (const auto &val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
