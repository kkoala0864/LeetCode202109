#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,2,1,2,2,1,2,2};
	int k = 2;
	Solution *test = new Solution();
	cout << test->maximizeSweetness(input, k) << endl;
	return 0;
}
