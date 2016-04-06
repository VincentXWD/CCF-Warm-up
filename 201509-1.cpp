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

int n, a;

int main() {
	// freopen("in", "r", stdin);
	while(~scanf("%d", &n)) {
		scanf("%d", &a);
		int cur = a, cnt = 1;
		for(int i = 1; i < n; i++) {
			scanf("%d", &a);
			if(cur != a) {
				cnt++;
				cur = a;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}