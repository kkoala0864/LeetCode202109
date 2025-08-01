#include <Solution.h>

int main(void) {
	Solution *test = new Solution();
	auto result = test->generate(5);
	for (const auto &vec : result) {
		for (const auto &val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
