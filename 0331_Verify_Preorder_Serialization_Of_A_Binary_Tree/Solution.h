#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	bool isValidSerialization(string preorder);
	bool isValidSerialization2(string preorder);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

