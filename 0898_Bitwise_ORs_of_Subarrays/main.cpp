#include <Solution.h>

int main(void) {
	vector<int> input = {9,6,15};
	Solution *test = new Solution();
	cout << test->subarrayBitwiseORs(input) << endl;
	return 0;
}
