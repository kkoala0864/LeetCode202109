#include <Solution.h>

int main(void) {
	vector<int> input = {1,10,1,1};
	Solution *test = new Solution();
	cout << test->minimumCoins(input) << endl;
	return 0;
}
