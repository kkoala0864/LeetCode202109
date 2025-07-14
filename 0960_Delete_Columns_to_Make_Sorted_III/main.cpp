#include <Solution.h>

int main(void) {
	vector<string> input = {"babca","bbazb"};
	Solution *test = new Solution();
	cout << test->minDeletionSize(input) << endl;
	return 0;
}
