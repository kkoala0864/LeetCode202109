#include <Solution.h>

int main(void) {
	vector<int> input = {2,1,3,3};
	int k = 2;
	Solution *test = new Solution();
	auto result = test->maxSubsequence(input, k);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
