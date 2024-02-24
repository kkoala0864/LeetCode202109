#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> secret = {{3,4,2},{1,2,1},{2,3,1}};
	Solution* test = new Solution();
	auto result = test->findAllPeople(5, secret, 1);

	for (const auto& p : result) {
		cout << p << " ";
	}
	cout << endl;
	return 0;
}

