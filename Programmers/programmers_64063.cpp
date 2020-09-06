#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef long long ll;
unordered_map<ll, ll> m;

ll find(ll number) {
	if (m[number] != 0)
		return m[number] = find(m[number]);
	return number;
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	int N = room_number.size();
	answer.resize(N);
	for (int i = 0; i < N; i++) {
		if (m[room_number[i]] == 0) {
			m[room_number[i]] = room_number[i] + 1;
			answer[i] = room_number[i];
		}
		else {
			ll num = find(room_number[i]);
			m[num] = num + 1;
			answer[i] = num;
		}
	}
	return answer;
}