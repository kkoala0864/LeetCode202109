#include <Solution.h>

int main(void) {
	vector<int> input = {2,4,1,1,6,5};
	Solution *test = new Solution();
	cout << test->countHillValley(input) << endl;
	return 0;
}
