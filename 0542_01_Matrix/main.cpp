#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,0,0},{0,1,0},{1,1,1}};
	Solution* test = new Solution();
	auto result = test->updateMatrix(input);
	for (int i = 0 ; i < result.size() ; ++i) {
		for (int j = 0 ; j < result[0].size() ; ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	result = test->updateMatrix2(input);
	for (int i = 0 ; i < result.size() ; ++i) {
		for (int j = 0 ; j < result[0].size() ; ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

