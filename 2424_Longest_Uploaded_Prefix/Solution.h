#include <data_type.h>
#include <vector>

using std::vector;

class LUPrefix {
public:
	LUPrefix() {
	}
	LUPrefix(int n) {
		size = n;
		cur = 0;
		v = vector<bool>(n + 1, false);
	}

	void upload(int video) {
		if (video > size)
			return;

		v[video] = true;
		while (cur < size) {
			if (v[cur + 1])
				++cur;
			else
				break;
		}
	}

	int longest() {
		return cur;
	}

private:
	int size;
	vector<bool> v;
	int cur;
	virtual ~LUPrefix() {
	}
	LUPrefix &operator=(const LUPrefix &source);
	LUPrefix(const LUPrefix &);
};
