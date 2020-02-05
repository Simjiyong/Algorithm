#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int MAX_N = 100;

bool structure[MAX_N + 1][MAX_N + 1][2];

bool checkBuild(int x, int y, int a, int n) {
	if (a == 0) { //±âµÕ
		if (y == 0 || structure[y - 1][x][0])
			return true;
		if (x - 1 >= 0 && structure[y][x - 1][1])
			return true;
		if (structure[y][x][1])
			return true;

	}
	else { //º¸
		if (structure[y - 1][x][0] || structure[y - 1][x + 1][0])
			return true;

		if (x - 1 >= 0 && structure[y][x - 1][1] && x + 2 <= n && structure[y][x + 1][1])
			return true;
	}
	return false;
}
bool checkRemove(int x, int y, int a, int n) {
	structure[y][x][a] = false;
	if (a == 0) { // ±âµÕ
		if (structure[y + 1][x][0] && !checkBuild(x, y + 1, 0, n)) {
			structure[y][x][a] = true;
			return false;
		}
		if (structure[y + 1][x][1] && !checkBuild(x, y + 1, 1, n)) {
			structure[y][x][a] = true;
			return false;
		}
		if ((x - 1 >= 0 && structure[y + 1][x - 1][1]) && !checkBuild(x - 1, y + 1, 1, n)) {
			structure[y][x][a] = true;
			return false;
		}
	}
	else { // º¸
		if (structure[y][x][0] && !checkBuild(x, y, 0, n)) {
			structure[y][x][a] = true;
			return false;
		}
		if (structure[y][x + 1][0] && !checkBuild(x + 1, y, 0, n)) {
			structure[y][x][a] = true;
			return false;
		}
		if (x - 1 >= 0 && structure[y][x - 1][1] && !checkBuild(x - 1, y, 1, n)) {
			structure[y][x][a] = true;
			return false;
		}
		if (x + 2 <= n && structure[y][x + 1][1] && !checkBuild(x + 1, y, 1, n)) {
			structure[y][x][a] = true;
			return false;
		}
	}
	return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	int x, y, a, b;
	for (int i = 0; i < build_frame.size(); i++) {
		x = build_frame[i][0];
		y = build_frame[i][1];
		a = build_frame[i][2];
		b = build_frame[i][3];

		if (b == 1 && checkBuild(x, y, a, n))
			structure[y][x][a] = true;
		if (b == 0 && checkRemove(x, y, a, n))
			structure[y][x][a] = false;
	}

	for (int x = 0; x <= n; x++) {
		for (int y = 0; y <= n; y++) {
			if (structure[y][x][0])
				answer.push_back({ x,y,0 });
			if (structure[y][x][1])
				answer.push_back({ x,y,1 });
		}
	}
	return answer;
}