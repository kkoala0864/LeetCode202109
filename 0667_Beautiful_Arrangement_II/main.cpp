#include <Solution.h>

int main(void) {
	int n = 3;
	int k = 2;
	Solution *test = new Solution();
	auto result = test->constructArray(n, k);
	for (const auto& v : result) cout << v << " " ;
	cout << endl;
	return 0;
}
