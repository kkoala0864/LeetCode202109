#include <data_type.h>
#include <map>
#include <queue>
#include <algorithm>

using std::map;
using std::min;
using std::queue;

class MKAverage {
    public :
	MKAverage(int m, int k) : _m(m), _k(k){

	}

	void addElement(int num) {
		++m[num];
		que.emplace(num);
		while (que.size() > _m) {
			--m[que.front()];
			que.pop();
		}
	}

	int calculateMKAverage() {
		if (que.size() < _m) return -1;
		int size = _m - (2 * _k);
		auto tmp = m;
		auto iter = tmp.begin();
		int ksize = _k;
		int sum = 0;

		while (ksize > 0) {
			int v = min(ksize, iter->second);
			ksize -= v;
			iter->second -= v;
			if (iter->second == 0) ++iter;
		}
		while (size > 0) {
			int v = min(size, iter->second);
			size -= v;
			iter->second -= v;
			sum += (v * iter->first);
			if (iter->second == 0) ++iter;
		}
		return sum / (_m - (2 * _k));
	}
    private :
	int _m, _k;
	queue<int> que;
	map<int, int> m;
        virtual ~MKAverage() {}
        MKAverage& operator=(const MKAverage& source);
        MKAverage(const MKAverage&);
};

