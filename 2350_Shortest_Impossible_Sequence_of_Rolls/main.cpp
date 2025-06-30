#include <Solution.h>

int main(void) {
	vector<int> rolls = {4,2,1,2,3,3,2,4,1};
	int k = 4;
	Solution *test = new Solution();
	cout << test->shortestSequence(rolls, k) << endl;
	return 0;
}
