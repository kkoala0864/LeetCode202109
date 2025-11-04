#include <Solution.h>

int main(void) {
	vector<int> input = {1,1,2,2,3,4,2,3};
	int k = 6;
	int x = 2;
	Solution *test = new Solution();
	auto result = test->findXSum(input, k, x);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
