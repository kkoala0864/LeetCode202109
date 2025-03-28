#include <data_type.h>
#include <unordered_map>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;
using std::vector;

class DetectSquares {
public:
	DetectSquares() {
	}

	void add(vector<int> point) {
		++m[point[0]][point[1]];
	}

	int count(vector<int> point) {
		int result = 0;
		for (const auto &r : m) {
			if (r.first == point[0])
				continue;
			for (const auto &c : r.second) {
				if (c.first == point[1])
					continue;
				if (abs(c.first - point[1]) != abs(r.first - point[0]))
					continue;
				result += (c.second * m[r.first][point[1]] * m[point[0]][c.first]);
			}
		}
		return result;
	}

private:
	unordered_map<int, unordered_map<int, int>> m;
	virtual ~DetectSquares() {
	}
	DetectSquares &operator=(const DetectSquares &source);
	DetectSquares(const DetectSquares &);
};
