#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	string multiply(string num1, string num2);
	string multiply2(string num1, string num2);
	string multiply3(string num1, string num2);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

