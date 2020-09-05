#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 100;
const int MAX_M = 100;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool visit[MAX_N][MAX_M];

int bfs(vector<vector<int>> maps) {
	int N, M;
	N = maps.size();
	M = maps[0].size();
	queue<pii> q;
	visit[0][0] = true;
	q.push(pii(0, 0));
	int size, cnt = 1;
	int ny, nx, y, x;
	while (!q.empty()) {
		size = q.size();
		cnt++;
		while (size > 0) {
			pii cur = q.front();
			q.pop();
			y = cur.first;
			x = cur.second;
			for (int dir = 0; dir < 4; dir++) {
				ny = y + dy[dir];
				nx = x + dx[dir];
				if (ny < 0 || nx < 0 || ny > N - 1 || nx > M - 1)
					continue;
				if (maps[ny][nx] == 0)
					continue;
				if (visit[ny][nx])
					continue;
				if (ny == N - 1 && nx == M - 1)
					return cnt;
				visit[ny][nx] = true;
				q.push(pii(ny, nx));
			}
			size--;
		}
	}

	return -1;

}
int solution(vector<vector<int> > maps)
{
	int answer = 0;
	answer = bfs(maps);
	return answer;
}