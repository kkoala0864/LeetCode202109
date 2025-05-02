#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class SnakeGame {
public:
	SnakeGame(int width, int height, vector<vector<int>> &food)
	    : _width(width),
	      _height(height), _food(food), _bodySize(1), _score(0), _foodIdx(0), _bodySet(), _body(1, {0, 0}) {
	}
	int move(string direction) {
		pair<int, int> nextAxis = _body.back();
		if (direction == "U")
			nextAxis.first -= 1;
		else if (direction == "D")
			nextAxis.first += 1;
		else if (direction == "L")
			nextAxis.second -= 1;
		else if (direction == "R")
			nextAxis.second += 1;

		if (nextAxis.first < 0 || nextAxis.first >= _height || nextAxis.second < 0 || nextAxis.second >= _width) {
			return -1;
		}

		if (_foodIdx < _food.size() && (_food[_foodIdx][0] == nextAxis.first) && (_food[_foodIdx][1] == nextAxis.second)) {
			++_foodIdx;
			++_bodySize;
			++_score;
		}

		_body.emplace_back(nextAxis);
		while (_body.size() > _bodySize) {
			_bodySet[_body.front().first].erase(_body.front().second);
			_body.pop_front();
		}

		if (_bodySet.count(nextAxis.first) && _bodySet[nextAxis.first].count(nextAxis.second)) {
			return -1;
		}

		_bodySet[nextAxis.first].emplace(nextAxis.second);

		return _score;
	}

private:
	int _width;
	int _height;
	deque<pair<int, int>> _body;
	int _bodySize;
	int _score;
	vector<vector<int>> _food;
	int _foodIdx;
	unordered_map<int, unordered_set<int>> _bodySet;
	virtual ~SnakeGame() {
	}
	SnakeGame &operator=(const SnakeGame &source);
	SnakeGame(const SnakeGame &);
};
