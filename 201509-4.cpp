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
const int maxm = 100010;
typedef struct Edge {
    int u;
    int v;
    int next;
    Edge() { next = -1; }
}Edge;

int head[maxn], ecnt;
Edge edge[maxm];
int n, m;

int bcnt, dindex;
int dfn[maxn], low[maxn];
int stk[maxn], top;
int belong[maxn];
bool instk[maxn];

void init() {
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    memset(instk, 0, sizeof(instk));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    ecnt = top = bcnt = dindex = 0;
}

void adde(int uu, int vv) {
    edge[ecnt].u = uu;
    edge[ecnt].v = vv;
    edge[ecnt].next = head[uu];
    head[uu] = ecnt++;
}

void tarjan(int u) {
    int v = u;
    dfn[u] = low[u] = ++dindex;
    stk[++top] = u;
    instk[u] = 1;
    for(int i = head[u]; ~i; i=edge[i].next) {
        v = edge[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instk[v] && dfn[v] < low[u]) {
            low[u] = dfn[v];
        }
    }
    if(dfn[u] == low[u]) {
        bcnt++;
        do {
            v = stk[top--];
            instk[v] = 0;
            belong[v] = bcnt;
        } while(v != u);
    }
}

int main() {
    // freopen("in", "r", stdin);
    int uu, vv;
    while(~scanf("%d %d", &n, &m)) {
        init();
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &uu, &vv);
            adde(uu, vv);
        }
        for(uu = 1; uu <= n; uu++) {
            if(!dfn[uu]) {
                tarjan(uu);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
        	for(int j = i + 1; j <= n; j++) {
        		if(belong[i] == belong[j]) {
        			ans++;
        		}
        	}
        }
        printf("%d\n", ans);
    }
    return 0;
}
