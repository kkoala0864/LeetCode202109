#include <Solution.h>

int main(void) {
	vector<int> input = {1,0,2,0,3};
	Solution *test = new Solution();
	cout << test->countValidSelections(input) << endl;
	return 0;
}
