#include <Solution.h>

int main(void) {
	vector<int> input = {10,6,8,5,11,9};
	Solution *test = new Solution();
	auto result = test->canSeePersonsCount(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
