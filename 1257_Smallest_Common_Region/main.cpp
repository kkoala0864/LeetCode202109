#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<string>> regions = {{"zDkA", "GfAj", "lt"}, {"GfAj", "rtupD", "og", "l"}, {"rtupD", "IT", "jGcew", "ZwFqF"}, {"og", "yVobt", "EjA", "piUyQ"}, {"IT", "XFlc", "W", "rB"}, {"l", "GwQg", "shco", "Dub", "KwgZq"}, {"jGcew", "KH", "lbW"}, {"KH", "BZ", "sauG"}, {"yVobt", "Aa", "lJRmv"}, {"BZ", "v", "zh", "oGg", "WP"}, {"XFlc", "Sn", "ftXOZ"}, {"sauG", "If", "nK", "HHOr", "yEH", "YWMgF"}, {"GwQg", "Mfb", "gr", "S", "nQ"}, {"shco", "xsUkW"}, {"xsUkW", "Cssa", "TgPi", "qx"}, {"v", "SAH", "Rjr"}, {"lt", "Q", "fWB", "a", "Wk", "zpqU"}, {"If", "e", "y", "quEA", "sNyV"}, {"piUyQ", "G", "aTi"}, {"Sn", "rVIh", "twv", "pYA", "Ywm"}, {"zh", "PWeEf"}, {"Mfb", "GEs", "XjpeC", "p"}, {"GEs", "oXMG", "tNJYJ"}, {"SAH", "bmFhM"}, {"bmFhM", "SOvB", "RWsEM", "z"}, {"SOvB", "iD", "pLGYN", "Zqk"}, {"Dub", "PnGPY"}, {"a", "TekG", "zp"}, {"XjpeC", "vK", "aaO", "D"}, {"pLGYN", "ldb"}, {"oGg", "x"}, {"nQ", "IOw"}, {"Aa", "wmYF"}, {"Zqk", "th"}, {"ZwFqF", "GDl"}, {"th", "JyOSt", "ALlyw"}, {"lbW", "M"}, {"yEH", "UY", "GIwLp"}, {"JyOSt", "i"}, {"x", "dclJ"}, {"wmYF", "xreBK"}, {"PnGPY", "Ev", "lI"}, {"ALlyw", "jguyA", "Mi"}, {"oXMG", "uqe"}, {"sNyV", "WbrP"}};
	string regions1 = "RWsEM";
	string regions2 = "GfAj";
	Solution *test = new Solution();
	cout << test->findSmallestRegion(regions, regions1, regions2) << endl;
	return 0;
}
