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
int a[maxn], cnt;

int main() {
	freopen("in", "r", stdin);
	scanf("%d", &n);
	cnt = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			cout << i << " " << j << endl;
			if(int(abs(a[i] - a[j])) == 1) {
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
