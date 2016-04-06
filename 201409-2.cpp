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


const int maxn = 105;
int n;
int xx1, yy1, xx2, yy2;
int vis[maxn][maxn];

int main() {
    // freopen("in", "r", stdin);
    int flag;
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &xx1, &yy1, &xx2, &yy2);
        for(int k = xx1; k < xx2; k++) {
            for(int j = yy1; j < yy2; j++) {
                vis[k][j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            // cout <<vis[i][j] << " ";
            if(vis[i][j]) cnt++;
        }
        // cout << endl;
    }
    printf("%d\n", cnt);
    return 0;
}
