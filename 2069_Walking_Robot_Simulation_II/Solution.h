#include <data_type.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Robot {
public:
	Robot() {}
	Robot(int width, int height) {
		m = width;
		n = height;
		curX = 0;
		curY = 0;
		curD = 0;
		mod = ((m-1) + (n-1)) * 2;
	}

	void step(int num) {
		while (num > 0) {
			int offset = 0;
			int postX = curX + (dir[curD][0] * num);
			int postY = curY + (dir[curD][1] * num);
			bool turn = false;
			if (curD == 0) {
				curX = min(m-1, postX);
				num = max(0, postX - curX);
				if (curX == m-1) turn = true;
			} else if (curD == 1) {
				curY = min(n-1, postY);
				num = max(0, postY - curY);
				if (curY == n-1) turn = true;
			} else if (curD == 2) {
				curX = max(0, postX);
				num = max(0, curX - postX);
				if (curX == 0) turn = true;
			} else {
				curY = max(0, postY);
				num = max(0, curY - postY);
				if (curY == 0) turn = true;
			}
			if (turn) {
				num %= mod;
				if (num > 0) {
					curD = (curD + 1) % 4;
				}
			}
		}
	}

	vector<int> getPos() {
		return vector<int>({curX, curY});
	}

	string getDir() {
		return dstr[curD];
	}
private:
	vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	vector<string> dstr = {"East", "North", "West", "South"};
	int curD;
	int curX;
	int curY;
	int mod;
	int m;
	int n;
	virtual ~Robot() {
	}
	Robot &operator=(const Robot &source);
	Robot(const Robot &);
};
