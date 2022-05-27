#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,100};
	Solution* test = new Solution();
	cout << test->maximumGap(input) << endl;
	cout << test->BucketSort(input) << endl;
	return 0;
}

