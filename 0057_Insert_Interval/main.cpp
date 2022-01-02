#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,3},{7,10}};
	vector<int> insertVal = {4,6};
	Solution* test = new Solution();
	//auto result = test->insert(input, insertVal);
	//for (const auto iter : result) {
	//	cout << iter[0] << " : " << iter[1] << endl;
	//}

	//cout << endl;
	auto result = test->insert4(input, insertVal);
	for (const auto iter : result) {
		cout << iter[0] << " : " << iter[1] << endl;
	}
	return 0;
}

