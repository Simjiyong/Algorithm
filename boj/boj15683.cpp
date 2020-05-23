#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
struct cctv
{
	int y;
	int x;
	int type;
	cctv(int y, int x, int type) {
		this->y = y;
		this->x = x;
		this->type = type;
	}
};

const int MAX_N = 8;
const int MAX_M = 8;
const int INF = 987654321;
const int BLOCK = 6;
const int VISIT = 7;

int map[MAX_N][MAX_M];
int N, M, b_spot;
int answer = INF;
vector<cctv> v;
vector<vector<int>> t[6];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 }; // urdl

void make_type(int subset) {
	int type, i = 0;
	vector<int> v;
	while (subset >= (1 << i)) {
		if (subset & (1 << i)) {
			v.push_back(i);
		}
		i++;
	}
	type = v.size();
	if (type >= 3)
		type++;
	if (type == 2) {
		if (v[1] - v[0] != 2)
			type = 3;
	}
	vector<int> tmp;
	for (int i = 0; i < v.size(); i++)
		tmp.push_back(v[i]);
	t[type].push_back(tmp);
}

void init() {
	for (int i = 1; i < 1 << 4; i++)
		make_type(i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				b_spot++;
			else if (map[i][j] != 6)
				v.push_back(cctv(i, j, map[i][j]));
		}
	}
}

void draw(int y, int x, vector<int> v, int map[MAX_N][MAX_M], int& b_spot) {

	int ny, nx;
	for (int i = 0; i < v.size(); i++) {
		ny = y, nx = x;
		while (1) {
			ny += dy[v[i]];
			nx += dx[v[i]];
			if (ny < 0 || nx < 0 || ny> N - 1 || nx >M - 1)
				break;
			if (map[ny][nx] == BLOCK)
				break;
			if (map[ny][nx] != 0)
				continue;
			map[ny][nx] = VISIT;
			b_spot--;
		}
	}
}

void mMemcpy(int dest[MAX_N][MAX_M], int src[MAX_N][MAX_M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dest[i][j] = src[i][j];
		}
	}
}
void dfs(int here, int map[MAX_N][MAX_M], int& b_spot) {
	if (v.size() == here) {
		answer = min(answer, b_spot);
		return;
	}
	int type, y, x, t_spot;
	int tmp[MAX_N][MAX_M];

	mMemcpy(tmp, map);
	t_spot = b_spot;
	type = v[here].type;
	y = v[here].y;
	x = v[here].x;

	for (int i = 0; i < t[type].size(); i++) {
		draw(y, x, t[type][i], map, b_spot);
		dfs(here + 1, map, b_spot);
		b_spot = t_spot;
		mMemcpy(map, tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	init();
	if (v.size() == 0)
		answer = b_spot;
	else {
		dfs(0, map, b_spot);
	}
	cout << answer << '\n';
	return 0;
}