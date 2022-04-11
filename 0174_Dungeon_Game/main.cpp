#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    vector<vector<int>> input = {{-3, 5}};
    Solution* test = new Solution();
    cout << test->calculateMinimumHP(input) << endl;
    cout << test->calculateMinimumHP2(input) << endl;
    return 0;
}

