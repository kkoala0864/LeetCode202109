#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<vector<int>> input = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution* test = new Solution();
    cout << test->calculateMinimumHP(input) << endl;
    return 0;
}

