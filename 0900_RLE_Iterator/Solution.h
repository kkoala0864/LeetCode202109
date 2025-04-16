#include <data_type.h>
#include <vector>

using namespace std;

class RLEIterator {
public:
	RLEIterator(vector<int> &encoding) : _enc(encoding) {
	}

	int next(int n) {
		if (vIdx >= _enc.size())
			return -1;
		int ret = 0;
		while (vIdx < _enc.size() && n > 0) {
			int v = min(n, _enc[cIdx]);
			n -= v;
			_enc[cIdx] -= v;
			ret = _enc[vIdx];
			if (_enc[cIdx] == 0) {
				cIdx += 2;
				vIdx += 2;
			}
		}
		if (n > 0)
			return -1;
		else
			return ret;
	}

private:
	int cIdx = 0;
	int vIdx = 1;
	vector<int> &_enc;
	virtual ~RLEIterator() {
	}
	RLEIterator &operator=(const RLEIterator &source);
	RLEIterator(const RLEIterator &);
};
