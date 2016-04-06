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

const int maxn = 1111;
int n;
int G[maxn][maxn];
bool vis[maxn][maxn];

bool ok(int i, int j) {
	return !vis[i][j] && i >= 0 && j >= 0 && i < n && j < n;
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &G[i][j]);
			}
		}
		int cnt = 0;
		bool r = 0, d = 0, ru = 0, ld = 0;
		int cx = 0, cy = 0;
		while(cnt < n * n) {
			if(r == 0 && d == 0 && ru == 0 && ld == 0) {
				r = 1;
				vis[cx][cy] = 1;
				printf("%d ", G[cx][cy]);
				cnt++;
				continue;
			}
			if(r == 1) {
				r = 0;
				ld = 1;
				if(ok(cx, cy+1)) {
					vis[cx][cy] = 1;
					cy += 1;
					cnt++;
					printf("%d ", G[cx][cy]);
				}
				continue;
			}
			if(d == 1) {
				d = 0;
				ru = 1;
				if(ok(cx+1, cy)) {
					vis[cx][cy] = 1;
					cnt++;
					cx += 1;
					printf("%d ", G[cx][cy]);
				}
				continue;
			}
			if(ru == 1) {
				ru = 0;
				r = 1;
				int tx = cx - 1;
				int ty = cy + 1;
				while(ok(tx, ty)) {
					vis[cx][cy] = 1;
					cnt++;
					cx -= 1;
					cy += 1;
					printf("%d ", G[cx][cy]);
					tx = cx - 1;
					ty = cy + 1;
				}
				continue;
			}
			if(ld == 1) {
				ld = 0;
				d = 1;
				int tx = cx + 1;
				int ty = cy - 1;
				while(ok(tx, ty)) {
					vis[cx][cy] = 1;
					cnt++;
					cx += 1;
					cy -= 1;
					printf("%d ", G[cx][cy]);
					tx = cx + 1;
					ty = cy - 1;
				}
				continue;
			}
		}
		printf("\n");
	}
}
