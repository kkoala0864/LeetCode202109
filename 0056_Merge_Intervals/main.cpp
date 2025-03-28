#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 4}, {4, 5}};
	Solution *test = new Solution();
	/*
	vector<vector<int>> result = test->merge2(input);
	for (const auto iter : result) {
	        cout << "[ " << iter[0] << " : " << iter[1] << " ]" << endl;
	}
	cout << endl;
	*/
	vector<vector<int>> result2 = test->merge4(input);
	for (const auto iter : result2) {
		cout << "[ " << iter[0] << " : " << iter[1] << " ]" << endl;
	}
	return 0;
}
