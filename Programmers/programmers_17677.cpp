#include <string>
#include <map>
#include <iostream>
using namespace std;
const int MULTI = 65536;
map<string, int> m[2];
void convertToUpper(string& str) {
	for (int i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
}

void getMap(string str, int idx) {
	int i = 0;
	string tmp = "";
	while (i < str.size()) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			tmp += str[i];
			if (tmp.size() == 2) {
				m[idx][tmp]++;
				tmp = str[i];
			}
		}
		else
			tmp = "";
		i++;
	}
}
int getIntersection() {
	int res = 0;
	for (auto kv : m[0]) {
		string key = kv.first;
		if (m[1][key] == 0)
			continue;
		res += min(kv.second, m[1][key]);
	}
	return res;
}

int getSum() {
	int res = 0;
	for (auto kv : m[0]) {
		string key = kv.first;
		if (m[1][key] == 0)
			res += kv.second;
		else
			res += max(m[1][key], kv.second);
	}

	for (auto kv : m[1]) {
		string key = kv.first;
		if (m[0][key] == 0)
			res += kv.second;
	}
	return res;
}

int solution(string str1, string str2) {
	int answer = 0;
	convertToUpper(str1);
	convertToUpper(str2);

	getMap(str1, 0);
	getMap(str2, 1);
	if (m[0].size() == 0 && m[1].size() == 0)
		return MULTI;
	int intersection = getIntersection();
	int sum = getSum();
	answer = MULTI * intersection / sum;
	return answer;
}