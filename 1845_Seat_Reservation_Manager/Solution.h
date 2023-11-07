#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class SeatManager {
    public :
        SeatManager() {}
	SeatManager(int n) {
		for (int i = 1 ; i <= n ; ++i) a.emplace(i);
	}

	int reserve() {
		int result = a.top();
		a.pop();
		return result;
	}

	void unreserve(int seatNumber) {
		a.emplace(seatNumber);

	}
    private :
	priority_queue<int, vector<int>, std::greater<int>> a;
        virtual ~SeatManager() {}
        SeatManager& operator=(const SeatManager& source);
        SeatManager(const SeatManager&);
};

