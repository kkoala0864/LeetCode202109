#include <Solution.h>

int main(void) {
	vector<int> input = {4,4,4,4};
	int k = 1;
	Solution *test = new Solution();
	cout << test->maxDistinctElements(input, k) << endl;
	return 0;
}
