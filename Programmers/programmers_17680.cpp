#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
const int HIT = 1;
const int MISS = 5;

deque<int> dq;
void convertToUpper(string& str) {
	for (int i = 0; i < str.size(); i++) {
		str[i] = toupper(str[i]);
	}
}

bool hit(string str, vector<string>& cities) {
	deque<int>::iterator it;
	for (it = dq.begin(); it != dq.end(); it++) {
		if (cities[*it] == str) {
			dq.erase(it);
			return true;
		}
	}
	return false;
}
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	for (int i = 0; i < cities.size(); i++) {
		convertToUpper(cities[i]);
		if (cacheSize == 0) {
			answer += MISS;
		}
		else if (hit(cities[i], cities)) {
			dq.push_back(i);
			answer += HIT;
		}
		else {
			if (dq.size() == cacheSize)
				dq.pop_front();
			dq.push_back(i);
			answer += MISS;
		}
	}
	return answer;
}