#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int score[3], bonus[3], option[3];
int getScore(int& idx, string dartResult) {
	int res = 0;
	char c;
	while (1) {
		c = dartResult[idx];
		if (c < '0' || c > '9')
			break;
		res *= 10;
		res += c - '0';
		idx++;
	}
	return res;
}

int getBonus(char type) {
	if (type == 'S')
		return 1;
	if (type == 'D')
		return 2;
	return 3;
}
int getOption(char type) {
	if (type == '*')
		return 2;
	if (type == '#')
		return -1;
}
int solution(string dartResult) {
	int answer = 0;
	for (int i = 0, j = 0; i < 3; i++) {
		score[i] = getScore(j, dartResult);
		bonus[i] = getBonus(dartResult[j]);
		j++;
		if (j == dartResult.size() || ('0' <= dartResult[j] && dartResult[j] <= '9'))
			continue;
		option[i] = getOption(dartResult[j]);
		j++;
	}

	int res;
	for (int i = 0; i < 3; i++) {
		res = 0;
		res = pow(score[i], bonus[i]);
		if (option[i] != 0)
			res *= option[i];
		if (i + 1 < 3 && option[i + 1] == 2)
			res *= 2;
		answer += res;
	}
	return answer;
}