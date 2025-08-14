#include <Solution.h>

int main(void) {
	vector<int> input = {2,5,1,4,3};
	Solution *test = new Solution();
	cout << test->maxBalancedShipments(input) << endl;
	return 0;
}
