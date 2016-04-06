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

typedef struct Node {
    int a;
    int b;
    int v;
    friend bool operator < (Node a, Node b) {
        return a.v > b.v;
    }
}Node;

const int maxn = 1111;
int pre[maxn];
int n, m, ans;
priority_queue<Node> pq;

int find(int x) {
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        pre[y] = x;
        return true;
    }
    return false;
}
inline void init() {
    for (int i = 0; i < n + 5; i++) {
        pre[i] = i;
    }
    while (!pq.empty()) pq.pop();
}

int main() {
	Node p;
	int a, b, v;
	// freopen("in", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		init();
		ans = 0;
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &v);
			p.a = a;
			p.b = b;
			p.v = v;
			pq.push(p);
		}
		n--;
		while(n) {
            p = pq.top();
            pq.pop();
            if(unite(p.a, p.b)) {
                n--;
                ans += p.v;
            }
        }
        printf("%d\n", ans);
	}
	return 0;
}
