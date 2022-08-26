#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> manager = {1,2,3,4,5,6,-1};
    vector<int> informTime = {0,6,5,4,3,2,1};
    cout << test->numOfMinutes(7, 6, manager, informTime) << endl;
    cout << test->numOfMinutes2(7, 6, manager, informTime) << endl;
    return 0;
}

