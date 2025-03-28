#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	/*
	vector<vector<int>> result = test->getFactors(32);
	for (const auto& iter : result) {
	    for (const auto& it : iter) {
	            cout << it << " ";
	    }
	    cout << endl;
	}
	cout << endl;*/
	auto result = test->getFactors2(32);
	for (const auto &iter : result) {
		for (const auto &it : iter) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}
