#include <Solution.h>
#include <iostream>
#include <unordered_set>

struct hashFunc
{
	int operator()(const pair<int, int> &x) const {
		return x.first ^ x.second;
	}
};

vector<pair<int, int>> axis = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void goback(Robot &robot) {
	robot.turnLeft();
	robot.turnLeft();
	robot.move();
	robot.turnLeft();
	robot.turnLeft();
}

void dfs(Robot &robot, int x, int y, int d, unordered_set<pair<int, int>, hashFunc> &coordinate) {
	coordinate.insert({x, y});
	robot.clean();
	for (int k = 0; k < 4; ++k) {
		int newd = (d + k) % 4;
		int i = x + axis[newd].first;
		int j = y + axis[newd].second;
		if (coordinate.count({i, j}) == 0 && robot.move()) {
			dfs(robot, i, j, newd, coordinate);
			goback(robot);
		}
		robot.turnRight();
	}
}

void Solution::cleanRoom(Robot &robot) {
	unordered_set<pair<int, int>, hashFunc> coordinate;
	dfs(robot, 0, 0, 0, coordinate);
}
