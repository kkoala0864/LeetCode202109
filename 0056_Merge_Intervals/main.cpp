#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
	Solution* test = new Solution();
	vector<vector<int>> result = test->merge2(input);
	for (const auto iter : result) {
		cout << "[ " << iter[0] << " : " << iter[1] << " ]" << endl;
	}
	return 0;
}

