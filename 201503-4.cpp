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

const int maxn = 10010;
const int p = 10000;
int n, m;
queue<int> q;
vector<int> G[maxn<<1];
bool vis[maxn<<1];
int depth[maxn<<1];

// sw : 1~10000
// pc : 10000~20000

int bfs1() {
	memset(vis, 0, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	int cur = 0;
	depth[1] = cur++;
	while(!q.empty()) q.pop();
	q.push(1); vis[1] = 1;
	while(!q.empty()) {
		bool update = 0;
		int u = q.front(); q.pop();
		for(int v = 0; v < G[u].size(); v++) {
			if(!vis[G[u][v]]) {
				update = 1;
				if(depth[G[u][v]] == 0) {
					depth[G[u][v]] = cur;
				}
				vis[G[u][v]] = 1;
				q.push(G[u][v]);
			}
		}
		if(update) cur++;
	}
	int adep = 0, aim;
	for(int i = 1; i < (maxn<<1); i++) {
		if(adep < depth[i]) {
			adep = depth[i];
			aim = i;
		}
	}
	return aim;
}

int bfs2(int s) {
	memset(vis, 0, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	int cur = 0;
	while(!q.empty()) q.pop();
	depth[s] = cur++;
	q.push(s); vis[s] = 1;
	while(!q.empty()) {
		bool update = 0;
		int u = q.front(); q.pop();
		for(int v = 0; v < G[u].size(); v++) {
			if(!vis[G[u][v]]) {
				update = 1;
				if(depth[G[u][v]] == 0) {
					depth[G[u][v]] = cur;
				}
				vis[G[u][v]] = 1;
				q.push(G[u][v]);
			}
		}
		if(update) cur++;
	}
	int adep = 0;
	for(int i = 1; i < (maxn<<1); i++) {
		if(adep <= depth[i]) {
			adep = depth[i];
		}
	}
	return adep;
}

int main() {
	freopen("in", "r", stdin);
	int pre;
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 0; i < (maxn<<1); i++) {
			G[i].clear();
		}
		for(int i = 2; i <= n; i++) {
			scanf("%d", &pre);
			G[i].push_back(pre);
			G[pre].push_back(i);
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d", &pre);
			G[p+i].push_back(pre);
			G[pre].push_back(p+i);
		}
		cout << bfs2(bfs2(bfs2(bfs1()))) << endl;
	}
	return 0;
}
