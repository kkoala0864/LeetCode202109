#include <Solution.h>

int main(void) {
	vector<int> input = {2,3,4,7,9};
	Solution *test = new Solution();
	cout << test->minJumps(input) << endl;
	return 0;
}
