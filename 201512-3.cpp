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

typedef struct Point {
	int x, y;
	Point() {}
	Point(int xx, int yy) : x(xx), y(yy) {}
}Point;

const int maxn = 111;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

char G[maxn][maxn];
int n, m, q;
Point a, b;
int cmd;

void init() {
	memset(G, 0, sizeof(G));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			G[i][j] = '.';
		}
	}
}

void line(Point a, Point b) {
	if(a.y == b.y) {
		if(a.x > b.x) {
			Point tmp = a;
			a = b;
			b = tmp;
		}
		for(int i = a.x; i <= b.x; i++) {
			if(G[i][a.y] == '-' || G[i][a.y] == '+') G[i][a.y] = '+';
			else G[i][a.y] = '|';
		}
	}
	else if(a.x == b.x) {	
		if(a.y > b.y) {
			Point tmp = a;
			a = b;
			b = tmp;
		}
		for(int i = a.y; i <= b.y; i++) {
			if(G[a.x][i] == '|' || G[a.x][i] == '+') G[a.x][i] = '+';
			else G[a.x][i] = '-';
		}
	}
}
bool ok(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

void dfs(int x, int y, char s) {
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(ok(xx, yy) && !(G[xx][yy] == '|' || G[xx][yy] == '+' || G[xx][yy] == '-' ) && G[xx][yy] != s) {
			G[xx][yy] = s;
			dfs(xx, yy, s);
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &m, &n)) {
		scanf("%d", &q);
		init();
		while(q--) {
			scanf("%d", &cmd);
			if(cmd == 0) {
				scanf("%d %d %d %d", &a.y, &a.x, &b.y, &b.x);
				line(a, b);
			}
			else {
				char s[3];
				memset(s, 0, sizeof(s));
				scanf("%d %d", &a.y, &a.x);
				scanf("%s", s);
				dfs(a.x, a.y, s[0]);
			}
		}
		for(int i = n - 1; i >= 0; i--) {
			for(int j = 0; j < m; j++) {
				printf("%c", G[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}