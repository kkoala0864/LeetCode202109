#include <Solution.h>

int main(void) {
	vector<int> input = {84,93,100,77,90};
	int k = 3;
	Solution *test = new Solution();
	auto result = test->maxKDistinct(input, k);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
