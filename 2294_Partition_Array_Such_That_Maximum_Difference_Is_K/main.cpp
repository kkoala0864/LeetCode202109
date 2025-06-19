#include <Solution.h>

int main(void) {
	vector<int> input = {2, 2, 4, 5};
	int k = 0;
	Solution *test = new Solution();
	cout << test->partitionArray(input, k) << endl;
	return 0;
}
