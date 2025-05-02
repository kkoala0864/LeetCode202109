#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	// ["SnakeGame","move","move","move","move","move","move","move","move","move","move","move","move"]
	// [[3,3,[[2,0],[0,0],[0,2],[2,2]]],["D"],["D"],["R"],["U"],["U"],["L"],["D"],["R"],["R"],["U"],["L"],["D"]]
	vector<vector<int>> food = {{2, 0}, {0, 0}, {0, 2}, {2, 2}};
	SnakeGame * test = new SnakeGame(3, 3, food);
	cout << test->move("D") << endl;
	cout << test->move("D") << endl;
	cout << test->move("R") << endl;
	cout << test->move("U") << endl;
	cout << test->move("U") << endl;
	cout << test->move("L") << endl;
	cout << test->move("D") << endl;
	cout << test->move("R") << endl;
	cout << test->move("R") << endl;
	cout << test->move("U") << endl;
	cout << test->move("L") << endl;
	cout << test->move("D") << endl;
	return 0;
}
