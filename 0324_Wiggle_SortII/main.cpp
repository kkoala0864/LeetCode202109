#include <Solution.h>

int main(void) {
	vector<int> input = {1, 5, 1, 1, 6, 4};
	Solution *test = new Solution();
	test->wiggleSort(input);
	for (const auto &v : input)
		cout << v << " ";
	cout << endl;
	return 0;
}
