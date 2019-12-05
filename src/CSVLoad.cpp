#include "CSVLoad.h"

//�ŏ��ɓǂݔ�΂��s��
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

	if (ifs.fail()) {//�G���[�����Aifs������̂̓t�@�C�����J���̂����s�������ǂ���
		cerr << "�t�@�C���I�[�v�����s" << endl;
		exit(-1);
	}

	while (getline(ifs, line)) {
		tmpStr.push_back(line);
	}

	for (int i = ADJUST; i < tmpStr.size(); i++) {
		tmpStrVec = split(tmpStr[i], del);					//1�s�ǂݍ���ŃJ���}�ŕ���

		for (int i = 0; i < tmpStrVec.size(); i++) {
			double num = atof(tmpStrVec[i].c_str());        //string��int�ɕϊ�
			tmpData.push_back(num);							//vec�̍Ō�ɑ}��
		}

		tmpData.insert(tmpData.begin(), Num);				//�z��̐擪�ɔԍ���}��
		Num++;

		vec.push_back(tmpData);								//�܂Ƃ߂��f�[�^��vec�̖����ɑ}��
		tmpData.clear();									//������

	}

	ifs.close();

	return vec;
};

//���������؂�֐�
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
