#include <Solution.h>

int main(void) {
	vector<int> input = {5,2,-10,-5,1};
	int k = 3;
	Solution *test = new Solution();
	cout << test->maximumEnergy(input, k) << endl;
	return 0;
}
