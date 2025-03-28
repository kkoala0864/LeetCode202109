#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> v1 = {1, 3, 4};
	vector<int> v2 = {1, 3, 4};
	int k = 1;
	Solution *test = new Solution();
	cout << test->numberOfPairs(v1, v2, k) << endl;
	return 0;
}
