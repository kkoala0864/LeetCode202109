#include <Solution.h>

int main(void) {
	vector<int> input = {4,2,3,1};
	Solution *test = new Solution();
	auto result = test->findBuildings(input);
	for (const auto& building : result) {
		cout << building << " ";
	}
	cout << endl;
	return 0;
}
