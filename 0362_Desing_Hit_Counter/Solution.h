#include <deque>

using std::deque;

class HitCounter {
    public :
	HitCounter() {
		list = deque<int>();
		cnt = 0;
	}

	void hit(int timestamp) {
		list.emplace_back(timestamp);
		++cnt;
	}

	int getHits(int timestamp) {
		while (!list.empty() && timestamp - list.front() >= 300) {
			list.pop_front();
			--cnt;
		}
		return cnt;
	}
    private :
	deque<int> list;
	int cnt;
        virtual ~HitCounter() {}
        HitCounter& operator=(const HitCounter& source);
        HitCounter(const HitCounter&);
};

