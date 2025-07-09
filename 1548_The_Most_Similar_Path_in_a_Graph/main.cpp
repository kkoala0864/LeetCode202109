#include <Solution.h>

int main(void) {
	int n = 4;
	vector<vector<int>> roads = {{1,3},{3,0},{1,0},{0,2},{2,1}};
	vector<string> names = {"HSV","HSV","HSV","FAI"};
	vector<string> targetPath = {"HSV","HSV","HSV","HSV","HSV","FAI","HSV","HSV","HSV","HSV","FAI","FAI","HSV","FAI","HSV","HSV","HSV","HSV","HSV","HSV","FAI","HSV","HSV","HSV","HSV","HSV","HSV","HSV","HSV","HSV","HSV"};
	Solution *test = new Solution();
	auto result = test->mostSimilar(n, roads, names, targetPath);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
