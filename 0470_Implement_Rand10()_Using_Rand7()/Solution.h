#include <data_type.h>

class Solution {
    public :
        Solution() {}
	int rand10() {
		int col, row, idx;
		do {
			col = rand7();
			row = rand7();
			idx = col + (row - 1) * 7;
		} while (idx > 40);
		return 1 + (idx - 1) % 10;
	}
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

