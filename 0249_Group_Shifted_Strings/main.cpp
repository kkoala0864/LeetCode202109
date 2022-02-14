#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"xzv","tvhmtraayghfabutim","scruzaydxrapcuv","xiznzqqjbetchvhndzz","qmbkbjpkxzmnwvo","tttwsszaetyzgsaprv","xdhbxxxomhagohdvdyv","khugdmdbbqjbeuxq","xzzqnowcyplkdxgkbbb","daxzqsdcfuymlyevyfnayb","nrlalrdjqqckogfqlhfhg","akpellndulbbbipbvatbu","pfqeu","dneng","rjnvgxk","eujibxcxetdjztn","aufkyfjuruaq","izeqjoftsfzjkujiubkrb","dwzuyrospzjzuckk","kcuxsetkmzkq","lvej","lzefktml","varaxwjxf","cwdqxivcxeyzhsvqccy","kzxlrqbabvtvkfajbjatzyix","husuheaiirzowtiadgtxwf","swtja","ddvxhgesuenqdgutm","uaduv","t","yvwfcproumulvnbva","ddjikfsnasyj","tqxiqlqkxbmwuytempvg","yihridsxajkiyehmdbru","pbxvdoleubrdd","smavxt","azlrmjwmlsglgwrdakgn","cf","ohkaajphvrorgyx","nll","jlnlqzviffdmegnxig","pqgkqrancnwaqrjovjlgqsfx","azwaipyqlmgoeslujdkwuh","jubooimlfis","sosnjvqikiivlighyktd","jhujjiiovhw","jgbj","qtrbilvqvy","vlmkkilhsqlknvqpus","omuucd","ligpithabxjqtuaf","mz","ognmihotoqgprvbt","nmgwkocmeezb","qmiajlowymr","xmlmolj","cwciqqpbmzzcgmnrvgucezor","ng","lqglykvsxhobqrppeqrlp","ywuytvrproahtgro","etcnjqg","bogjahrw","rrrkddajfq","nwcraujocpk","yo","nhasjwodqyququhhfkyv","tpalgbgirzrl","jjgcsekxxi","r","jgxxttnlhez","ha","jxklqfdizkgzusrzs","hnjctughrsdiyezcqsmij","tvpawacxepvq","lwv","rspgmumnbrzk","gqkdxbkylirxxqrhh","wsbvir","fjktj","rulvjpezzonnbr","kxntnopkkjgliltrlklfgc","h","uplapswlksu","cevzkpfcbviliulexyx","mvbwfqqbeisdsjdnn","giavjwaftarskv","trlhxmqayeiero","yfazdiayalzrnf","qmolgaezbwuodbdhsxclhzi","nskgjmut","gccpj","psmqmdceprjoiw","dhvqyqvnh","jcxq","quvi","pvqdzzwv","yzksz","vnicvmnfwwwmzhsdsm","gn","jcyfpawtcnuikudwuijpd","mmncorzbnoawyo","cwygpjjmrmslabafcmwdhpdo","nikwaflxpepnkz","qmylnzkhz","oc","jnyibizgmwjqjvhbg","ajhaejn","eulboowdyd","vyjfniqjoepdbzulvpgjic","oauvt","vpnmjbnkf","izk","sanouetznnk","truufmplrmsxgvrtl","yuabbnxybbpfgblou","yjyawflsvetbdpcgbjta","cmozvlftrhtxmjqkorxfrql","nbyvnbhjlofqdtilvplcdks","nxmyafxvrfhbuzpzixt","lxtoignhwtcbsi","cycu","rlzjrirwfhwdvolixa","itle","nmitv","cno","mnwjytgktowostuzvrcjxr","etus","othjqfpysicbdhfezxpvhjd","nzypfebzbsaakoky","uimwaktcywogwptihvrrh","pgc","njwftpurketzvjbzivanz","olnrizftjnjixeysi","k","fbwkolpka","vqcxxbcumypdbetrknavgm","ivfnyhqqnjdmdwqslhk","fusfadhqfruriiglvqzuns","r","sghqrdaelollqmczagojceys"};
	Solution* test = new Solution();
	/*
	vector<vector<string>> result = test->groupStrings(input);
	for (const auto& iter : result) {
		for (const auto& iter2 : iter) {
			cout << iter2 << " ";
		}
		cout << endl;
	}*/
	vector<vector<string>> result2 = test->groupStrings2(input);
	for (const auto& iter : result2) {
		for (const auto& iter2 : iter) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	return 0;
}

