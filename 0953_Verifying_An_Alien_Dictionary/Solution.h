#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	bool isAlienSorted(vector<string>& words, string order);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

