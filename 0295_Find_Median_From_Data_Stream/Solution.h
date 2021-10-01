#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;
using std::greater;

class MedianFinder {
    public :
	MedianFinder() : _count(0) {
	}

	void addNum(int num) {
		++_count;
		_maxHeap.emplace(num);
		_minHeap.emplace(_maxHeap.top());
		_maxHeap.pop();

		if ((_minHeap.size() - _maxHeap.size()) > 1) {
			_maxHeap.emplace(_minHeap.top());
			_minHeap.pop();
		}
	}

	double findMedian() {
		return _count & 1 ? _minHeap.top() : ((double)_minHeap.top() + (double)_maxHeap.top()) / 2;
	}

    private :
	int _count;
	priority_queue<int, vector<int>, greater<int>> _minHeap;
	priority_queue<int> _maxHeap;
        virtual ~MedianFinder() {}
        MedianFinder& operator=(const MedianFinder& source);
        MedianFinder(const MedianFinder&);
};

