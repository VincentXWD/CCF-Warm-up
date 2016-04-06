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
int vis[maxn];

int main() {
	// freopen("in", "r", stdin);
	int a;
	while(~scanf("%d", &n)) {
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++) {
			scanf("%d", &a);
			printf("%d ", ++vis[a]);
		}
		printf("\n");
	}
}
