#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> positions = {5, 4, 3, 2, 1};
	vector<int> healths = {2, 17, 9, 15, 10};
	string directions = "RRRRR";
	Solution *test = new Solution();
	auto result = test->survivedRobotsHealths(positions, healths, directions);
	for (const auto &c : result)
		cout << c << " ";
	cout << endl;
	return 0;
}
