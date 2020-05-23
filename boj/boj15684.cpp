#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 10; // 세로선
const int MAX_H = 30; // 가로 위치

int N, M, H;
int board[MAX_H + 1][MAX_N + 1];
int route[MAX_H + 1][MAX_N + 1];
int answer;

vector<pii> v;
map<int, int> m;

bool isPossible(int a, int b) {
	if (b > 1) {
		if (board[a][b - 1] == 1 || board[a][b + 1] == 1)
			return false;
	}
	else {
		if (board[a][b + 1] == 1)
			return false;
	}
	return true;
}

void mSwap(int a, int b) {
	int k1, k2, tmp;
	k1 = route[a][b];
	k2 = route[a][b + 1];

	tmp = m[k1];
	m[k1] = m[k2];
	m[k2] = tmp;
}

void draw() {
	int dest;
	for (int b = 1; b <= N; b++) {
		route[0][b] = b;
	}
	for (int a = 1; a <= H; a++) {
		for (int b = 1; b <= N; b++) {
			if (board[a][b] == 1) {
				route[a][b] = route[a - 1][b + 1];
			}
			else if (board[a][b - 1] == 1) {
				route[a][b] = route[a - 1][b - 1];
			}
			else
				route[a][b] = route[a - 1][b];
		}
	}
}

void init() {
	cin >> N >> M >> H;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		board[a][b] = 1;
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (board[i][j] == 0 && isPossible(i, j))
				v.push_back(pii(i, j));
		}
	}
	draw();
	for (int i = 1; i <= N; i++)
		m[i] = i;
	answer = -1;
}

bool check() {
	int k;
	for (int i = 1; i <= N; i++) {
		k = route[H][i];
		if (m[k] != i)
			return false;
	}
	return true;
}

void dfs(int here, int cur, int cnt) {
	if (answer != -1)
		return;

	if (cur == cnt) {
		if (check())
			answer = cnt;
		return;
	}
	int a, b;
	for (int i = here; i < v.size(); i++) {
		a = v[i].first;
		b = v[i].second;
		if (isPossible(a, b)) {
			board[a][b] = 1;
			mSwap(a, b);
			dfs(i + 1, cur + 1, cnt);
			mSwap(a, b);
			board[a][b] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();

	for (int i = 0; i <= 3; i++) {
		dfs(0, 0, i);
		if (answer != -1)
			break;
	}
	cout << answer << '\n';
	return 0;
}