#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,2,3,3,3};
	Solution *test = new Solution();
	cout << test->findLucky(input) << endl;
	return 0;
}
