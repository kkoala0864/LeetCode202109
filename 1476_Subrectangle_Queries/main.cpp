#include <Solution.h>

int main(void) {
	// ["SubrectangleQueries","getValue","updateSubrectangle","getValue","getValue","updateSubrectangle","getValue","getValue"]
	// [[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],[3,0,3,2,10],[3,1],[0,2]]
	vector<vector<int>> rectangle = {{1,2,1},{4,3,4},{3,2,1},{1,1,1}};
	SubrectangleQueries *test = new SubrectangleQueries(rectangle);
	cout << test->getValue(0, 2) << endl;
	test->updateSubrectangle(0, 0, 3, 2, 5);
	cout << test->getValue(0, 2) << endl;
	cout << test->getValue(3, 1) << endl;
	test->updateSubrectangle(3, 0, 3, 2, 10);
	cout << test->getValue(3, 1) << endl;
	cout << test->getValue(0, 2) << endl;
	return 0;
}
