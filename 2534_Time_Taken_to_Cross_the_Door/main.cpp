#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> arrival = {0, 1, 1, 2, 4};
	vector<int> state = {0, 1, 0, 0, 1};
	Solution *test = new Solution();
	auto result = test->timeTaken(arrival, state);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
