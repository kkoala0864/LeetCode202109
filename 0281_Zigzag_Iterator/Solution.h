#include <data_type.h>
#include <vector>

using std::vector;

class ZigzagIterator {
public:
	ZigzagIterator() {
	}
	ZigzagIterator(vector<int> &v1, vector<int> &v2) {
		v.emplace_back(v1);
		v.emplace_back(v2);
		x = 0;
		y = 0;
		cnt = 0;
		total = x.size() + y.size();
		if (cnt < total) {
			while (x == 2 || y >= v[x].size()) {
				if (x == 2) {
					++y;
					x = 0;
				} else {
					++x;
				}
			}
		}
	}

	int next() {
		int ret = v[x][y];
		++cnt;
		++x;
		if (cnt < total) {
			while (x == 2 || y >= v[x].size()) {
				if (x == 2) {
					++y;
					x = 0;
				} else {
					++x;
				}
			}
		}
		return ret;
	}

	bool hasNext() {
		return cnt < total;
	}

private:
	int x, y;
	vector<vector<int>> v;
	int total;
	int cnt = 0;
	virtual ~ZigzagIterator() {
	}
	ZigzagIterator &operator=(const ZigzagIterator &source);
	ZigzagIterator(const ZigzagIterator &);
};
