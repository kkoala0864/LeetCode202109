#include <Solution.h>

int main(void) {
	vector<int> input = {3,4,1,1,0,0};
	int n = 5;
	Solution *test = new Solution();
	cout << test->minTaps(n, input) << endl;
	return 0;
}
