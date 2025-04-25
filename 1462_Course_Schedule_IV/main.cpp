#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int numCourses = 5;
	vector<vector<int>> prerequisites = {{4,3},{4,1},{4,0},{3,2},{3,1},{3,0},{2,1},{2,0},{1,0}};
	vector<vector<int>> queries = {{1,4},{4,2},{0,1},{4,0},{0,2},{1,3},{0,1}};
	Solution* test = new Solution();
	vector<bool> result = test->checkIfPrerequisite(numCourses, prerequisites, queries);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

