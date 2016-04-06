#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

const int maxn = 10005;
const int maxm = 100005;
vector<int>::iterator it;
vector<int> G[maxn];
bool vis[maxn][maxn];
int dig[maxn];
int n, m, top;
int st[maxm];
int pre[maxn];

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		pre[y] = x;
	}
}
inline void init() {
	for(int i = 0; i < maxn; i++) {
		pre[i] = i;
	}
}

void dfs(int u) {
	for(int i = 0; i < G[u].size(); i++) {
		if(!vis[u][G[u][i]]) {
			vis[u][G[u][i]] = vis[G[u][i]][u] = 1;
			dfs(G[u][i]);
			st[top++] = G[u][i];
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	int a, b;
	while(~scanf("%d %d", &n, &m)) {
		init();
		memset(dig, 0, sizeof(dig));
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n + 5; i++) G[i].clear();
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
			unite(a, b);
			dig[a]++; dig[b]++;
		}
		int odd = 0;
		bool exflag = 0;
		int father = find(1);
		for(int i = 1; i <= n; i++) {
			if(father != find(i)) exflag = 1;
			sort(G[i].begin(), G[i].end());
			if(dig[i] & 1) odd++;
		}
		if(odd == 1 || odd > 2 || exflag) {
			puts("-1");
			continue;
		}
		top = 0;
		dfs(1);
		printf("1");
		while(top--) printf(" %d", st[top]);
		printf("\n");
	}
	return 0;
}
