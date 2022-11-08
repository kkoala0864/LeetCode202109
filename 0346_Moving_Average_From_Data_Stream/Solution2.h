#include <queue>
using std::queue;

class MovingAverage {
    public :
	MovingAverage() {}
	MovingAverage(int size) {
		this->size = size;
		total = 0;
	}

	double next(int val) {
		que.emplace(val);
		total += val;
		if (que.size() > size) {
			total -= que.front();
			que.pop();
		}
		return total / (double)que.size();
	}
    private :
	double total;
	int size;
	queue<int> que;
        virtual ~MovingAverage() {}
        MovingAverage& operator=(const MovingAverage& source);
        MovingAverage(const MovingAverage&);
};

