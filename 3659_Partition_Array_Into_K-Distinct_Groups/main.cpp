#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,3,4};
	int k = 2;
	Solution *test = new Solution();
	cout << test->partitionArray(input, k) << endl;
	return 0;
}
