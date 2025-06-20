#include <Solution.h>

int main(void) {
	vector<vector<char>> seats = {{'#','.','#','#','.','#'},
	{'.','#','#','#','#','.'},
	{'#','.','#','#','.','#'}};
	Solution *test = new Solution();
	cout << test->maxStudents(seats) << endl;
	return 0;
}
