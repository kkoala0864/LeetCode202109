#include <Solution.h>

int main(void) {
	vector<int> input1 = {-17,-31};
	vector<int> input2 = {-31,-17};
	Solution *test = new Solution();
	cout << test->minSplitMerge(input1, input2) << endl;
	return 0;
}
