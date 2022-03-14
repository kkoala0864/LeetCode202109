#include <vector>
#include <string>
#include <list>
#include <vector>

using std::string;
using std::vector;
using std::list;

class SnakeGame {
    public :
	    SnakeGame(int width, int height, vector<vector<int>>& food) :
		    _width(width), _height(height), _food(food), _fIdx(0) {
		    _body = list<vector<int>>();
		    _body.push_front({0,0});
	    }

	    int move(string direction) {
		    vector<int> cur = _body.front();
		    switch (direction[0]) {
			case 'L' :
				cur[1] -= 1;
				break;
			case 'R' :
				cur[1] += 1;
				break;
			case 'U' :
				cur[0] -= 1;
				break;
			case 'D' :
				cur[0] += 1;
				break;
			default :
				break;
		    }

		    if (cur[0] >= 0 && cur[0] < _height && cur[1] >= 0 && cur[1] < _width) {
			if (_fIdx < _food.size() && _food[_fIdx][0] == cur[0] && _food[_fIdx][1] == cur[1]) ++_fIdx;
			else _body.pop_back();
			for (const auto& iter : _body) {
				if (iter[0] == cur[0] && iter[1] == cur[1]) return -1;
			}
			_body.push_front(cur);
			return _fIdx;
		    } else {
			return -1;
		    }
	    }
    private :
	    int _width, _height, _fIdx;
	    list<vector<int>> _body;
	    vector<vector<int>> _food;

	    virtual ~SnakeGame() {}
	    SnakeGame& operator=(const SnakeGame& source);
	    SnakeGame(const SnakeGame&);
};

