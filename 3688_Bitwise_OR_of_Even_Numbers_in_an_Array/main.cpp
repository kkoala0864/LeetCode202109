#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,3,4,5,6};
	Solution *test = new Solution();
	cout << test->evenNumberBitwiseORs(input) << endl;
	return 0;
}
