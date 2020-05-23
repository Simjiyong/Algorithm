#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
typedef pair<int, int> pii;
struct Shark
{
	int y;
	int x;
	int size;
	int cnt;
	Shark() {
		y = 0;
		x = 0;
		size = 0;
		cnt = 0;
	}
	Shark(int y, int x, int size) {
		this->y = y;
		this->x = x;
		this->size = size;
		this->cnt = 0;
	}
};
int N;
int board[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
Shark s;

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 }; // ulrd
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				s = Shark(i, j, 2);
				board[i][j] = 0;
			}
		}
	}
}

bool cmp(const pii a, const pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

void eat(int y, int x) {
	board[y][x] = 0;
	s.cnt++;
	s.y = y;
	s.x = x;
	if (s.cnt == s.size) {
		s.size++;
		s.cnt = 0;
	}
}
int bfs() {
	queue<pii> q;
	vector<pii> v;
	int y, x, ny, nx;
	int size, cnt = 0;
	y = s.y, x = s.x;
	q.push(pii(y, x));
	visit[y][x] = true;

	while (!q.empty()) {
		size = q.size();
		while (size--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				ny = y + dy[dir];
				nx = x + dx[dir];
				if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
					continue;
				if (visit[ny][nx])
					continue;
				if (board[ny][nx] > s.size)
					continue;


				if (board[ny][nx] == 0 || board[ny][nx] == s.size) {
					visit[ny][nx] = true;
					q.push(pii(ny, nx));
				}
				else {
					v.push_back(pii(ny, nx));
				}
			}
		}
		cnt++;
		if (v.size() > 0) {
			sort(v.begin(), v.end(), cmp);
			eat(v[0].first, v[0].second);
			return cnt;
		}
	}

	return 0;
}

void mMemset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	init();

	int res, answer = 0;
	while (1) {
		mMemset();
		res = bfs();
		if (res == 0)
			break;
		answer += res;
	}

	cout << answer << '\n';
	return 0;
}