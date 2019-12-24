#include "CSVLoad.h"

//最初に読み飛ばす行数
#define ADJUST 2

vector<vector<double>> CSVLoad(string& _filename) {

	ifstream ifs;
	ifs.open(_filename);

	vector<vector<double>> vec;

	string line;

	vector<string> tmpStr;
	vector<string> tmpStrVec;

	vector<double> tmpData;
	char del = ',';
	int Num = 0;

	if (ifs.fail()) {//エラー処理、ifsをつけるのはファイルを開くのを失敗したかどうか
		cerr << "ファイルオープン失敗" << endl;
		exit(-1);
	}

	while (getline(ifs, line)) {
		tmpStr.push_back(line);
	}

	for (int i = ADJUST; i < tmpStr.size(); i++) {
		tmpStrVec = split(tmpStr[i], del);					//1行読み込んでカンマで分解

		for (int i = 0; i < tmpStrVec.size(); i++) {
			double num = atof(tmpStrVec[i].c_str());        //stringをintに変換
			tmpData.push_back(num);							//vecの最後に挿入
		}

		tmpData.insert(tmpData.begin(), Num);				//配列の先頭に番号を挿入
		Num++;

		vec.push_back(tmpData);								//まとめたデータをvecの末尾に挿入
		tmpData.clear();									//初期化

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

vector<sUnitLoad> UnitLoad(string& _filePath)
{
	ifstream ifs;
	ifs.open(_filePath);

	vector<sUnitLoad> vec;

	string line;

	vector<string> tmpStr;
	vector<string> tmpStrVec;

	char del = ',';
	int Num = 0;

	if (ifs.fail())
	{//エラー処理、ifsをつけるのはファイルを開くのを失敗したかどうか
		cerr << "ファイルオープン失敗" << endl;
		exit(-1);
	}

	while (getline(ifs, line))
	{
		tmpStr.push_back(line);
	}

	for (int i = ADJUST; i < tmpStr.size(); i++)
	{
		tmpStrVec = split(tmpStr[i], del);					//1行読み込んでカンマで分解
	
		sUnitLoad tmpUnit;

		tmpUnit.ID = atof(tmpStrVec[0].c_str());
		tmpUnit.type = atof(tmpStrVec[1].c_str());
		tmpUnit.HP = atof(tmpStrVec[2].c_str());
		tmpUnit.ATK = atof(tmpStrVec[3].c_str());
		tmpUnit.speed = atof(tmpStrVec[4].c_str());
		tmpUnit.coolTime = atof(tmpStrVec[5].c_str());
		tmpUnit.DEF = atof(tmpStrVec[6].c_str());
		tmpUnit.unitPath = tmpStrVec[7];
		tmpUnit.effectPath = tmpStrVec[8];
		tmpUnit.cost = atof(tmpStrVec[9].c_str());

		vec.push_back(tmpUnit);
	}

	return vec;
}