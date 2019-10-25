#include "CSVLoad.h"
vector<vector<double>> CSVLoad(string& _filename) {

	ifstream ifs;
	ifs.open(_filename);

	vector<vector<double>> vec;

	string line;

	vector<string> tmpStr;
	vector<string> tmpStrVec;

	vector<double> tmpData;
	char del = ',';
	int roomNum = 1;

	if (ifs.fail()) {        // エラー処理     ifsをつけるのはファイルを開くのを失敗したかどうか
		cerr << "ファイルオープン失敗" << endl;
		exit(-1);
	}

	/*getline(ifs, line);//1行空読み(なぞ)
	getline(ifs, line);//1行空読み
	getline(ifs, line);//1行空読み*/

	/*while (!ifs.eof()) {        // ファイルストリームが終わるまで回る

		getline(ifs, line);     // 1行読み込む

		tmpStr = split(line, del);//読み込んだ行を','で分解

		for (int i = 0; i < tmpStr.size(); i++) {
			double num = atof(tmpStr[i].c_str());        // stringをintに変換
			tmpData.push_back(num);		//vecの最後に挿入
		}

		tmpData.insert(tmpData.begin(),roomNum);//配列の先頭に部屋番号を挿入
		roomNum++;

		vec.push_back(tmpData);

	}*/

	while (getline(ifs, line)) {
		tmpStr.push_back(line);
	}

	for (int i = 2; i < tmpStr.size(); i++) {
		tmpStrVec = split(tmpStr[i], del);

		for (int i = 0; i < tmpStrVec.size(); i++) {
			double num = atof(tmpStrVec[i].c_str());        // stringをintに変換
			tmpData.push_back(num);		//vecの最後に挿入
		}

		tmpData.insert(tmpData.begin(), roomNum);//配列の先頭に部屋番号を挿入
		roomNum++;

		vec.push_back(tmpData);

	}


	ifs.close();

	return vec;
};

//文字列を区切る関数
vector<string> split(string str, char del) {
	int first = 0;
	int last = str.find_first_of(del);

	vector<string> result;

	while (first < str.size()) {
		string subStr(str, first, last - first);

		result.push_back(subStr);

		first = last + 1;
		last = str.find_first_of(del, first);

		if (last == string::npos) {
			last = str.size();
		}
	}

	return result;
}
