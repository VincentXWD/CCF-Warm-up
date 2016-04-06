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

using namespace std;

const int maxn = 11111;
int n, a;
int vis[maxn];

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		vis[a]++;
	}
	int ans, cnt = 0;
	for(int i = 0; i < maxn; i++) {
		if(cnt < vis[i]) {
			ans = i;
			cnt = vis[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
