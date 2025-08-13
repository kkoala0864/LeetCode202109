#include <Solution.h>

int main(void) {
	vector<int> value = {4,1,5,2};
	vector<int> limit = {3,3,2,3};
	Solution *test = new Solution();
	cout << test->maxTotal(value, limit) << endl;
	return 0;
}
