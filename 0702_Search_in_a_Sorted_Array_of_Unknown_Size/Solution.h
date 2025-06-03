#include <data_type.h>

class ArrayReader {
	public:
		int get(int index);
};

class Solution {
public:
	Solution() {
	}
	int search(const ArrayReader& reader, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
