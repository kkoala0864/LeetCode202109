#include <deque>
using std::deque;

class MovingAverage {
    public :
	MovingAverage() {}
	MovingAverage(int size) {
		_size = size;
		_curSum = 0;
	}

	double next(int val) {
		if (_element.size() >= _size) {
			_curSum -= _element.front();
			_element.pop_front();
		}
		_element.emplace_back(val);
		_curSum += val;
		return _curSum / (double)_element.size();
	}
    private :
	int _curSum;
	int _size;
	deque<int> _element;
        virtual ~MovingAverage() {}
        MovingAverage& operator=(const MovingAverage& source);
        MovingAverage(const MovingAverage&);
};

