#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "AFFFFA";
	vector<string> words = {"ADA","ADC","ADB","AEA","AEC","AEB","AFA","AFC","AFB","CDA","CDC","CDB","CEA","CEC","CEB","CFA","CFC","CFB","BDA","BDC","BDB","BEA","BEC","BEB","BFA","BFC","BFB","DAA","DAC","DAB","DCA","DCC","DCB","DBA","DBC","DBB","EAA","EAC","EAB","ECA","ECC","ECB","EBA","EBC","EBB","FAA","FAC","FAB","FCA","FCC","FCB","FBA","FBC","FBB","DDA","DDC","DDB","DEA","DEC","DEB","DFA","DFC","DFB","EDA","EDC","EDB","EEA","EEC","EEB","EFA","EFC","EFB","FDA","FDC","FDB","FEA","FEC","FEB","FFA","FFC","FFB","DDD","DDE","DDF","DED","DEE","DEF","DFD","DFE","DFF","EDD","EDE","EDF","EED","EEE","EEF","EFD","EFE","EFF","FDD","FDE","FDF","FED","FEE","FEF","FFD","FFE","FFF"};
	Solution* test = new Solution();
	cout << test->pyramidTransition(input, words) << endl;
	return 0;
}

