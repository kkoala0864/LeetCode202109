#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,4,2,1,5};
	int k = 857;
	Solution *test = new Solution();
	cout << test->countPartitions(input, k) << endl;
	return 0;
}
