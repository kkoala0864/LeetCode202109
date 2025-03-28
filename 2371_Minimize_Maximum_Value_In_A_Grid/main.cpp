#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{920212616, 142237098, 345501974, 533487831, 269413793, 819692083, 469106291, 483049590, 63489034, 58052923}};
	Solution *test = new Solution();
	auto result = test->minScore(input);
	for (const auto &iter : result) {
		for (const auto &val : iter) {
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
