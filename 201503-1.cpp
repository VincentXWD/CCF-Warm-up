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
int n, m;
int G[maxn][maxn];

int main() {
    // freopen("in", "r", stdin);
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &G[i][j]);
            }
        }
        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                printf("%d ", G[j][i]);
            }
            printf("\n");
        }
    }
    return 0;
}