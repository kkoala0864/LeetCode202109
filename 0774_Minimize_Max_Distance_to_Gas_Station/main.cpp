#include <Solution.h>

int main(void) {
	vector<int> input = {10,19,25,27,56,63,70,87,96,97};
	int k = 3;
	Solution *test = new Solution();
	cout << test->minmaxGasDist(input, k) << endl;
	return 0;
}
