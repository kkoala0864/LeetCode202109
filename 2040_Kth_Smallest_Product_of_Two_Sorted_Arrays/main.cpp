#include <Solution.h>

int main(void) {
	vector<int> n1 = {-9,-4,1,6,8,8,9,10};
	vector<int> n2 = {-10,-10,-8,-8,1,3,6,6,8,10};
	int k = 29;
	Solution *test = new Solution();
	cout << test->kthSmallestProduct(n1, n2, k) << endl;
	return 0;
}
