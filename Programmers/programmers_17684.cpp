#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;
int idx = 1;
void init() {
	char c = 'A';
	string s;
	for (int i = 0; i < 26; i++) {
		s = "";
		s += c;
		m[s] = idx++;
		c += 1;
	}
}
vector<int> solution(string msg) {
	vector<int> answer;
	init();

	int i = 0;
	string cur = "", prev;
	while (i < msg.size()) {
		cur += msg[i];
		if (m[cur] == 0) {
			answer.push_back(m[prev]);
			m[cur] = idx++;
			cur = "";
		}
		else {
			prev = cur;
			i++;
		}
	}
	answer.push_back(m[prev]);
	return answer;
}