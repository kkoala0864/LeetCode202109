#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> mat1 = {{1,0,0},{-1,0,3}};
	vector<vector<int>> mat2 = {{7,0,0},{0,0,0},{0,0,1}};
	Solution* test = new Solution();
	auto result = test->multiply2(mat1, mat2);
	for (const auto& outer : result) {
		for (const auto& iter : outer) {
			cout << iter << " ";
		}
		cout << endl;
	}
	return 0;
}

