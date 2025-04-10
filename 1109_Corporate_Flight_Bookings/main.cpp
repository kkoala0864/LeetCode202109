#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2,10},{2,3,20},{2,5,25}};
	int n = 5;
	Solution *test = new Solution();
	auto result = test->corpFlightBookings(input, n);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
