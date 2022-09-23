#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {1,2,3,4};
	vector<vector<int>> quries = {{1,0},{-3,1},{-4,0},{2,3}};
	Solution* test = new Solution();
	auto result = test->sumEvenAfterQueries(nums, quries);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

