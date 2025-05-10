#include <Solution.h>

int main(void) {
	vector<int> input = {3,4,16,8};
	Solution *test = new Solution();
	vector<int> result = test->largestDivisibleSubset(input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
