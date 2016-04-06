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

const int maxn = 111;
int na, nb;
char a[maxn];
char aa[maxn];
char b[maxn];
int pre[maxn];
int m;

void getpre(char *b, int *pre) {
    int j, k;
    pre[0] = -1;
    j = 0;
    k = -1;
    while(j < nb) {
        if(k == -1 || b[j] == b[k]) {
            j++;
            k++;
            pre[j] = k;
            if(b[j] != b[k]) {
                pre[j] = k;
            }
            else {
                pre[j] = pre[k];
            }
        }
        else {
            k = pre[k];
        }
    }
}

int kmp() {
    int ans = 0;
    int i = 0;
    int j = 0;
    while(i < na) {
        if(j == -1 || aa[i] == b[j]) {
            i++;
            j++;
        }
        else {
            j = pre[j];
        }
        if(j == nb) {
            ans++;
        }
    }
    return ans;
}

int main() {
    // freopen("in", "r", stdin);
    int flag;
    while(~scanf("%s", b)) {
        scanf("%d %d", &flag, &m);
        if(flag == 0) {
            nb = strlen(b);
            for(int i = 0; b[i]; i++) {
                if(b[i] <= 'Z' && b[i] >= 'A') {
                    b[i] = b[i] - 'A' + 'a';
                }
            }
            getpre(b, pre);
            while(m--) {
                scanf("%s", a);
                strcpy(aa, a);
                na = strlen(a);
                for(int i = 0; aa[i]; i++) {
                if(aa[i] <= 'Z' && aa[i] >= 'A') {
                    aa[i] = aa[i] - 'A' + 'a';
                }
            }
                if(kmp()) {
                    printf("%s\n", a);
                }
            }
        }
        else {
            nb = strlen(b);
            getpre(b, pre);
            while(m--) {
                scanf("%s", a);
                na = strlen(a);
                strcpy(aa, a);
                if(kmp()) {
                    printf("%s\n", a);
                }
            }
        }
    }
    return 0;
}
