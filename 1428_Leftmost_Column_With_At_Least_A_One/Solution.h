#include <vector>

using std::vector;

class BinaryMatrix {
	public:
		int get(int row, int col);
		vector<int> dimensions();
};

class Solution {
    public :
        Solution() {}
	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

