#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"jump","add","add","jump","add","jump"};
	vector<int> value = {2,1,3,1,-2,-3};
	Solution *test = new Solution();
	cout << test->calculateScore(input, value) << endl;
	return 0;
}
