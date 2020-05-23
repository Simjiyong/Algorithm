#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

const int MAX_N = 50;
const int MAX_M = 13;
const int INF = 987654321;

int board[MAX_N + 1][MAX_N + 1];
int dist[MAX_N + 1][MAX_N + 1];
int N, M, answer = INF;
vector<pii> ck, h;
void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				h.push_back(pii(i, j));
			else if (board[i][j] == 2)
				ck.push_back(pii(i, j));

			dist[i][j] = INF;
		}
	}
}

void change(int cy, int cx) {
	int y, x;
	for (int i = 0; i < h.size(); i++) {
		y = h[i].first;
		x = h[i].second;
		if (dist[y][x] > abs(cy - y) + abs(cx - x))
			dist[y][x] = abs(cy - y) + abs(cx - x);
	}
}

int getDist() {
	int res = 0;
	int y, x;
	for (int i = 0; i < h.size(); i++) {
		y = h[i].first;
		x = h[i].second;
		res += dist[y][x];
	}
	return res;
}

void mCopy(int dest[MAX_N + 1][MAX_N + 1], int src[MAX_N + 1][MAX_N + 1]) {
	int y, x;
	for (int i = 0; i < h.size(); i++) {
		y = h[i].first;
		x = h[i].second;
		dest[y][x] = src[y][x];
	}
}


void dfs(int here, int cnt) {
	if (cnt == M) {
		answer = min(answer, getDist());
		return;
	}

	int y, x;
	int tmp[MAX_N + 1][MAX_N + 1];
	mCopy(tmp, dist);
	for (int i = here; i < ck.size(); i++) {
		y = ck[i].first;
		x = ck[i].second;
		change(y, x);
		dfs(i + 1, cnt + 1);
		mCopy(dist, tmp);
	}
}

int main() {

	init();

	dfs(0, 0);
	cout << answer << '\n';
	return 0;
}