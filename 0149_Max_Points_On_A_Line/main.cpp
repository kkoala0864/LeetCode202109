#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> input = {{1,1},{2,2},{3,3}};
    cout << test->maxPoints(input) << endl;
    return 0;
}

