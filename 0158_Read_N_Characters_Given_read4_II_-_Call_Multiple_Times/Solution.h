#include <data_type.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	Solution() {
	}
	int read(char *buf, int n) {
		int i = 0;
		while (i < n && (i4 < n4 || (i4 = 0) < (n4 = read4(buf4)))) {
			buf[i++] = buf4[i4++];
		}
		return i;
	}
	int i4 = 0;
	int n4 = 0;
	char buf4[4];

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
