#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
const int INF = 987654321;
unordered_map<string, int> m;
int d[20000];
int solution(vector<string> strs, string t)
{
	int answer = 0;
	for (int i = 0; i < strs.size(); i++)
		m[strs[i]] = 1;
	d[0] = 0;
	for (int i = 1; i <= t.size(); i++) {
		d[i] = INF;
		for (int j = 0; j < strs.size(); j++) {
			int len = strs[j].size();
			if (i - len < 0)
				continue;
			char end = strs[j][len - 1];
			if (end != t[i - 1])
				continue;
			string s1, s2;
			s1 = strs[j];
			s2 = t.substr(i - len, len);
			if (s1.compare(s2) == 0) {
				d[i] = min(d[i], d[i - len] + m[s1]);
			}
		}
	}
	answer = d[t.size()];
	if (answer == INF)
		return -1;
	return answer;
}