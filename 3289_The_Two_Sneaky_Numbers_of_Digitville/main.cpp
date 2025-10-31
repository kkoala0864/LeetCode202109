#include <Solution.h>

int main(void) {
	vector<int> input = {0,1,1,0};
	Solution *test = new Solution();
	auto result = test->getSneakyNumbers(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
