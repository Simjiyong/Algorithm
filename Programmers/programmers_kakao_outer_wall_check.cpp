#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> subset;
vector<int> getSubset(int n) {
	vector<int> subset;
	int i = 0;
	while (1 << i <= n) {
		if (1 << i & n)
			subset.push_back(i);
		i++;
	}
	return subset;
}

bool cmp(const vector<int> a, const vector<int> b) { return a.size() < b.size(); }

bool check(vector<int> subset, int here, int n, vector<int> weak, vector<int> dist) {

	int next, start, end;
	int cnt = 0;

	next = here;
	start = weak[here];
	end = weak[here] + dist[subset[0]];

	int idx, repeat = 0;;
	for (int i = 0; i < subset.size(); i++) {
		idx = subset[i];
		start = weak[next];
		end = weak[next] + dist[idx];
		while (cnt < weak.size()) {
			if (weak[next] + repeat < start || weak[next] + repeat > end)
				break;
			next++;
			cnt++;
			if (next == weak.size()) {
				next = 0;
				repeat += n;
			}
		}
	}
	if (cnt == weak.size())
		return true;
	return false;
}

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 0;

	vector<int> v;
	for (int i = 1; i < 1 << dist.size(); i++) {
		v = getSubset(i);
		subset.push_back(v);
	}
	sort(subset.begin(), subset.end(), cmp);

	for (int i = 0; i < subset.size(); i++) {
		do {
			for (int j = 0; j < weak.size(); j++) {
				if (check(subset[i], j, n, weak, dist))
					return subset[i].size();
			}
		} while (next_permutation(subset[i].begin(), subset[i].end()));
	}
	return -1;
}