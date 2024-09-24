#include <data_type.h>
#include <vector>

using std::vector;

struct tNode {
	vector<tNode*> child;
	tNode() {
		child = vector<tNode*>(10, nullptr);
	}
};

class Solution {
    public :
        Solution() {}
	int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

