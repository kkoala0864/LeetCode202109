#include <Solution.h>
#include <iostream>

using std::to_string;

string Solution::discountPrices(string sentence, int discount) {
	string result("");
	for (int i = 0 ; i < sentence.size() ; ++i) {
		if (sentence[i] != '$') result.push_back(sentence[i]);
		else {
			result.push_back('$');
			++i;
			string price("");
			bool isNum = true;
			while (i < sentence.size() && sentence[i] != ' ') {
				if (sentence[i] < '0' || sentence[i] > '9') isNum = false;
				price.push_back(sentence[i++]);
			}
			if (!isNum) {
				result += price;
			} else if (!price.empty()) {
				if (discount == 100) result += "0.00";
				else {
					long pInt = stol(price);
					long double disPrice = (long double) pInt * (long double)(100 - discount) * 0.01;
					string dpStr = to_string(disPrice);
					size_t loc = dpStr.find(".");
					if (loc != std::string::npos) dpStr = dpStr.substr(0, loc + 3);
					result += dpStr;
				}
			}
			--i;
		}
	}
	return result;
}
