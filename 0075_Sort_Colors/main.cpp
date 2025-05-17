#include <Solution.h>

int main(void) {
	vector<int> input = {2, 0, 2, 1, 1, 0};
	Solution *test = new Solution();
	test->sortColors(input);
	for (const auto &iter : input) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
