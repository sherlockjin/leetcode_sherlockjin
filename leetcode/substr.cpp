#include"common.h"

class Substr{
public:
	vector<string> results;
	//void dfsPrefix(string prefix, vector<string> items){
	//	vector<string> curVector;
	//	while (items.size() != 0){
	//		curVector.clear();
	//		string temp = items[items.size() - 1];
	//		results.push_back(prefix + temp);
	//		items.pop_back();
	//		for (int i = 0; i < items.size(); i++){
	//			curVector.push_back(items[i]);
	//		}
	//
	//		dfsPrefix(prefix + temp, curVector);
	//	}
	//}

	void dfsPrefix(string prefix, string items){
		for (int i = 0; i < items.length(); i++){
			char temp = items[i];
			results.push_back(prefix + temp);
			if (i != items.length() - 1){
				dfsPrefix(prefix + temp, items.substr(i + 1));
			}
		}
	}


	//int main(){
	//	string str;
	//	vector<string> items;
	//	cin >> str;
	//	
	//	dfsPrefix("", str);
	//	for (int i = 0; i < results.size(); i++){
	//		cout << results[i] << endl;
	//	}
	//	return 0;
	//}
};
