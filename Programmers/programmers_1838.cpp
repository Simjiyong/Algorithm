#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
const int MAX_N = 10;
int D[20];
int getMaxPerson(int m, vector<vector<int>>& timetable) {
	int enter, exit, res;
	int arr[1321] = { 0, };
	res = 0;
	for (int i = 0; i < m; i++) {
		enter = timetable[i][0];
		exit = timetable[i][1];
		for (int j = enter; j <= exit; j++) {
			arr[j]++;
			res = max(res, arr[j]);
		}
	}
	return res;
}

bool isPossible(int here, int n, int d, vector<int> v) {
	int y, x, vx, vy;
	y = here / n;
	x = here % n;
	for (int i = 0; i < v.size(); i++) {
		vy = v[i] / n;
		vx = v[i] % n;
		if (abs(x - vx) + abs(y - vy) < d)
			return false;
	}
	return true;
}

int getCount(int here, int n, int d, vector<int> v) {
	int y, x, vx, vy;
	for (int i = here + 1; i < n * n; i++) {
		if (isPossible(i, n, d, v))
			v.push_back(i);
	}
	if (v.size() == 1)
		return 0;
	return v.size();
}

int init(int n, int d) {
	int res = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
		res = max(res, getCount(i, n, d, v));
		v.clear();
	}
	return res;
}

int solution(int n, int m, vector<vector<int>> timetable) {
	int answer = 0, maxPerson = 0;
	for (int i = 1; i < 20; i++) {
		D[i] = init(n, i);
	}
	sort(timetable.begin(), timetable.end());
	maxPerson = getMaxPerson(m, timetable);
	if (maxPerson == 1)
		return 0;
	answer = 1;
	while (D[answer] >= maxPerson)
		answer++;
	answer--;
	return answer;
}