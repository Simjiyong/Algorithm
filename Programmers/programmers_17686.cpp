#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct File {
	int idx;
	string head;
	int number;
	string tail;
	File() {

	}
	File(int idx, string head, int number, string tail) {
		this->idx = idx;
		this->head = head;
		this->number = number;
		this->tail = tail;
	}
};

vector<File> v;
string convertToUpper(string str) {
	string res = "";
	for (int i = 0; i < str[i]; i++)
		res += toupper(str[i]);
	return res;
}

bool operator<(const File& a, const File& b) {
	string strA, strB;
	strA = convertToUpper(a.head);
	strB = convertToUpper(b.head);
	if (strA == strB) {
		if (a.number == b.number)
			return a.idx < b.idx;
		return a.number < b.number;
	}
	return strA < strB;
}

File parsingFile(string file) {
	File res;
	string tmp = "";
	int i = 0;
	while (i < file.size()) {
		if ('0' <= file[i] && file[i] <= '9')
			break;
		tmp += file[i];
		i++;
	}
	res.head = tmp;
	tmp = "";

	while (i < file.size()) {
		if (file[i] < '0' || file[i] > '9')
			break;
		tmp += file[i];
		i++;
	}
	res.number = stoi(tmp);
	tmp = "";

	while (i < file.size()) {
		tmp += file[i];
		i++;
	}
	res.tail = tmp;
	return res;
}
vector<string> solution(vector<string> files) {
	vector<string> answer;
	File cur;
	for (int i = 0; i < files.size(); i++) {
		cur = parsingFile(files[i]);
		cur.idx = i;
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		answer.push_back(files[v[i].idx]);
	}
	return answer;
}