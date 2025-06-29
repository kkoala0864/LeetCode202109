#include <Solution.h>

int main(void) {
	vector<int> input = {2,3,3,4,6,7};
	Solution *test = new Solution();
	cout << test->numSubseq(input, 12) << endl;
	return 0;
}
