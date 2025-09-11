#include <Solution.h>

int main(void) {
	int n = 2;
	Solution *test = new Solution();
	auto result = test->getNoZeroIntegers(n);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
