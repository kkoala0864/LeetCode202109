#include <Solution.h>

int main(void) {
	vector<int> input = {3,2,4,1};
	int k = 2;
	Solution *test = new Solution();
	cout << test->mergeStones(input, k) << endl;
	return 0;
}
