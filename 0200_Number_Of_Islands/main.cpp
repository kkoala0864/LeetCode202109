#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> grid = {
		    {'1','1','0','0','0'},
		    {'1','1','0','0','0'},
		    {'0','0','1','0','0'},
		    {'0','0','0','1','1'}
	};
    Solution* test = new Solution();
    cout << test->numIslands(grid) << endl;
    return 0;
}

