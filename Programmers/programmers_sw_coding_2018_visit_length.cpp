#include <string>
#include <map>
#include <cstring>
#include <iostream>


using namespace std;

const int MAX_N = 5;

map<char, int> m;
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, 1, -1, 0}; // URLD

bool visit[MAX_N * 2 + 1][MAX_N * 2 + 1][MAX_N * 2 + 1][MAX_N * 2 + 1];


void init() {
	m['U'] = 0;
	m['R'] = 1;
	m['L'] = 2;
	m['D'] = 3;
	memset(visit, 0, sizeof(visit));
}

void getXY(const int y, const int x, int& ny, int& nx, int dir) {

}
int solution(string dirs) {
	int answer = 0;

	init();

	int dir, nx, ny, x, y;
	x = 0, y = 0;
	for (int i = 0; i < dirs.size(); i++) {
		dir = m[dirs[i]];
		ny = y + dy[dir];
		nx = x + dx[dir];
		if (ny < -MAX_N || nx < -MAX_N || ny > MAX_N || nx > MAX_N)
			continue;

		if (!visit[y + 5][x + 5][ny + 5][nx + 5] && !visit[ny + 5][nx + 5][y + 5][x + 5]) {
			visit[y + 5][x + 5][ny + 5][nx + 5] = true;
			visit[ny + 5][nx + 5][y + 5][x + 5] = true;
			answer++;
		}
		y = ny;
		x = nx;
	}
	return answer;
}