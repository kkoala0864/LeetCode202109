#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<int> partitionLabels(string s);
	vector<int> partitionLabels2(string s);
	vector<int> partitionLabels3(string s);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

