#include <map>
#include <algorithm>

using std::max;
using std::min;
using std::map;

class CountIntervals {
	public:
		CountIntervals() {
			_cnt = 0;
		}

		void add(int left, int right) {
			int i = 0;

			if (!_itv.empty() && !(right < _itv.begin()->first || left > _itv.rbegin()->second)) {
				for (auto& iter : _itv) {
					if (iter.second < left) continue;
					if (iter.first > right) break;
					if (iter.first <= right) {
						left = min(iter.first, left);
						right = max(iter.second, right);
						_cnt -= (iter.second - iter.first + 1);
						_itv.erase(iter.first);
					}
				}
			}

			_itv[left] = right;
			_cnt += (right - left + 1);
		}

		int count() {
			return _cnt;
		}
	private:
		map<int, int> _itv;
		int _cnt;
		virtual ~CountIntervals() {}
		CountIntervals& operator=(const CountIntervals& source);
		CountIntervals(const CountIntervals&);
};

