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

const int maxn = 33;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
int n, m;
int G[maxn][maxn];
bool dis[maxn][maxn];

bool ok(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		memset(dis, 0, sizeof(dis));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d", &G[i][j]);
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(ok(i-1, j) && ok(i+1, j)) {
					if(G[i-1][j] == G[i+1][j] && G[i-1][j] == G[i][j] && G[i+1][j] == G[i][j]) {
						dis[i-1][j] = dis[i+1][j] = dis[i][j] = 1;
					}
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(ok(i, j-1) && ok(i, j+1)) {
					if(G[i][j-1] == G[i][j+1] && G[i][j-1] == G[i][j] && G[i][j+1] == G[i][j]) {
						dis[i][j-1] = dis[i][j+1] = dis[i][j] = 1;
					}
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(dis[i][j]) G[i][j] = 0;
				printf("%d ", G[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}