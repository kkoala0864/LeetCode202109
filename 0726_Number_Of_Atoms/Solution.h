#include <data_type.h>
#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	string countOfAtoms(string formula);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

