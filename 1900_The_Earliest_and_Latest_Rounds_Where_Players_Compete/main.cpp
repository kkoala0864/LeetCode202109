#include <Solution.h>

int main(void) {
	int n = 11;
	int firstPlayer = 2;
	int secondPlayer = 4;
	Solution *test = new Solution();
	auto result = test->earliestAndLatest(n, firstPlayer, secondPlayer);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
