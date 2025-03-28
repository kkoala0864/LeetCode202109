#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5, 11, 20, 20};
	int k = 5;
	int operations = 1;
	Solution *test = new Solution();
	cout << test->maxFrequency(input, k, operations) << endl;
	return 0;
}
