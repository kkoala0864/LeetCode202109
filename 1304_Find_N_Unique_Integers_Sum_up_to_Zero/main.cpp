#include <Solution.h>

int main(void) {
	int n = 5;
	Solution *test = new Solution();
	auto result = test->sumZero(n);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
