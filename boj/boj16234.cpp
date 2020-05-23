#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

const int MAX_N = 50;
const int MAX_L = 100;
const int MAX_R = 100;

int N, L, R;

int A[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];

vector<pii> v;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, 1, -1, 0 };
int sum, answer;
void init() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			v.push_back(pii(i, j));
		}
	}
}

void open() {
	int y, x, ny, nx, diff;
	for (int i = 0; i < v.size() - 1; i++) {
		y = v[i].first;
		x = v[i].second;
		for (int j = i + 1; j < v.size(); j++) {
			ny = v[i].first;
			nx = v[i].second;

		}
		for (int dir = 0; dir < 4; dir++) {
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
				continue;
			diff = abs(A[y][x] - A[ny][nx]);
			if (L <= diff && R <= diff) {

			}
		}
	}
}

void dfs(int y, int x) {
	int ny, nx, diff;
	for (int dir = 0; dir < 4; dir++) {
		ny = y + dy[dir];
		nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
			continue;
		if (visit[ny][nx])
			continue;

		diff = abs(A[y][x] - A[ny][nx]);
		if (L <= diff && diff <= R) {
			visit[ny][nx] = true;
			v.push_back(pii(ny, nx));
			sum += A[ny][nx];
			dfs(ny, nx);
		}
	}
}


void mMemset(bool visit[MAX_N][MAX_N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
}

int main() {
	init();
	bool flag;
	while (1) {
		flag = false;
		mMemset(visit);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j])
					continue;
				v.clear();

				visit[i][j] = true;
				sum = A[i][j];
				v.push_back(pii(i, j));

				dfs(i, j);
				if (v.size() == 1)
					continue;
				flag = true;
				for (int k = 0; k < v.size(); k++)
					A[v[k].first][v[k].second] = sum / v.size();
			}
		}
		if (!flag)
			break;
		answer++;
	}
	cout << answer;
	return 0;
}