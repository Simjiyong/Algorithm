#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

const int MAX_N = 20;
const int MAX_Y = 100;
const int MAX_X = 100;

int map[MAX_Y + 1][MAX_X + 1];
int N;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 }; // ruld

void draw(int x, int y, int d, int g) {
	vector<pii> v;
	v.push_back(pii(y, x));

	int ny, nx;
	ny = y + dy[d];
	nx = x + dx[d];
	v.push_back(pii(ny, nx));

	int cy, cx, size;
	while (g-- > 0) {
		size = v.size() - 1;
		cy = v[size].first;
		cx = v[size].second;
		for (int i = size - 1; i >= 0; i--) {
			y = v[i].first;
			x = v[i].second;

			ny = cy + (x - cx);
			nx = cx - (y - cy);
			v.push_back(pii(ny, nx));
		}
	}

	for (int i = 0; i < v.size(); i++) {
		y = v[i].first;
		x = v[i].second;
		if (y < 0 || x < 0 || y > 100 || x > 100)
			continue;
		map[y][x] = 1;
	}
}

int get_cnt() {
	int cnt = 0;
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++) {
			if (map[i][j] && map[i + 1][j] &&
				map[i][j + 1] && map[i + 1][j + 1])
				cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> N;
	int x, y, d, g;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		draw(x, y, d, g);
	}

	cout << get_cnt() << '\n';
	return 0;
}