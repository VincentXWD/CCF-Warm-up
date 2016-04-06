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

typedef struct Node {
	int x1, y1;
	int x2, y2;
	int num;
	Node() {}
	Node(int a, int b, int c, int d, int e) : x1(a), y1(b), x2(c), y2(d), num(e) {}
}Node;
const int maxn = 11;
int n, m, a1, b1, a2, b2;
Node v[maxn];

bool ok(int i, int a, int b) {
	if(v[i].x1 > v[i].x2) swap(v[i].x1, v[i].x2);
	if(v[i].y1 > v[i].y2) swap(v[i].y1, v[i].y2);
	for(int j = v[i].x1; j <= v[i].x2; j++) {
		for(int k = v[i].y1; k <= v[i].y2; k++) {
			if(a == j && b == k) return 1;
		}
	}
	return 0;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
		v[i] = Node(a1, b1, a2, b2, i+1);
	}
	int kase = 1;
	for(int i = 0; i < m; i++) {
		bool flag = 0;
		scanf("%d %d", &a1, &b1);
		for(int j = n - 1; j >= 0; j--) {
			if(ok(j, a1, b1)) {
				printf("%d\n", v[j].num);
				Node tmp = v[j];
				for(int k = n - 1; k >= j; k--) {
					v[k+1] = v[k];
				}
				flag = 1;
				v[n-1] = tmp;
				break;
			}
		}
		if(!flag) printf("IGNORED\n");
	}
	return 0;
}
