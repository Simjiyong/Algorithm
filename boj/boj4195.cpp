#include <stdio.h>

#define MAX_F (100000 * 2)
#define MAX_LEN 20

struct Hash
{
	char key[MAX_LEN + 1];
	int idx;
};

Hash tb[MAX_F];
int T, F;
int parent[MAX_F];
int cnt[MAX_F];
int mStrcmp(const char* str, const char* str2) {
	int i;
	for (i = 0; str[i] != '\0' || str2[i] != '\0'; i++) {
		if (str[i] != str2[i])
			return -1;
	}
	if (str[i] != '\0' || str2[i] != '\0')
		return -1;
	return 0;
}

void mStrcpy(char* dest, const char* src) {
	int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}
unsigned long mHash(const char* str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) - hash) + c) % MAX_F;
	}

	return hash % MAX_F;
}

int find(const char* key) {
	unsigned long h = mHash(key);
	int cnt = MAX_F;

	while (tb[h].key[0] != 0 && cnt--) {
		if (mStrcmp(tb[h].key, key) == 0) {
			return tb[h].idx;
		}
		h = (h + 1) % MAX_F;
	}
	return -1;
}


int add(const char* key, int& idx)
{
	unsigned long h = mHash(key);

	while (tb[h].key[0] != 0)
	{
		if (mStrcmp(tb[h].key, key) == 0) {
			return 0;
		}
		h = (h + 1) % MAX_F;
	}

	mStrcpy(tb[h].key, key);
	tb[h].idx = idx++;
	return 1;
}

void init() {
	for (int i = 0; i < MAX_F; i++) {
		parent[i] = i;
		cnt[i] = 1;
		tb[i].key[0] = 0;
		tb[i].idx = -1;
	}
}

int find_root(int n) {
	if (n == parent[n])
		return n;
	return parent[n] = find_root(parent[n]);
}


int merge(int a, int b) {
	int ra = find_root(a);
	int rb = find_root(b);

	if (ra != rb) {
		parent[rb] = ra;
		cnt[ra] += cnt[rb];
	}

	printf("%d\n", cnt[ra]);
	return 1;
}

int main() {
	scanf(" %d", &T);
	char name[MAX_LEN + 1], name2[MAX_LEN + 1];
	int idx;
	int n1, n2;
	for (int tc = 1; tc <= T; tc++) {
		scanf(" %d", &F);
		init();
		idx = 0;
		for (int i = 0; i < F; i++) {
			scanf(" %s %s\n", name, name2);
			add(name, idx);
			add(name2, idx);
			n1 = find(name);
			n2 = find(name2);
			merge(n1, n2);
		}
	}
	return 0;
}