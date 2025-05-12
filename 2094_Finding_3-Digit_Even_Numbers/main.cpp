#include <Solution.h>

int main(void) {
	vector<int> input = {2,1,3,0};
	Solution *test = new Solution();
	auto result = test->findEvenNumbers(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
