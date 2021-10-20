#include <vector>
#include <string>
#include <deque>

using std::vector;
using std::string;
using std::deque;

class SnakeGame {
    public :
	    SnakeGame(int width, int height, vector<vector<int>>& food) : _width(width),
	    _height(height), _food(food), _bodySize(1), _score(0), _foodIdx(0) {
		    vector<int> init = {0, 0};
		    _body.emplace_back(init);
	    }
	    int move(string direction) {
		    vector<int> nextAxis = _body.back();
		    if (direction == "U") nextAxis[0] -= 1;
		    else if (direction == "D") nextAxis[0] += 1;
		    else if (direction == "L") nextAxis[1] -= 1;
		    else if (direction == "R") nextAxis[1] += 1;

		    if (nextAxis[0] < 0 || nextAxis[0] >= _height || nextAxis[1] < 0 || nextAxis[1] >= _width) return -1;
		    for (int i = 1 ; i < _body.size() ; ++i) if ((nextAxis[0] == _body[i][0]) && (nextAxis[1] == _body[i][1])) return -1;

		    _body.emplace_back(nextAxis);
		    if (_foodIdx < _food.size() && (_food[_foodIdx][0] == nextAxis[0]) && (_food[_foodIdx][1] == nextAxis[1])) {
			++_foodIdx;
			++_bodySize;
			++_score;
		    }

		    if (_body.size() > _bodySize) _body.pop_front();

		    return _score;
	    }
    private :
	    int _width;
	    int _height;
	    deque<vector<int>> _body;
	    int _bodySize;
	    int _score;
	    vector<vector<int>> _food;
	    int _foodIdx;
	    virtual ~SnakeGame() {}
	    SnakeGame& operator=(const SnakeGame& source);
	    SnakeGame(const SnakeGame&);
};

