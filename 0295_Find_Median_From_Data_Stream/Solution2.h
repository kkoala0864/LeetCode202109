#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;
using std::greater;

class MedianFinder {
    public :
	MedianFinder() : count(0) {}

	void addNum(int num) {
		++count;
		maxHeap.emplace(num);
		minHeap.emplace(maxHeap.top());
		maxHeap.pop();
		if ((minHeap.size() - maxHeap.size()) > 1) {
			maxHeap.emplace(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian() {
		return count & 1 ? minHeap.top() : ((double) minHeap.top() + (double) maxHeap.top()) / 2;
	}

    private :
        virtual ~MedianFinder() {}
	int count;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
        MedianFinder& operator=(const MedianFinder& source);
        MedianFinder(const MedianFinder&);
};

