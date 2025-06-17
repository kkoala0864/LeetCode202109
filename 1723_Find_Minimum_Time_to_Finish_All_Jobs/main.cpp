#include <Solution.h>

int main(void) {
	vector<int> input = {10001,10002,10003,10004,10005,10006,10007,10008,10009,10010,10011,1000000};
	int k = 11;
	Solution *test = new Solution();
	cout << test->minimumTimeRequired(input, k) << endl;
	return 0;
}
