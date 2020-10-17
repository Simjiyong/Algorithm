#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 10;
const int INF = 987654321;

int Min = INF;
int T, N;
int board[MAX_N][MAX_N];
vector<pii> person, stair;
void init() {
	person.clear();
	stair.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				person.push_back(pii(i, j));
			else if (board[i][j] > 1)
				stair.push_back(pii(i, j));
		}
	}
}


int getTime(vector<int> v, int cur) {
	int len = board[stair[cur].first][stair[cur].second];
	int cnt = 0;
	queue<int> q;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		while (!q.empty() && v[i] >= q.front())
			q.pop();
		if (q.size() < 3)
			q.push(v[i] + len);
		else {
			q.push(q.front() + len);
			q.pop();
		}
	}

	int res = 0;
	while (!q.empty()) {
		res = q.front();
		q.pop();
	}
	return res;
}

int solve(int subset) {
	int i = 0;
	int cur, dist;
	int res;
	vector<int> v[2];
	while (1) {
		cur = 1 << i;
		if (cur == 1 << person.size())
			break;
		if (cur & subset) {
			dist = abs(person[i].first - stair[1].first) + abs(person[i].second - stair[1].second);
			v[1].push_back(dist);
		}
		else {
			dist = abs(person[i].first - stair[0].first) + abs(person[i].second - stair[0].second);
			v[0].push_back(dist);
		}
		i++;
	}

	res = max(getTime(v[0], 0), getTime(v[1], 1));
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	int answer;
	for (int tc = 1; tc <= T; tc++) {
		answer = INF;
		cin >> N;
		init();
		for (int i = 0; i < 1 << person.size(); i++) {
			answer = min(answer, solve(i));
		}
		cout << "#" << tc << " " << answer + 1 << '\n';
	}
	return 0;
}
