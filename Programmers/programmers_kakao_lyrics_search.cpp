#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

#define MAX_SIZE 26
#define MAX_N 1000000
using namespace std;

struct Trie {
	Trie* next[MAX_SIZE];
	int idx;
};

map<int, int> m[MAX_N];
Trie triePool[MAX_N];
int trieIdx;
Trie* root, * r_root;

void init() {
	root = nullptr;
	r_root = nullptr;
	trieIdx = 0;
	for (int i = 0; i < MAX_N; i++)
		m[i].clear();
}

Trie* alloc() {
	for (int i = 0; i < MAX_SIZE; i++)
		triePool[trieIdx].next[i] = nullptr;
	triePool[trieIdx].idx = trieIdx;

	return &triePool[trieIdx++];
}

void insert(string buf) {
	if (root == nullptr)
		root = alloc();

	Trie* cur = root;

	int len = buf.size();
	int idx, ch;

	for (int i = 0; i < len; i++) {
		ch = buf[i] - 'a';
		idx = cur->idx;

		if (m[idx].find(len) == m[idx].end())
			m[idx][len] = 1;
		else
			m[idx][len]++;

		if (cur->next[ch] == nullptr)
			cur->next[ch] = alloc();
		cur = cur->next[ch];

	}

}

void r_insert(string buf) {
	if (r_root == nullptr)
		r_root = alloc();

	Trie* r_cur = r_root;

	int len = buf.size();
	int r_idx, r_ch;

	for (int i = 0; i < len; i++) {
		r_ch = buf[len - 1 - i] - 'a';
		r_idx = r_cur->idx;

		if (m[r_idx].find(len) == m[r_idx].end())
			m[r_idx][len] = 1;
		else
			m[r_idx][len]++;
		if (r_cur->next[r_ch] == nullptr)
			r_cur->next[r_ch] = alloc();

		r_cur = r_cur->next[r_ch];
	}

}


int query(string buf, int type, int len) {

	Trie* cur;
	int buf_len = buf.size();
	int answer = 0, idx, ch;
	if (type == 0) {
		cur = root;
		if (root == nullptr)
			return 0;

		for (int i = 0; i < buf_len; i++) {
			ch = buf[i] - 'a';
			if (cur->next[ch] == nullptr)
				return 0;
			cur = cur->next[ch];
		}
	}
	else {
		cur = r_root;
		if (r_root == nullptr)
			return 0;

		for (int i = buf_len - 1; i >= 0; i--) {
			ch = buf[i] - 'a';
			if (cur->next[ch] == nullptr)
				return 0;
			cur = cur->next[ch];
		}
	}
	idx = cur->idx;
	if (m[idx].find(len) != m[idx].end())
		answer = m[idx][len];
	return answer;
}


vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	answer.resize(queries.size());
	int i;
	string buf;
	int type;

	vector<pair<string, int>> v;
	for (int i = 0; i < queries.size(); i++)
		v.push_back(make_pair(queries[i], i));

	init();
	for (int i = 0; i < words.size(); i++) {
		r_insert(words[i]);
	}


	sort(v.begin(), v.end());
	sort(queries.begin(), queries.end());

	for (i = 0; i < queries.size(); i++) {
		if (queries[i][0] != '?')
			break;
		buf = "";
		for (int j = 0; j < queries[i].size(); j++) {
			if (queries[i][j] == '?')
				continue;
			buf += queries[i][j];
		}
		answer[v[i].second] = query(buf, 1, queries[i].size());
	}

	init();
	for (int i = 0; i < words.size(); i++) {
		insert(words[i]);
	}
	for (; i < queries.size(); i++) {
		buf = "";
		for (int j = 0; j < queries[i].size(); j++) {
			if (queries[i][j] == '?')
				continue;
			buf += queries[i][j];
		}

		answer[v[i].second] = query(buf, 0, queries[i].size());
	}


	return answer;
}