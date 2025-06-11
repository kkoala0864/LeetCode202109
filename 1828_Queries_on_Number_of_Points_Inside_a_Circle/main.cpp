#include <Solution.h>

int main(void) {
	vector<vector<int>> points = {{1,3},{3,3},{5,3},{2,2}};
	vector<vector<int>> queries = {{2,3,1},{4,3,1},{1,1,2}};
	Solution *test = new Solution();
	vector<int> result = test->countPoints(points, queries);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
