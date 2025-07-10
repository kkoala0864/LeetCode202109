#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,3,4};
	int time = 1;
	Solution *test = new Solution();
	auto result = test->goodDaysToRobBank(input, time);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
