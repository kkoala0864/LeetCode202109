#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	string subStrHash(string s, int power, int modulo, int k, int hashValue);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

