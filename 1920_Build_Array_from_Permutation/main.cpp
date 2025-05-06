#include <Solution.h>

int main(void) {
	vector<int> input = {0,2,1,5,3,4};
	Solution *test = new Solution();
	auto result = test->buildArray(input);
	for (auto i : result) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
