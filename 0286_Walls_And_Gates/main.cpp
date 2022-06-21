#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    Solution* test = new Solution();
    test->wallsAndGates(input);
    for (const auto& vec : input) {
	for (const auto& val : vec) {
		cout << val << " ";
	}
	cout << endl;
    }
    cout << endl;
    return 0;
}

