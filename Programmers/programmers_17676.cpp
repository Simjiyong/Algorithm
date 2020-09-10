#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <functional>

using namespace std;
const int MAX_N = 2000;
typedef pair<float, float> pff;
typedef pair<int, int> pii;
pii line[MAX_N];

queue<int> q;
int solution(vector<string> lines) {
	int answer = 0;
	int N = lines.size();
	int h, m, s, t;
	float fs, ft;
	for (int i = 0; i < N; i++) {
		sscanf(lines[i].c_str(), " 2016-09-15 %d:%d:%f %fs", &h, &m, &fs, &ft);
		m += h * 60;
		fs += m * 60;
		s = fs * 1000;
		t = ft * 1000;
		line[i].second = s;
		line[i].first = s - t + 1;
		q.push(line[i].first);
		q.push(line[i].second);
	}

	int cnt;
	while (!q.empty()) {
		float cur = q.front();
		q.pop();
		cnt = 0;
		for (int i = 0; i < N; i++) {
			if (cur > line[i].second || cur + 999 < line[i].first)
				continue;
			cnt++;
		}
		answer = max(cnt, answer);
	}

	return answer;
}