#include <Solution.h>

int main(void) {
	string input = "0";
	Solution *test = new Solution();
	auto result = test->diffWaysToCompute(input);
	for (auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
