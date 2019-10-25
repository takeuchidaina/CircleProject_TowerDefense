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

	if (ifs.fail()) {        // �G���[����     ifs������̂̓t�@�C�����J���̂����s�������ǂ���
		cerr << "�t�@�C���I�[�v�����s" << endl;
		exit(-1);
	}

	/*getline(ifs, line);//1�s��ǂ�(�Ȃ�)
	getline(ifs, line);//1�s��ǂ�
	getline(ifs, line);//1�s��ǂ�*/

	/*while (!ifs.eof()) {        // �t�@�C���X�g���[�����I���܂ŉ��

		getline(ifs, line);     // 1�s�ǂݍ���

		tmpStr = split(line, del);//�ǂݍ��񂾍s��','�ŕ���

		for (int i = 0; i < tmpStr.size(); i++) {
			double num = atof(tmpStr[i].c_str());        // string��int�ɕϊ�
			tmpData.push_back(num);		//vec�̍Ō�ɑ}��
		}

		tmpData.insert(tmpData.begin(),roomNum);//�z��̐擪�ɕ����ԍ���}��
		roomNum++;

		vec.push_back(tmpData);

	}*/

	while (getline(ifs, line)) {
		tmpStr.push_back(line);
	}

	for (int i = 2; i < tmpStr.size(); i++) {
		tmpStrVec = split(tmpStr[i], del);

		for (int i = 0; i < tmpStrVec.size(); i++) {
			double num = atof(tmpStrVec[i].c_str());        // string��int�ɕϊ�
			tmpData.push_back(num);		//vec�̍Ō�ɑ}��
		}

		tmpData.insert(tmpData.begin(), roomNum);//�z��̐擪�ɕ����ԍ���}��
		roomNum++;

		vec.push_back(tmpData);

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
