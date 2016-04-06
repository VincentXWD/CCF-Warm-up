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
int n, a;
typedef struct V {
    int no;
    int cnt;
    V() { no = 0; cnt = 0; }
}V;
V vis[maxn];
set<int> yep;
bool cmp(V a, V b) {
    if(a.cnt == b.cnt) return a.no < b.no;
    return a.cnt > b.cnt;
}

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d", &n)) {
        memset(vis, 0, sizeof(vis));
        yep.clear();
        for(int i = 0; i < n; i++) {
            scanf("%d", &a);
            vis[a].no = a;
            vis[a].cnt++;
            yep.insert(a);
        }
        sort(vis, vis + maxn, cmp);
        for(int i = 0; i < yep.size(); i++) {
            printf("%d %d\n", vis[i].no, vis[i].cnt);
        }
    }
    return 0;
}